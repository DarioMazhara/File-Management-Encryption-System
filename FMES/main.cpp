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

using namespace std;
int main(int argc, const char * argv[]) {
    
    fstream fin, fout;
    
    Profile* p1 = new Profile("Dario");
    
    Profile* p2 = new Profile("Rose");
    
    p1->new_file("Info");
    
    p1->write("Info", "My name is Dario Mazhara. I am 20 years old and living in Walnut Creek, California");
    
    p1->encrypt("Info", 50);
    
    p1->open("Info_encrypted");
    
    p1->decrypt("Info", 40);
    
    p1->open("Info");
   
    
//    p1->open("Info");
    
 //   p1->remove("Info");
   
  //  string path = "/Users/dario/Desktop/Profiles/TestProfile/TestFile";
   // string cmd = "open -a TextEdit  ";
   // system(cmd.c_str());

    
    return 0;
}
