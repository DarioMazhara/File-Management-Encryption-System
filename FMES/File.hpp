//
//  File.hpp
//  FMES
//
//  Created by Dario Mazhara on 2/15/22.
//  Copyright © 2022 Dario Mazhara. All rights reserved.
//

#ifndef File_hpp
#define File_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class File {
public:
    string file_name;
    bool encrypted;
    
    File(string file_name, string path) {
        this->file_name = path+"/"+file_name;
        encrypted = false;
    }
    
};
#endif /* File_hpp */
