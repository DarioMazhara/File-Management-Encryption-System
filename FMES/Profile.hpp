//
//  Profile.hpp
//  FMES
//
//  Created by Dario Mazhara on 2/15/22.
//  Copyright © 2022 Dario Mazhara. All rights reserved.
//

#ifndef Profile_hpp
#define Profile_hpp

#include <stdio.h>
#include "FileSystem.hpp"
#include <unordered_map>
#include <map>
#include <string>
#include <list>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>


using namespace std;

class Profile {
private:
    map<string, list<string>> keychain;
    using FileMap = map<string, File*>;
    
    
    
    File* current_file;
public:
    string profile_name;
    const string base_path = "/Users/dario/Desktop/Profiles/";
    FileMap file_access;
    string path;
    Profile(string name) {
        file_access = {};
        current_file = NULL;
        this->profile_name = name;
        this->path = base_path + profile_name;
        
        cout << "profile: " << this->path << endl;
        
        mkdir(this->path.c_str(), S_IRWXU);
    }
    
    //Creates a new file with a name given by parameter
    void new_file(string);
    //Opens the file text document and allows user to enter data; saved upon closing
    void write(string, string);
    //Opens the text document; not saved if any data is modified
    void open(string);
    //Deletes file
    void remove(string);
    //Encrypts the data in specified document with a specified key and saves it
    void encrypt(string, int);
    //Unencrypts the data in specified document using specified key and saves it
    void decrypt(string, int);
    //Unecnrypts data in specified document using specified key and opens the file, but does not
    //save it post decryptions. When the file is closed it automatically is reencrypted.
    //Thus, opens a single instance of the unencrypted file for user with the key to read data
    //without decrypting the file first, then encrypting it again after closing document
    void view_single_instance_unencrypted(string, string);
    
    
    
};

#endif /* Profile_hpp */
