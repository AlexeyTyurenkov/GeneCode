//
//  Shield.cpp
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#include "Shield.h"
#include <iostream>



unsigned Shield::hit(unsigned int damage)
{
    damage/=2;
    if (!damage)
    {
        damage = 1;
    }
    if (damage <=  value)
    {
        value-=damage;
    }
    else
    {
        value = 0;
    }
    return 0;
}

void Shield::print()
{
    std::cout << "Shield:" << value << std::endl;
}