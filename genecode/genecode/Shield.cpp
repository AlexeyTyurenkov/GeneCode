//
//  Shield.cpp
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#include "Shield.h"


bool Shield::canFire() const
{
    return false;
}

void Shield::hit(unsigned int damage)
{
    if (damage <=  value)
    {
        value-=damage;
    }
    else
    {
        value = 0;
    }
}