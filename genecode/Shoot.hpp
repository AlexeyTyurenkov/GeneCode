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
#include "Ship.h"
class Shoot
{
    Ship* target;
    unsigned value;
public:
    Shoot(Ship* target, unsigned value):target(target),value(value){};
};

#endif /* Shoot_hpp */
