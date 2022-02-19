//
//  FileSystem.hpp
//  FMES
//
//  Created by Dario Mazhara on 2/16/22.
//  Copyright © 2022 Dario Mazhara. All rights reserved.
//

#ifndef FileSystem_hpp
#define FileSystem_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "File.hpp"
using namespace std;

static ofstream stream;

class FileSystem {
public:
    static void create_file(string);
    
    static void open_file(string);
    
    static void remove_file(string);
    
    static void write_file(string, string);
    
    static void encrypt_file(File*, int);
    
    static void decrypt_file(File*, string, int);
};
#endif /* FileSystem_hpp */
