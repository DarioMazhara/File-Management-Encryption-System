//
//  main.cpp
//  FMES
//
//  Created by Dario Mazhara on 2/15/22.
//  Copyright © 2022 Dario Mazhara. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sys/stat.h>



#include <stdlib.h>

#include "SystemMemory.hpp"
#include "Interpreter.cpp"

using namespace std;
void write(Profile profile, string file, string data) {
    
    profile.write(file, data);
}
int main(int argc, const char * argv[]) {
    
  
    
    

    Interpreter* interpreter = new Interpreter();
    
    return 0;
}


