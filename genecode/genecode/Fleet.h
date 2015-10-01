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
    std::vector<Ship> ships;
public:
    Fleet(uint32_t* array,size_t length);
    bool wins(Fleet* other);
};


#endif /* defined(__etc__Fleet__) */
