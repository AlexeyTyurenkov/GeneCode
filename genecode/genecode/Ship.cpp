//
//  Ship.cpp
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#include "Ship.h"


Ship::~Ship()
{
    for (auto unit : units)
    {
        delete unit;
    }
    units.clear();
}