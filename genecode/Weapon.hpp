//
//  Weapon.hpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/2/15.
//  Copyright © 2015 com.ovt. All rights reserved.
//

#ifndef Weapon_hpp
#define Weapon_hpp

#include <stdio.h>

#include <vector>
#include "GLOBAL_CONST.h"
#include <functional>

class Fleet;
class Shoot;

class Weapon:public Unit {
    
protected:
    bool isHitEnemy(double ourSpeed, double enemySpeed);
    virtual double calibration() = 0;
    std::function<double(double)> hitChance = [this](double maneur)->double {
        double x2 = maneur*maneur;
        return 0.98*x2/(x2 + calibration()) + 0.02;
    };
public:
    Weapon(unsigned value):Unit(value){};
    virtual void fire(std::vector<Shoot>& salvo, Fleet* enemy, double ourspeed) = 0;

    static bool canRemove(Weapon*);
};

#endif /* Weapon_hpp */
