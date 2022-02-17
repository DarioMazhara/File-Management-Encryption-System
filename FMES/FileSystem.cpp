//
//  FileSystem.cpp
//  FMES
//
//  Created by Dario Mazhara on 2/16/22.
//  Copyright © 2022 Dario Mazhara. All rights reserved.
//

#include "FileSystem.hpp"

void FileSystem::create_file(string name) {
    ofstream file;
    
    file.open(name);
    
    file.close();
}

void FileSystem::open_file(string path) {
    string cmd = "open -a TextEdit ";
    
    cmd += path;
    
    system(cmd.c_str());
}

void FileSystem::remove_file(string path) {
    string cmd = "rm " + path;
    
    system(cmd.c_str());
}

void FileSystem::write_file(string path, string edit) {
    stream.open(path);
    
    stream << edit << endl;
    
    stream.close();
}

void FileSystem::encrypt_file(string file_name, string file_dir, int key) {
    fstream fin, fout;
    
    fin.open(file_dir+"/"+file_name, fstream::in);
    fout.open(file_dir+"/"+file_name+"_encrypted", fstream::out);
    char c;
    
    while (fin >> noskipws >> c) {
        int temp = (c + key);
        
        fout << (char)temp;
    }
    
    fin.close();
    fout.close();
}
