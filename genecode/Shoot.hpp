//
//  Shoot.hpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/2/15.
//  Copyright © 2015 com.ovt. All rights reserved.
//

#ifndef Shoot_hpp
#define Shoot_hpp

#include "GLOBAL_CONST.h"

class Ship;

class Shoot
{
    std::weak_ptr<Ship> target;
    unsigned value;
    bool fired = false;
    unsigned distance;
public:
    Shoot(std::weak_ptr<Ship> target, unsigned value, unsigned distance):target(target),value(value),distance(distance){ fired = false;};
    bool canBeRemoved();
    void fire();
};

#endif /* Shoot_hpp */
