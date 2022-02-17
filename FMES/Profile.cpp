//
//  Profile.cpp
//  FMES
//
//  Created by Dario Mazhara on 2/15/22.
//  Copyright © 2022 Dario Mazhara. All rights reserved.
//

#include "Profile.hpp"


void Profile::new_file(string name) {
    
    File* file = new File(name, this->path);
    
    file_access[name] = file;
    
    current_file = file;
    
    cout << this->path + "/" + file->file_name << " has been created" << endl;
};

void Profile::write(string file_name, string data) {
    FileSystem::write_file(this->path + "/" + file_name, data);
    cout << "Written into " << file_name << endl << data << endl;
}

void Profile::open(string file_name) {
    FileSystem::open_file(this->path+"/"+file_name);
}

void Profile::remove(string file_name) {
    FileSystem::remove_file(this->path+"/"+file_name);
    cout << file_name << " removed" << endl;
}

void Profile::encrypt(string file_name, int key) {
    
    FileSystem::encrypt_file(file_name, this->path, key);
    
    cout << file_name << " encrypted using key: " << key << endl;
}
