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
#include "Shoot.hpp"
#include "Fleet.h"

class Ship
{
private:
    std::vector<Unit*> units;
public:
    Ship(std::vector<Unit*> vector):units(vector){};
    ~Ship();
    Shoot hit(unsigned value);
    std::vector<Shoot> fire(Fleet* enemy);
    bool canFire();
};
#endif /* defined(__etc__Ship__) */
