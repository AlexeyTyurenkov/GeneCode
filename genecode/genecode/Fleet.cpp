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
            result = kStopStart;
            break;
        case kShield:
            result = kShield;
            break;
        case kEngine:
            result = kEngine;
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
    ShipBuilder builder;
    for (int i=0; i < length; i++)
    {
        auto unitcode = array[i];
        UnitType type = unittypefromCode(unitcode);
        if (type == kUnknown) continue;
        
    }
}


