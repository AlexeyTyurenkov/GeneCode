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
#include "GLOBAL_CONST.h"

class Ship
{
private:
    std::vector<Unit*> units;
    std::vector<Weapon*> weapons;
public:
    Ship(std::vector<Unit*> unit, std::vector<Weapon*> weapon):units(unit), weapons(weapon){};
    ~Ship();
    void hit(unsigned value);
    void fire(std::vector<Shoot>&salvo, Fleet *enemy);
    bool canFire();
};
#endif /* defined(__etc__Ship__) */
