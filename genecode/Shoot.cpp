//
//  Shoot.cpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/2/15.
//  Copyright © 2015 com.ovt. All rights reserved.
//

#include "Shoot.hpp"
#include "Ship.h"

bool Shoot::isFired()
{
    return fired;
}

void Shoot::fire()
{
    std::shared_ptr<Ship> target = this->target.lock();
    if (target)
    {
        target->hit(value);
    }

}