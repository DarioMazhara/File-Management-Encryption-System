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

#include "SystemMemory.hpp"
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


class Operation {
public:
   //ex: "open" "file"
   //"write" "file" "blah blah blah"
   //"encrypt" "file" 5
   
                                             //optional parameters
   void execute(Profile& profile_ref, string command, string param, string param2=0) {
      Profile* profile = &profile_ref;
      if (command == "open") {
         FileSystem::open_file(param);
         return;
      }
      else if(command == "create") {
         string file_name = param.substr(profile->base_path.length() + profile->profile_name.length()+1);
        
         profile->new_file(file_name);
         
         SystemMemory::record_file(profile, profile->file_access[file_name]);
         cout << "in create: " << profile->file_access[file_name]->file_name << endl;
      }
      else if(command == "write") {
         cout << "Write: " << param << ": " << param2 << endl;
         FileSystem::write_file(param, param2);
         return;
      }
      else if(command == "encrypt") {
         string file_name = param.substr(profile->base_path.length() + profile->profile_name.length()+1);
         
         profile->encrypt(file_name, stoi(param2));
         
         return;
      }
      else if (command == "decrypt") {
         string file_name = param.substr(profile->base_path.length() + profile->profile_name.length() + 1);
         
         profile->decrypt(file_name, stoi(param2));
         return;
      }
      else if (command == "delete") {
         FileSystem::remove_file(param);
         return;
      }
      
      
      
   }

};
class Interpreter {
public:

    string input;
    
    string commands[6] = {"create", "open","write", "encrypt", "decrypt", "delete"};
   
    
   unordered_map<string, Operation*> operations;
   
   Profile* profile;
   
   

    Interpreter() {
       
       string name;
       
       cin >> name;
       
       profile = new Profile(name);
       
       
       SystemMemory::record_profile(profile);
       
       
       
       operations["create"] = operations["open"] = operations["write"] = operations["encrypt"] = operations["decrypt"] = operations["delete"] = new Operation;
       
      /*
       operations["create"] = new Operation;
       operations["open"] = new Operation;
       operations["write"] = new Operation;
       operations["encrypt"] = new Operation;
       operations["decrypt"] = new Operation;
       operations["delete"] = new Operation;
       */
              
     
    //   operations["write"]->execute("Dario", "dario");
       while (input != "exit") {
          
          if (input == "logout") {
             profile = NULL;
             cout << "Enter profile: " << endl;
             cin >> name;
             profile = new Profile(name);
             
          }
          getline(cin, input);
        
          parse(profile, input);
       }
    }
    
    void parse(Profile* profile, string input) {
       
      
       istringstream ss(input);
       
       
       string command[100];
       
       int i = 0;
       
       while (ss >> command[i]) {
          i++;
       }
       
       execute(profile, command);
    }
   
   string concat(string arr[]) {
         
      string result = "";
      
      for (int i = 2; i < sizeof(arr); i++) {
         result += arr[i] + " ";
      }
      

      return result;
   }
   
   void execute(Profile* profile, string command[100]) {

 
      cout << command[2].empty() << endl;
      //command format: [command] [file name] [if applicable second parameter (ex: key, new data to write)]
      
      //saves the second word of the command, which is the file name, and saves it into variable param
      
      string param = profile->path + "/" + command[1];
      
      
      //initalize another param variable to hold the third argument of the command, which is a key or text to write, in case
      //it requires a declaration
      string param2 = "";
      cout << param2.empty() << endl;
      
      string write_args = concat(command);
      //if there is no third word of the parsed command (no key or write), param2 = nullptr, otherwise
      //param2 = the second argument
      command[2].empty() ? param2 = "" : param2 = write_args;
      
      
      //if there is not second argument, run only those command that take in only one parameter
      
      cout << param2 << endl;
      
      if (param2.empty()) {
         
         cout << command[0] << " " << param << " " << param2 << endl;
         operations[command[0]]->execute(*profile, command[0], param, param2);
      }
      //if there is a second argument, then run only those commands that take a second parameter
      else {
         
         operations[command[0]]->execute(*profile, command[0], param, param2);
      }
      
   }
};
