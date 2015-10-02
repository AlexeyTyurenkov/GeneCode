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
#include "Shoot.hpp"

class Weapon {
    
    
public:
    virtual void fire(std::vector<Shoot>& salvo, Fleet* enemy) = 0;
};

#endif /* Weapon_hpp */
