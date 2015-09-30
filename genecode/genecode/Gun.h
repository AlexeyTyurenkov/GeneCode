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
#include "Unit.h"
class Gun : public Unit{
    
    
public:
    Gun(unsigned value):Unit(value){};
    virtual bool canFire() const;
};
#endif /* defined(__genecode__Gun__) */
