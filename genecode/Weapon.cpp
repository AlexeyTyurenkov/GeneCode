//
//  Weapon.cpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/2/15.
//  Copyright © 2015 com.ovt. All rights reserved.
//

#include "Weapon.hpp"

bool Weapon::canRemove(Weapon* weapon)
{
    return weapon->shouldRemove();
}

bool Weapon::isHitEnemy(double ourSpeed, double enemySpeed)
{
    double probability = enemySpeed == 0 ? 1 : hitChance(ourSpeed/enemySpeed);
    unsigned percent = probability * 100;
    unsigned random = rand() % 100;
    return (percent > random);
}