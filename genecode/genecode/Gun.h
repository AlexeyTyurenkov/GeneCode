//
//  Gun.h
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/1/15.
//  Copyright (c) 2015 com.ovt. All rights reserved.
//

#ifndef __genecode__Gun__
#define __genecode__Gun__

#include <stdio.h>

#include "GLOBAL_CONST.h"


class Gun : public Weapon{
    
    unsigned calmdown;
public:
    Gun(unsigned value):Weapon(value){};

    
    virtual void fire(std::vector<Shoot> &salvo, Fleet *enemy, double ourspeed);
    virtual unsigned hit(unsigned int damage);
    virtual void print();


};
#endif /* defined(__genecode__Gun__) */
