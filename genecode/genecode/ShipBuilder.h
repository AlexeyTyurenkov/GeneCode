//
//  ShipBuilder.h
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#ifndef __etc__ShipBuilder__
#define __etc__ShipBuilder__


#include <vector>
#include "GLOBAL_CONST.h"

class ShipBuilder
{
    std::vector<Unit*> units;
    std::vector<Weapon*> weapon;
    std::vector<Engine*> engines;
public:
    
    void addShield(unsigned value);
    void addEngine(unsigned value);
    void addGun(unsigned value);
    Ship*  getShip();
    ~ShipBuilder();
};

#endif /* defined(__etc__ShipBuilder__) */
