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
#include <functional>

#include "GLOBAL_CONST.h"


class Gun : public Weapon{
    
    unsigned calmdown = 0;
    double calibrationParameter = 0.3;

protected:
    virtual double calibration() {return calibrationParameter;};
public:
    Gun(unsigned value):Weapon(value){};

    
    virtual void fire(std::vector<Shoot> &salvo, Fleet *enemy, double ourspeed);
    virtual unsigned hit(unsigned int damage);
    virtual void print();
    virtual std::string json();

};
#endif /* defined(__genecode__Gun__) */
