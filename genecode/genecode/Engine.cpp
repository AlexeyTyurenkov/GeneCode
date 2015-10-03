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
    if (damage <=  value)
    {
        value-=damage;
    }
    else
    {
        value = 0;
    }
    return rand()%2;
}

void Engine::print()
{
    std::cout << "Engine:" << value << std::endl;
}
