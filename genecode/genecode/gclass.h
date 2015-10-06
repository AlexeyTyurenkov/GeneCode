//
//  gclass.h
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#ifndef __etc__gclass__
#define __etc__gclass__


#include "GLOBAL_CONST.h"



class Gclass
{
    std::vector<shima_t>  internalArray;
    std::string filename;
    Fleet* fleetCreate() const;
    int score = 0;

public:
    //genetic operators
    void mutation();

    Gclass* crossover(Gclass* gene);

    //Save to disk delete from disk
    static Gclass* loadFromFile(std::string dir, std::string filename);
    void deleteGene(std::string dir);
    bool save(std::string dir);
    void saveJSON(std::string dir);
    
    //Fitness operator
    bool betterThan(const Gclass* other) const;
    void compare(Gclass* other);
    void clearScore();
    
    //Create new
    static Gclass* empty();
    
    //Print
    void print();
    
};
#endif /* defined(__etc__gclass__) */
