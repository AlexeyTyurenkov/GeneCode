//
//  Ship.cpp
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#include "Ship.h"
#include <cstdlib>

Ship::~Ship()
{
    for (auto unit : units)
    {
        delete unit;
    }
    units.clear();
}


bool Ship::canFire()
{
    bool result = false;
    for(auto unit:units)
    {
        result = unit->canFire();
        if (result) break;
    }
    return result;
}

Shoot Ship::hit(unsigned int value)
{
    Shoot c;
    return c;
}

std::vector<Shoot> Ship::fire(Fleet *enemy)
{
    std::vector<Shoot> salvo;
    if (enemy->visibleCount())
    {
        for (auto unit : units)
        {
            if (unit->canFire())
            {
                salvo.push_back(unit->fire());
                
            }
        }
    }

    return salvo;
}

