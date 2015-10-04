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


class Fleet;
class Shoot;

class Weapon:public Unit {
    
public:
    Weapon(unsigned value):Unit(value){};
    virtual void fire(std::vector<Shoot>& salvo, Fleet* enemy, double ourspeed) = 0;
    static bool canRemove(Weapon*);
};

#endif /* Weapon_hpp */
