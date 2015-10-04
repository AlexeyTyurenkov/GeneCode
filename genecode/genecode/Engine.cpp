//
//  Engine.cpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/1/15.
//  Copyright (c) 2015 com.ovt. All rights reserved.
//

#include "Engine.h"


bool Engine::canFire() const
{
    return false;
}

unsigned Engine::hit(unsigned int damage)
{
    unsigned newDamage = 0;
    if (damage <=  value)
    {
        value-=damage;
    }
    else
    {
        newDamage = value / 2;
        value = 0;
    }
    return newDamage?rand()%newDamage:0;
}

void Engine::print()
{
    std::cout << "Engine:" << value << std::endl;
}

uint32_t Engine::power()
{
    return 2*value;
}