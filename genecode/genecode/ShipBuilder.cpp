//
//  ShipBuilder.cpp
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#include "ShipBuilder.h"
#include "Engine.h"
#include "Gun.h"
#include "Shield.h"

void ShipBuilder::addEngine(unsigned int value)
{
    units.push_back(new Engine(value));
}

void ShipBuilder::addShield(unsigned int value)
{
    units.push_back(new Shield(value));
}


void ShipBuilder::addGun(unsigned int value)
{
    units.push_back(new Gun(value));
}