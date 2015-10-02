//
//  Fleet.cpp
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#include "Fleet.h"
#include "ShipBuilder.h"
#include "Shoot.h"


typedef enum {
    kStopStart = 0,
    kShield  = 1,
    kEngine  = 2,
    kUnknown = 256
} UnitType;



UnitType unittypefromCode(uint32_t T)
{
    auto control = T >> 24;
    UnitType result = kUnknown;
    switch (control)
    {
        case kStopStart:
        case kShield:
        case kEngine:
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
}





#pragma mark - Destructors
Fleet::~Fleet()
{
    for(auto ship: ships)
    {
        delete ship;
    }
}


#pragma mark - Fitness point
bool Fleet::wins(Fleet *other)
{
    bool result = false;
    
    bool IcanFire = canFire();
    bool TheyCanFire = other->canFire();
    std::vector<Shoot>
    while (IcanFire && TheyCanFire)
    {
        for (auto firer: ships)
        {
            if (canFire())
            {
                
            }
        }
        IcanFire = canFire();
        TheyCanFire = other->canFire();
    }
    
    if (IcanFire && !TheyCanFire)
    {
        result = true;
    }
    else if (TheyCanFire && !IcanFire)
    {
        result = false;
    }
    else if (ships.size() == other->ships.size())
    {
        result = quality > other->quality;
    }
    else
    {
        result = ships.size() > other->ships.size();
    }
    return result;
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