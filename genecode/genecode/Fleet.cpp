//
//  Fleet.cpp
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#include "Fleet.h"
#include "ShipBuilder.h"

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


Fleet::Fleet(uint32_t* array, size_t length)
{
    parse(array, length);
    score = 0;
}

uint64_t Fleet::fitness()
{
    return score*10;
}


void Fleet::parse(uint32_t* array, size_t length)
{
    ShipBuilder* builder = new ShipBuilder;
    for (int i=0; i < length; i++)
    {
        auto unitcode = array[i];
        UnitType type = unittypefromCode(unitcode);
        if (type == kUnknown) continue;
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
    ships.push_back(builder->getShip());
    
}


