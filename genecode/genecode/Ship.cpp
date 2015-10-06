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
#include <numeric>
#include <sstream>


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
    _weight = std::accumulate(units.begin(), units.end(), 0, [](uint64_t weight, Unit* unit){return weight + unit->weight();});
    _speed  = (double)std::accumulate(engines.begin(), engines.end(), 0, [](uint64_t power, Engine* engine){return power + engine->power();})/_weight;
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

std::string Ship::json()
{
    std::ostringstream result;
    result << "{";
    result << "\"weight\":" << weight() << ",";
    result << "\"units\":[";
    switch (units.size())
    {
        case 0:
            result << "";
            break;
        case 1:
            result << units[0]->json();
            break;
        default:
            for (auto unit = units.begin(); unit != (units.end() - 1); unit++)
            {
                result << (*unit)->json() << ",";
            }
            result << (*units.rbegin())->json();
    }
    result << "],";
    result << "\"speed\":" << speed() << "";
    result << "}";
    return result.str();
}

uint64_t Ship::weight()
{
    return _weight;
}

double Ship::speed()
{
    return _speed;
}