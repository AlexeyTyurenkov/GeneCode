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
#include <memory>

using namespace std;




typedef vector<Gclass*> Population;

bool isPrefix(string first, string second)
{
    auto res = std::mismatch(first.begin(), first.end(), second.begin());

    if (res.first == first.end())
    {
        return true;
    }
    return false;
}



void loadAll(Population& all)
{
    string dirname = MAIN_DIR;
    DIR* dirp = opendir(dirname.c_str());
    while (auto dp = readdir(dirp))
    {
        if (dp->d_type == DT_REG && !isPrefix(".", dp->d_name))
        {
 //           cout << dp->d_name << endl;
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
    
    for (int i = 0; i<1000000; i++)
    {
        Population population;
        //Init RANDOM
        srand((unsigned)time(NULL));
        //load all
        loadAll(population);
        //if empty add first seed
        if (population.empty())
        {
            population.push_back(Gclass::empty());
        }
        for_each(population.begin(), population.end(), [&population](Gclass* gene){
            for_each(population.begin(), population.end(), [gene](Gclass* guest){
                if(gene != guest)
                    gene->compare(guest);
            });
        });
        
        //sort population
        sort(population.begin(), population.end(),[](Gclass* a, Gclass* b){
            
            return a->betterThan(b);
        });
    //    auto mediana = std::min(population.begin()+1000, population.end());
        for_each(population.begin(),population.size() > MAX_POPULATION ?  population.begin() + MAX_POPULATION : population.end(), [population](Gclass* gene){
            gene->save();
            auto rand = std::rand() % population.size();
            auto newgene = gene->crossover(population.at(rand));
            newgene->save();
        });
        //kill the others
        for_each(population.begin() + (population.size() > MAX_POPULATION ? MAX_POPULATION : population.size()),population.end(), [](Gclass* gene)
        {
            gene->deleteGene();
        });
        //clear memory
        for (auto it:population)
        {
            delete it;
        }
        population.clear();
        cout << "Generation:" << i << endl;
    }
    return 0;
}
