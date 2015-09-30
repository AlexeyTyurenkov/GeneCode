//
//  Fleet.h
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#ifndef __etc__Fleet__
#define __etc__Fleet__

#include <stdio.h>
#include <vector>
#include "Ship.h"


class Fleet
{
private:
    void parse(uint32_t* array, size_t length);
    std::vector<Ship> ships;
    uint64_t score;
public:
    Fleet(uint32_t* array,size_t length);
    uint64_t fitness();
};


#endif /* defined(__etc__Fleet__) */
