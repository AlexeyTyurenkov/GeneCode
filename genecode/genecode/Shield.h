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
#include "GLOBAL_CONST.h"

class Shield: public Unit
{
    
    
public:

    Shield(unsigned value):Unit(value){};
    virtual unsigned hit(unsigned int damage);
    virtual void print();
    virtual std::string json()
    {
        std::ostringstream result;
        result << "{ \"type\":\"Shield\", \"value\":" << value << "}";
        return result.str();
    }
};

#endif /* defined(__etc__Shield__) */
