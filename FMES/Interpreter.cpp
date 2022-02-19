//
//  Interpreter.cpp
//  FMES
//
//  Created by Dario Mazhara on 2/18/22.
//  Copyright © 2022 Dario Mazhara. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <string_view>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <memory>
#include "FileSystem.hpp"
#include "Profile.hpp"
#include <string.h>

using namespace std;

/**
 Command syntax:
 
 [command] [filename] [extra arguments]
 ex:
 create HelloWorld
 write HelloWorld Hello everybody!
 open HelloWorld
 
 encrypt HelloWorld 27
 decrypt HelloWorld 27
 
 delete HelloWorld
 
 
 */
template <typename T, typename U> class Operation {

public:
   Profile* profile;
   virtual void execute(const T& t, const U& u= 0)=0;
};



class Open : public Operation<string, string> {
public:
   void execute(string file)  {
      cout << "open" << endl;
      profile->open(file);
   }
};

class Create : public Operation<string, string> {
public:
   void execute(string file) {
      cout << "create" << endl;
   }
};
class Write : public Operation<string, string> {
public:
   void execute(string file, string data) {
      
   }
};
class Crypt : public Operation<string, int> {
   void execute(string file, int key)  {
      
   }
      
};
class Delete : public Operation<string, string> {
   void execute(string file)  {
     
   }
};
class Interpreter {
public:
   Profile* current_user;
    string input;
    
    string commands[6] = {"create", "open","write", "encrypt", "decrypt", "delete"};
   
    unordered_map<string, unique_ptr<Operation<string, string>>> operations;

    Interpreter(Profile* current_user) {
       this->current_user = current_user;
       operations["create"] = unique_ptr<Operation>(new Create);
       operations["open"] = unique_ptr<Operation>(new Open);
       operations["write"] = unique_ptr<Operation>(new Write());
       operations["crypt"] = unique_ptr<Operation>(new Crypt());
       operations["delete"] = unique_ptr<Operation>(new Delete());
        
       getline(cin, input);
        
       parse(input);
    }
    
    void parse(string input) {
       istringstream ss(input);
       
       
       string command[3];
       
       int i = 0;
       
       while (ss >> command[i]) {
          cout << command[i++] << endl;
       }
       
    }
   
   void execute(string command[3]) {
      //command format: [command] [file name] [if applicable second parameter (ex: key, new data to write)]
      
      //saves the second word of the command, which is the file name, and saves it into variable param
      string param = command[1];
      
      //initalize another param variable to hold the third argument of the command, which is a key or text to write, in case
      //it requires a declaration
      string param2;
      
      //if there is no third word of the parsed command (no key or write), param2 = nullptr, otherwise
      //param2 = the second argument
      command[2].empty() ? param2 = nullptr : param2 = command[2];
      
      //if there is not second argument, run only those command that take in only one parameter
      if (param2.empty()) {
         operations[command[0]]->execute();
      }
      //if there is a second argument, then run only those commands that take a second parameter
      else {
         operations[command[0]]->execute();
      }
      
   }
};
