//
//  Shield.h
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#ifndef __etc__Shield__
#define __etc__Shield__

#include <stdio.h>
#include "Unit.h"

class Shield: public Unit
{
    
    
public:
    virtual bool canFire() const;
    Shield(unsigned value):Unit(value){};
    virtual unsigned hit(unsigned int damage);
    virtual void print();
};

#endif /* defined(__etc__Shield__) */
