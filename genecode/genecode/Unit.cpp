//
//  Unit.cpp
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#include "Unit.h"

Unit::~Unit()
{
    
}

 bool Unit::shouldRemove()
{
    return value == 0;
}

int Unit::weight()
{
    return value;
}