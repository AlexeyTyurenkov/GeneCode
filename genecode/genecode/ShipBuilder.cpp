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
#include "GaussCannon.hpp"

void ShipBuilder::addEngine(unsigned int value)
{
    Engine* engine =new Engine(value);
    units.push_back(engine);
    engines.push_back(engine);
}

void ShipBuilder::addShield(unsigned int value)
{
    units.push_back(new Shield(value));
}


void ShipBuilder::addGun(unsigned int value)
{
    Gun* gun = new Gun(value);
    units.push_back(gun);
    weapon.push_back(gun);
}


void ShipBuilder::addGauss(unsigned int value)
{
    GaussCannon* gun = new GaussCannon(value);
    units.push_back(gun);
    weapon.push_back(gun);
}

Ship* ShipBuilder::getShip()
{
    Ship* ship = new Ship(units,weapon,engines);
    return ship;
}

ShipBuilder::~ShipBuilder()
{
    units.clear();
    weapon.clear();
}

