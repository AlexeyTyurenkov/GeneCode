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


class Gun : public Unit, public Weapon{
    
    
public:
    Gun(unsigned value):Unit(value){};
    virtual bool canFire() const;
    
    virtual void fire(std::vector<Shoot>& salvo, Fleet* enemy);
    virtual void hit(unsigned int damage);

};
#endif /* defined(__genecode__Gun__) */
