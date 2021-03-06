//
//  ShipBuilder.cpp
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#include "ShipBuilder.h"
#include "Engine.h"
#include "LaserGun.h"
#include "Shield.h"
#include "GaussCannon.hpp"

void ShipBuilder::addEngine(unsigned int value)
{
    std::shared_ptr<Engine> engine = std::make_shared<Engine>(value);
    units.push_back(engine);
    engines.push_back(engine);
}

void ShipBuilder::addShield(unsigned int value)
{
    units.push_back(std::make_shared<Shield>(value));
}


void ShipBuilder::addGun(unsigned int value)
{
    std::shared_ptr<LaserGun> gun = std::make_shared<LaserGun>(value);
    units.push_back(gun);
    weapon.push_back(gun);
}


void ShipBuilder::addGauss(unsigned int value)
{
    std::shared_ptr<GaussCannon> gun = std::make_shared<GaussCannon>(value);
    units.push_back(gun);
    weapon.push_back(gun);
}

std::shared_ptr<Ship> ShipBuilder::getShip()
{
    return std::make_shared<Ship>(units,weapon,engines);
}

ShipBuilder::~ShipBuilder()
{
    units.clear();
    weapon.clear();
}

