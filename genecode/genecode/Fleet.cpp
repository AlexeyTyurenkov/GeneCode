//
//  Fleet.cpp
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#include "Fleet.h"
#include "ShipBuilder.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

typedef enum {
    kStopStart = 0,
    kShield  = 1,
    kEngine  = 2,
    kGun     = 3,
    kGauss   = 4,
    kUnknown = 256
} UnitType;



UnitType unittypefromCode(shima_t T)
{
    auto control = T >> 12;
    UnitType result = kUnknown;
    switch (control)
    {
        case kStopStart:
        case kShield:
        case kEngine:
        case kGun:
        case kGauss:
            result = static_cast<UnitType>(control);
            break;
        default:
            break;
    }
    return result;
}

#pragma mark - Initialization
Fleet::Fleet(std::vector<shima_t> vector)
{
    quality = 0;
    bool hasRealShips = false;
    ShipBuilder* builder = new ShipBuilder;
    for (auto unitcode : vector)
    {
        UnitType type = unittypefromCode(unitcode);
        if (type == kUnknown)
        {
            quality--;
            continue;
        }
        quality++;
        hasRealShips = true;
        auto value = unitcode & 0xFF;
        switch (type)
        {
            case kShield:
                builder->addShield(value);
                break;
            case kEngine:
                builder->addEngine(value);
                break;
            case kGun:
                builder->addGun(value);
                break;
            case kGauss:
                builder->addGauss(value);
                break;
            case kStopStart:
            {
                ships.push_back(builder->getShip());
                delete builder;
                builder = new ShipBuilder;
                break;
            }
            default:
                continue;
                break;
        }
    }
    if (hasRealShips) ships.push_back(builder->getShip());
    delete builder;
    this->compress();
}





#pragma mark - Destructors
Fleet::~Fleet()
{
    ships.clear();
}


#pragma mark - Fitness point
BattleResult Fleet::result(Fleet *other)
{
    BattleResult result = MINORDRAW;
    
    bool IcanFire = canFire();
    bool TheyCanFire = other->canFire();
    bool fired = IcanFire && TheyCanFire;
    bool battleIsGoing = fired;
    std::vector<Shoot> salvo;
    while (battleIsGoing)
    {
        this->salvo(salvo, other);
        other->salvo(salvo, this);
        for (auto&& shoot: salvo)
        {
            shoot.fire();
        }
        compress();
        other->compress();
        salvo.erase(std::remove_if(salvo.begin(), salvo.end(), [](Shoot shoot){return shoot.canBeRemoved();}), salvo.end());
        
        IcanFire = canFire();
        TheyCanFire = other->canFire();
        battleIsGoing = (IcanFire && TheyCanFire) || (salvo.size() > 0);
    }
    
    if (IcanFire && !TheyCanFire)
    {
        result = WIN;
    }
    else if (TheyCanFire && !IcanFire)
    {
        result = FAIL;
    }
    else if (fired)
    {
        result = DRAW;
    }
    return result;
}


void Fleet::salvo(std::vector<Shoot>& salvo, Fleet* enemy)
{
    for (auto firer: ships)
    {
        if (firer->canFire())
        {
            firer->fire(salvo, enemy);
        }
    }
}

bool Fleet::canFire()
{
    bool result = false;
    for (auto ship: ships)
    {
        result = ship->canFire();
        if (result) break;
    }
    return result;
}

size_t Fleet::visibleCount()
{
    return ships.size();
}

std::shared_ptr<Ship> Fleet::randomShip()
{
    std::shared_ptr<Ship> result = nullptr;
    if (ships.size())
    {
        size_t randomIndex = rand()%ships.size();
        result = ships[randomIndex];
    }
    return result;
}

void Fleet::compress()
{
    ships.erase(std::remove_if(ships.begin(), ships.end(), Ship::shouldRemove),ships.end());
}



void Fleet::print()
{
    if(ships.size())
    {
        std::cout << "======= Fleet =======" << std::endl;
        for(auto sheep: ships)
        {
            sheep->print();
        }
    }
}


std::string Fleet::json(uint64_t score)
{
    std::ostringstream result;
    result << "{\"count\":" << ships.size() << "," <<"\"ships\":[";
    
    switch (ships.size())
    {
        case 0:
            result << "";
            break;
        case 1:
            result << ships[0]->json();
            break;
        default:
            for (auto ship = ships.begin();ship != (ships.end() - 1); ship++)
            {
                result << (*ship)->json() << ",";
            }
            result << (*ships.rbegin())->json();
    }
    result << "],\"effectivness\":" << quality << ",\"score\":"<< score << "}";
    return result.str();
}

