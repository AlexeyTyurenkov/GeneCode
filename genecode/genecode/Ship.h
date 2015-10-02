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
#include "Weapon.hpp"

class Ship
{
private:
    std::vector<Unit*> units;
    std::vector<Weapon*> weapons;
public:
    Ship(std::vector<Unit*> unit, std::vector<Weapon*> weapon):units(unit), weapons(weapon){};
    ~Ship();
    Shoot hit(unsigned value);
    std::vector<Shoot> fire(Fleet* enemy);
    bool canFire();
};
#endif /* defined(__etc__Ship__) */
