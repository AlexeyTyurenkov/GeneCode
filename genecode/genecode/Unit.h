//
//  Unit.h
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#ifndef __etc__Unit__
#define __etc__Unit__

#include <stdio.h>

class Unit
{
    
protected:
    int value;
public:
    virtual bool canFire() const = 0;
    Unit(unsigned value):value(value){};
    virtual ~Unit();
    virtual void hit(unsigned damage) = 0;
    static bool shouldRemove(Unit* theElement);
};

#endif /* defined(__etc__Unit__) */
