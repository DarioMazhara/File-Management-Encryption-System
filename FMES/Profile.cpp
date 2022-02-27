//
//  Profile.cpp
//  FMES
//
//  Created by Dario Mazhara on 2/15/22.
//  Copyright © 2022 Dario Mazhara. All rights reserved.
//

#include "Profile.hpp"


File& Profile::new_file(string name) {
    
    cout << "Name: " << name << endl;
    cout << "Path: " << this->path << endl;
    File* file = new File(name, this->path);
    
    
    file_access[name] = file;
    
   // current_file = file;
    
    FileSystem::create_file(file->file_name);
 //   cout << this->path + "/" + file->file_name << " has been created" << endl;
    return *file;
};

void Profile::write(string file_name, string data) {
    FileSystem::write_file(this->path + "/" + file_name, data);
    
    cout << "Written into " << file_name << endl << data << endl;
}

void Profile::open(string file_name) {
    
   // cout << "open: " << file_access[file_name]->file_name << endl;
    
    
    cout << file_access[file_name]->file_name << endl;
    
    
    FileSystem::open_file(file_access[file_name]->file_name);
    
}

void Profile::remove(string file_name) {
    FileSystem::remove_file(this->path+"/"+file_name);
    cout << file_name << " removed" << endl;
}

void Profile::encrypt(string file_name, int key) {
    
    File* to_encrypt = (file_access[file_name]);
    
    FileSystem::encrypt_file((*to_encrypt), key);
 //   cout << file_name << " encrypted using key: " << key << endl;
}

void Profile::decrypt(string file_name, int key) {
    
    File* to_decrypt = file_access[file_name];
    
 //   cout << "sdfgsd " << file_access["Draco"]->file_name << endl;
  //  cout << "hello there: " << to_decrypt->file_name << endl;
    FileSystem::decrypt_file(*to_decrypt, this->path, key);
    
   // cout << file_name << " decrypted using key: " << key << endl;
    //cout << file_access[file_name]->file_name << endl;
    
//    file_access[file_name]->file_name = "Info";
}

void Profile::view_single_instance_unencrypted(string file_name, int key) {
    
}
