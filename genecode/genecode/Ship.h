//
//  Ship.h
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#ifndef __etc__Ship__
#define __etc__Ship__

#include <stdio.h>
#include <vector>
#include "Unit.h"
class Ship
{
private:
    std::vector<Unit*> units;
public:
    Ship(std::vector<Unit*> vector):units(vector){};
    ~Ship();
};
#endif /* defined(__etc__Ship__) */
