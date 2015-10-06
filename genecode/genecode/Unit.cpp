//
//  Unit.cpp
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#include "Unit.h"
#include <sstream>
#include <iostream>

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

std::string Unit::json()
{
    std::ostringstream result;
    
    return result.str();
}