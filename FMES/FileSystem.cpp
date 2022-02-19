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
    
    cout << path << endl;
    
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

void FileSystem::encrypt_file(File* file, int key) {
    fstream fin, fout;
    
    cout << "filesystem: " << file->file_name << endl;
    
    fin.open(file->file_name, fstream::in);
    fout.open(file->file_name+"_encrypted", fstream::out);
    char c;
    
    while (fin >> noskipws >> c) {
        int temp = (c + key);
        
        fout << (char)temp;
    }
    string temp = file->file_name;
    FileSystem::remove_file(file->file_name);
    file->file_name = temp+"_encrypted";
    
    cout << "fs 2: " << file->file_name << endl;
    fin.close();
    fout.close();
}

void FileSystem::decrypt_file(File* file, string file_dir, int key) {
    fstream in, out;
    ofstream output;
    
    cout << "STARdddddddddddT: " << file->file_name << endl;
    in.open(file->file_name, fstream::in);
    out.open(file_dir+"/temp", fstream::out);
    
    char c;
    
    while (in >> noskipws >> c) {
        int temp = (c - key);
        
        out << (char)temp;
    }
    
    string to_modify_name = file->file_name;
    
    FileSystem::remove_file(file->file_name);
    
    unsigned long encryp_suffix_location = to_modify_name.find("_encrypted");
    
    string decrypted_name = to_modify_name.erase(encryp_suffix_location, 10);
    
   // output.open(file_dir+"/"+decrypted_name);
    string oldname = file_dir+"/temp";
    unsigned long n_old = oldname.length();
    string newname = decrypted_name;
    unsigned long n_new = newname.length();
    
    char old[n_old+1];
    char newer[n_new+1];
    
    strcpy(old, oldname.c_str());
    strcpy(newer, newname.c_str());
    
    rename(old, newer);
    
    
    file->file_name = decrypted_name;
    
    
   /* unsigned long encryp_suffix = file->file_name.find("_encrypted");
    
    
    string temp = (file->file_name);
    
    cout << "!!!!! " << file->file_name << endl;
    FileSystem::remove_file(file_dir+"/"+file->file_name);
    cout << "!!!!! " << file->file_name << endl;
    
    file->file_name = temp.erase(encryp_suffix, 10);
    in.close();
    out.close();*/
}
