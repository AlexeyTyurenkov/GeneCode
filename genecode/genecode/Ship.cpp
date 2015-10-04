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
#include <iostream>

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
        while(auto damage = units[randIndex]->hit(value)) hit(damage);
    }
}

void Ship::fire(std::vector<Shoot>&salvo, Fleet *enemy)
{
    double ourspeed = speed();
    for (auto weapon : weapons)
    {
        weapon->fire(salvo, enemy, ourspeed);
    }
}

void Ship::compress()
{
    weapons.erase(std::remove_if(weapons.begin(), weapons.end(), [](Weapon* weapon){ return weapon->shouldRemove();}),weapons.end());
    engines.erase(std::remove_if(engines.begin(), engines.end(), [](Engine* engine){ return engine->shouldRemove();}),engines.end());

    units.erase(std::remove_if(units.begin(), units.end(), [](Unit* unit){
        bool result = unit->shouldRemove();
        if (result) delete unit;
        return result;
    }),units.end());
}

bool Ship::shouldRemove(Ship * it)
{
    it->compress();
    bool result = it->units.size() == 0;
    if (result)
    {
        delete it;
    }
    return result;
}


void Ship::print()
{
    std::cout << "=== Ship => Weight: " << weight() << std::endl;
    for (auto unit : units)
    {
        unit->print();
    }
}

uint64_t Ship::weight()
{
    uint64_t summ = 0;
    std::for_each(units.begin(),units.end(),[&summ](Unit* unit){
        
        summ += unit->weight();
        
    });
    return summ;
}




double Ship::speed()
{
    double result = 0.0;
    std::for_each(engines.begin(),engines.end(),[&result](Engine* unit){
        
        result += unit->power();
        
    });
    result/=weight();
    return result;
}