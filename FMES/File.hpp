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
#include "FileSystem.hpp"

using namespace std;
class File {
public:
    string file_name;
    fstream file_stream;
    
    File(string file_name, string path) {
        this->file_name = file_name;
        
        FileSystem::create_file(path+"/"+file_name);
    }
    
};
#endif /* File_hpp */
