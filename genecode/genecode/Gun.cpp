//
//  Gun.cpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/1/15.
//  Copyright (c) 2015 com.ovt. All rights reserved.
//

#include "Gun.h"
#include <iostream>

bool Gun::canFire() const
{
    return true;
}

void Gun::fire(std::vector<Shoot> &salvo, Fleet *enemy)
{
    if (enemy->visibleCount())
    {
        salvo.push_back(Shoot(enemy->randomShip(), value));
    }
    
}


unsigned Gun::hit(unsigned int damage)
{
    value = 0;
    return 0;
}

void Gun::print()
{
    std::cout << "Gun:" << value << std::endl;
}