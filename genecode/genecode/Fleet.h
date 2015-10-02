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
#include "GLOBAL_CONST.h"

class Fleet
{
private:
    std::vector<Ship*> ships;
    int quality = 0;
    bool canFire();
public:
    Fleet(std::vector<shima_t>);
    bool wins(Fleet* other);
    ~Fleet();
    
    size_t visibleCount();
};


#endif /* defined(__etc__Fleet__) */
