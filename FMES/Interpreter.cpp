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
#include <any>
#include <functional>



using namespace std::literals;

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

template <class T> class Operation {
public:
   virtual void execute(string, string = 0, int = 0) {
      
   }
   virtual void test() {
      
   }
};

class Create : public Operation<Create> {
public:
   virtual void execute(string file_name) const{
      cout << "SUCCESS CREATE\n";
   }
   virtual void test() override {
      cout << "test in CREATE\n";
   }
};

class Open : public Operation<Open> {
public:
   void execute(string file_name) {
      cout << "open\n";
   }
};

class Write : public Operation<Write> {
   void execute(string file_name, string data) {
      cout << "write\n";
   }
};

class Crypt : public Operation<Crypt> {
   void execute(string file_name, int key) {
      cout << "crypt\n";
   }
};

class Delete : public Operation<Delete> {
   void execute(string file_name) {
      cout << "delete\n";
   }
};

class Interpreter {
public:
   
  
   Profile* current_user;
    string input;
    
    string commands[6] = {"create", "open","write", "encrypt", "decrypt", "delete"};
   
    
    template <typename T> unordered_map<string, Operation<T>*> operations;
   

    Interpreter(Profile* current_user) {
       this->current_user = current_user;
      
       operations["create"] = new Create;
       operations["open"] = new Open;
       operations["write"] = new Write;
       operations["encrypt"] = new Crypt;
       operations["decrypt"] = new Crypt;
       operations["delete"] = new Delete;
       
       Operation* op = new Create;
       
       op->execute("dario");
     
       cout << "oeprations TEST: \n";
    //   operations["write"]->execute("Dario", "dario");
       
       getline(cin, input);
        
       parse(input);
    }
    
    void parse(string input) {
       cout << "PARSE" << endl;
       istringstream ss(input);
       
       
       string command[3];
       
       int i = 0;
       
       while (ss >> command[i]) {
          cout << command[i++] << endl;
       }
       
       execute(command);
    }
   
   void execute(string command[3]) {
      cout << "EXECUTE" << endl;
      //command format: [command] [file name] [if applicable second parameter (ex: key, new data to write)]
      
      //saves the second word of the command, which is the file name, and saves it into variable param
      string param = command[1];
      
      //initalize another param variable to hold the third argument of the command, which is a key or text to write, in case
      //it requires a declaration
      string param2;
      
      //if there is no third word of the parsed command (no key or write), param2 = nullptr, otherwise
      //param2 = the second argument
      command[2].empty() ? param2 = nullptr : param2 = command[2];
      cout << "EXECUTE 2" << endl;

      //if there is not second argument, run only those command that take in only one parameter
      
      cout << param2 << endl;
      
      if (param2.empty()) {
         cout << "if statement\n";
         operations[command[0]]->execute(param);
      }
      //if there is a second argument, then run only those commands that take a second parameter
      else {
         cout << "else statement\n";
         operations[command[0]]->execute(param, param2);
      }
      
   }
};
