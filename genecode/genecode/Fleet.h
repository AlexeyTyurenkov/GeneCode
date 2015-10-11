//
//  Fleet.h
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#ifndef __etc__Fleet__
#define __etc__Fleet__

#include "GLOBAL_CONST.h"

class Ship;

typedef uint16_t shima_t;

enum BattleResult: uint8_t {
    FAIL = 0,
    MINORDRAW = 1,
    DRAW = 2,
    WIN  = 3
} ;


class Fleet
{
private:
    std::vector<std::shared_ptr<Ship>> ships;
    int quality = 0;
    bool canFire();
    void salvo(std::vector<Shoot>& salvo, Fleet* enemy);
    void compress();
public:
    Fleet(std::vector<shima_t>);
    BattleResult result(Fleet *other);
    ~Fleet();
    
    size_t visibleCount();
    std::shared_ptr<Ship> randomShip();
    
    
    void print();
    std::string json(uint64_t score);
};


#endif /* defined(__etc__Fleet__) */
