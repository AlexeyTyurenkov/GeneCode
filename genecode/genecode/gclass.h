//
//  gclass.h
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#ifndef __etc__gclass__
#define __etc__gclass__

#include <stdio.h>
#include <cstdlib>
#include <string>
#include "Fleet.h"


class Gclass
{
    size_t length;
    uint32_t* internalArray;
    std::string filename;
    Fleet* fleetCreate() const;
    int score = 0;
public:
    void mutation();
    void deleteGene();
    bool save();
    Gclass* crossover(Gclass* gene);
    uint64_t fitness();
    bool betterThan(const Gclass* other) const;
    
    
    void compare(Gclass* other);
    static Gclass* loadFromFile(std::string filename);
    static Gclass* empty();
    
};
#endif /* defined(__etc__gclass__) */
