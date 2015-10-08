//
//  Shoot.cpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/2/15.
//  Copyright © 2015 com.ovt. All rights reserved.
//

#include "Shoot.hpp"
#include "Ship.h"

bool Shoot::canBeRemoved()
{
    return fired || !target.lock();
}

void Shoot::fire()
{
    if (!distance)
    {
        std::shared_ptr<Ship> target = this->target.lock();
        if (target)
        {
            target->hit(value);
            fired = true;
        }
    }
    else
    {
        distance--;
    }

}