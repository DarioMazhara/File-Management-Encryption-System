//
//  SystemMemory.hpp
//  FMES
//
//  Created by Dario Mazhara on 2/23/22.
//  Copyright © 2022 Dario Mazhara. All rights reserved.
//

#ifndef SystemMemory_hpp
#define SystemMemory_hpp

#include <stdio.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <memory>
#include "Profile.hpp"
#include "File.hpp"


using namespace std;

//File System Memory
//Recalls structure and all changes from last session
/*
 # = Directory/folder/profile
 #Profile1
    -Textfile
    -Testfile2_encrypted
    -Testfile3
 */


class SystemMemory {
public:
    
    //Given a profile pointer, return a vector of all files under the profile
    
    static inline map<Profile*, vector<File*>> profile_files;
    
    //Given a profile name, return a pointer to the profile
    static inline  map<string,Profile*> profile_objs; //profile name, profile object
    static inline ofstream stream;
   // static inline ofstream ofstream;
    
  
    
    
    static inline void record_profile(Profile* profile) {
        profile_objs[profile->profile_name] = profile;
        profile_files[profile] = {};
        
        stream.open("/Users/dario/Desktop/Profiles/SystemMemory/Profiles");
        stream.close();
        
        stream.open("/Users/dario/Desktop/Profiles/SystemMemory/Profiles");
        stream << "Name: " << profile->profile_name << "\nPath: " << profile->path << endl;
        stream.close();
        
        
    }
    
    static inline void record_file(Profile* profile, File* file) {
         
          profile_files[profile].push_back(file);
                 
          string file_name(file->file_name);
          string file_path("/Users/dario/Desktop/Profiles/SystemMemory/Profiles");
                     
          fstream append;
                 
          append.open(file_path, std::ios_base::app);
        
        string data = "File: " + file_name;
        
    
                 
          if (append.is_open()) {
              append.write(data.data(), data.size());
              
           }
          
          
      }
    
   
    static void print_profile(string name) {
        cout << profile_objs[name] << endl;
    }
    
    
private:
    struct Constructor {
        Constructor() {
            profile_files = {};
            profile_objs = {};
            mkdir("/Users/dario/Desktop/Profiles/SystemMemory", S_IRWXU);
            
            stream.open("/Users/dario/Desktop/Profiles/SystemMemory/Profiles");
        }
    };
    static inline Constructor constructor;
};


#endif /* SystemMemory_hpp */
