//
//  Ship.cpp
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#include "Ship.h"
#include <cstdlib>
#include <algorithm>

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
    return weapons.size() > 0;
}

void Ship::hit(unsigned int value)
{
    if (units.size())
    {
        auto randIndex = rand()%units.size();
        units[randIndex]->hit(value);
    }
}

void Ship::fire(std::vector<Shoot>&salvo, Fleet *enemy)
{
    for (auto weapon : weapons)
    {
        weapon->fire(salvo, enemy);
    }
}

void Ship::compress()
{
    std::remove_if(units.begin(), units.end(), Unit::shouldRemove);
    units.shrink_to_fit();
}