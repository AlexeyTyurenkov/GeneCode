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
#include "Ship.h"
#include "Unit.h"

class ShipBuilder
{
    std::vector<Unit*> units;
    
public:
    void addShield(unsigned value);
    void addEngine(unsigned value);
    void addGun(unsigned value);
};

#endif /* defined(__etc__ShipBuilder__) */
