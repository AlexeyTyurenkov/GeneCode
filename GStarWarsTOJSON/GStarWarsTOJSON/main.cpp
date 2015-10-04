//
//  main.cpp
//  GStarWarsTOJSON
//
//  Created by Aleksey Tyurenkov on 10/4/15.
//  Copyright © 2015 com.ovt. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <dirent.h>

using namespace std;

typedef uint32_t shima_t;

size_t loadFromFile(std::string dir, std::string filename, shima_t*& buffer)
{
    size_t bufferlength = 0;
    //open file
    ifstream infile(dir+filename, ios_base::binary|ios_base::in|ios::ate);
    //if file opened
    if (infile.is_open())
    {
        //get file size
        size_t buffersize =infile.tellg();
        //create buffer
        char* bufferArray = new char[buffersize];
        //return to file start
        infile.seekg(ios::beg);
        //read all from file
        infile.read(bufferArray, buffersize);
        //close file
        infile.close();
        bufferlength = buffersize/sizeof(shima_t);
        buffer = reinterpret_cast<shima_t*>(bufferArray);
    }
    return bufferlength;
}

#define MAIN_TEMP_DIR "/Users/alterego4/GeneCode/temp/"
#define MAIN_JSON_DIR "/Users/alterego4/GeneCode/JSON/"

int main(int argc, const char * argv[])
{
    string dirname = MAIN_TEMP_DIR;
    DIR* dirp = opendir(dirname.c_str());
    while (auto dp = readdir(dirp))
    {
        if (dp->d_type == DT_REG && !isPrefix(".", dp->d_name))
        {
            //           cout << dp->d_name << endl;
            if (auto fall = Gclass::loadFromFile(dirname,dp->d_name))
            {
                all.push_back(fall);
            }
        }
    }
    (void)closedir(dirp);
}
