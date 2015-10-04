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
#include <thread>
#include <future>
#include <ctime>
#include <unistd.h>
#include <sys/stat.h>

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
            if (auto fall = Gclass::loadFromFile(dirname,dp->d_name))
            {
                all.push_back(fall);
            }
        }
    }
    (void)closedir(dirp);
}

void compareGenes(Population& population, Population::iterator begin, Population::iterator end)
{

        auto length = std::distance(begin, end);
        
        if (length < 51)
        {
            for_each(begin, end, [&](Gclass* gene){
                for_each(begin, end, [gene](Gclass* guest){
                    if(gene != guest)
                        gene->compare(guest);
                });
            });
        }
        else
        {
            length /=2;
            auto future = std::async(compareGenes, std::ref(population), begin, begin + length);
            compareGenes(population, begin+length, end);
            future.wait();
        }

};

int main(int argc, const char * argv[])
{
    Population corePopulation;
    srand((unsigned)time(NULL));
    //load all
    loadAll(corePopulation);
    //if empty add first seed
    if (corePopulation.empty())
    {
        corePopulation.push_back(Gclass::empty());
    }
    for (int i = 0; i<200; i++)
    {
        Population population(corePopulation);
        corePopulation.clear();
        for(int i = 0; i < 31; i++)
        {
            compareGenes(population, population.begin(),population.end());
            sort(population.begin(),population.end(),[](Gclass* a, Gclass* b){
                return a->betterThan(b);
            });
        }
        //make love
        for_each(population.begin(),population.size() > MAX_POPULATION ?  population.begin() + MAX_POPULATION : population.end(), [&corePopulation,&population](Gclass* gene){
            auto rand = std::rand() % population.size();
            auto newgene = gene->crossover(population.at(rand));
            corePopulation.push_back(newgene);
            gene->mutation();
            gene->clearScore();
            corePopulation.push_back(gene);
        });
        //kill the others
        for_each(population.begin() + (population.size() > MAX_POPULATION ? MAX_POPULATION : population.size()),population.end(), [](Gclass* gene)
        {
            gene->deleteGene(MAIN_DIR);
            delete gene;
        });
        population.clear();
        cout << "Generation:" << i << endl;
        if(!(i%10))
        {
            std::time_t rawtime;
            std::tm* timeinfo;
            char buffer [80];
            
            std::time(&rawtime);
            timeinfo = std::localtime(&rawtime);
            
            std::strftime(buffer,80,"%Y-%m-%d-%H-%M-%S",timeinfo);
            std::string stringifiedBuffer(buffer);
            std::string tempDir(MAIN_DIR + stringifiedBuffer + "/");
            mkdir(tempDir.c_str(), 0777);
            for_each(corePopulation.begin(), corePopulation.end(), [&tempDir](Gclass* g){g->save(tempDir);});
        }
            
    }
    //Save all
    for_each(corePopulation.begin(), corePopulation.end(), [](Gclass* g){g->save(MAIN_DIR);});
    for_each(corePopulation.begin(), corePopulation.end(), [](Gclass* g){
        g->print();
    });
    return 0;
}
