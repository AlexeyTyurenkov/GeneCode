//
//  Ship.h
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#ifndef __etc__Ship__
#define __etc__Ship__

#include <stdio.h>
#include <vector>

#include "GLOBAL_CONST.h"

class Weapon;

class Ship
{
private:
    std::vector<Unit*> units;
    std::vector<Weapon*> weapons;
    std::vector<Engine*> engines;
    double _speed;
    uint64_t _weight;
public:
    Ship(std::vector<Unit*> unit, std::vector<Weapon*> weapon,std::vector<Engine*> engines):
                units(unit),
                weapons(weapon),
                engines(engines){};
    ~Ship();
    void hit(unsigned value);
    void fire(std::vector<Shoot>&salvo, Fleet *enemy);
    void compress();
    bool canFire();
    static bool shouldRemove(Ship*);
    void print();
    double speed();
    uint64_t weight();
};
#endif /* defined(__etc__Ship__) */
