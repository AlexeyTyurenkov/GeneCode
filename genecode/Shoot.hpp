//
//  Shoot.hpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/2/15.
//  Copyright © 2015 com.ovt. All rights reserved.
//

#ifndef Shoot_hpp
#define Shoot_hpp

#include <stdio.h>
#include "GLOBAL_CONST.h"

class Ship;

class Shoot
{
    Ship* target;
    unsigned value;
    bool fired = false;
public:
    Shoot(Ship* target, unsigned value):target(target),value(value){ fired = false;};
    bool isFired();
    void fire();
};

#endif /* Shoot_hpp */
