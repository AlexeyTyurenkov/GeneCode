//
//  Engine.h
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/1/15.
//  Copyright (c) 2015 com.ovt. All rights reserved.
//

#ifndef __genecode__Engine__
#define __genecode__Engine__

#include <stdio.h>
#include "GLOBAL_CONST.h"

class Engine : public Unit
{
    
    
public:
    Engine(unsigned value):Unit(value){};
    virtual bool canFire() const;
    virtual unsigned hit(unsigned int damage);
    virtual void print();
    uint32_t power();
    virtual std::string json();
};
#endif /* defined(__genecode__Engine__) */
