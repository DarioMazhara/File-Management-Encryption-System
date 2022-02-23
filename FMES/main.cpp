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

#include "Profile.hpp"

#include <stdlib.h>
#include "Interpreter.cpp"

using namespace std;
void write(Profile profile, string file, string data) {
    
    profile.write(file, data);
}
int main(int argc, const char * argv[]) {
    
    
    Profile* rose = new Profile("Rose");
    
   
 //   rose->write("Testfile", "blah blah blah negro");
    Interpreter* interpreter = new Interpreter(*rose);
    
    return 0;
}


