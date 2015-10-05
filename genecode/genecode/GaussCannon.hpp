//
//  GaussCannon.hpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/4/15.
//  Copyright © 2015 com.ovt. All rights reserved.
//

#ifndef GaussCannon_hpp
#define GaussCannon_hpp

#include <stdio.h>
#include "GLOBAL_CONST.h"

class GaussCannon: public Weapon {
    double calibrationParameter = 16;
    unsigned reloadTurns = 0;
    
protected:
    virtual double calibration() {return calibrationParameter;};
public:
    GaussCannon(unsigned value):Weapon(value){};
    
    
    virtual void fire(std::vector<Shoot> &salvo, Fleet *enemy, double ourspeed);
    virtual unsigned hit(unsigned int damage);
    virtual void print();
    
    
};

#endif /* GaussCannon_hpp */
