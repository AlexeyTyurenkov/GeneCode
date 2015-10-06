//
//  Ship.h
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#ifndef __etc__Ship__
#define __etc__Ship__



#include "GLOBAL_CONST.h"

class Weapon;
class Engine;
class Unit;

class Ship
{
private:
    std::vector<std::shared_ptr<Unit>> units;
    std::vector<std::weak_ptr<Weapon>> weapons;
    std::vector<std::weak_ptr<Engine>> engines;
    double _speed;
    uint64_t _weight;
public:
    Ship(std::vector<std::shared_ptr<Unit>> unit, std::vector<std::weak_ptr<Weapon>> weapon,std::vector<std::weak_ptr<Engine>> engines):
                units(unit),
                weapons(weapon),
                engines(engines){};
    ~Ship();
    void hit(unsigned value);
    void fire(std::vector<Shoot>&salvo, Fleet *enemy);
    bool canFire();
    
    
    void compress();
    
    static bool shouldRemove(std::shared_ptr<Ship> it);
    
    double speed();
    uint64_t weight();
    
    void print();
    std::string json();
    
};
#endif /* defined(__etc__Ship__) */
