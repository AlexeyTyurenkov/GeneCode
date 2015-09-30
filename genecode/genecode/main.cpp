//
//  main.cpp
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "gclass.h"
#include <dirent.h>
#include <vector>
#include <algorithm>    // std::for_each
#include "GLOBAL_CONST.h"

using namespace std;




bool isPrefix(string first, string second)
{
    auto res = std::mismatch(first.begin(), first.end(), second.begin());

    if (res.first == first.end())
    {
        return true;
    }
    return false;
}


void loadAll(std::vector<Gclass*>& all)
{
    string dirname = MAIN_DIR;
    DIR* dirp = opendir(dirname.c_str());
    while (auto dp = readdir(dirp))
    {
        if (dp->d_type == DT_REG && !isPrefix(".", dp->d_name))
        {
            cout << dp->d_name << endl;
            if (auto fall = Gclass::loadFromFile(dirname + dp->d_name))
            {
                all.push_back(fall);
            }
        }
    }
    (void)closedir(dirp);
}


int main(int argc, const char * argv[])
{
    std::vector<Gclass*> allget;
    
    //Init RANDOM
    srand((unsigned)time(NULL));
    //load all
    loadAll(allget);
    //if empty add first seed
    if (allget.empty())
    {
        auto firstSeed = Gclass::empty();
        allget.push_back(firstSeed);
    }
    for_each(allget.begin(), allget.end(), [](Gclass* gene){gene->save();});
    return 0;
}
