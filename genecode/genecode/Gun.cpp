//
//  Gun.cpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/1/15.
//  Copyright (c) 2015 com.ovt. All rights reserved.
//

#include "Gun.h"
#include <iostream>

bool Gun::canFire() const
{
    return true;
}

void Gun::fire(std::vector<Shoot> &salvo, Fleet *enemy, double ourspeed)
{
    //0.98*(x^2)/(x^2+0.3)+0.02
    if (enemy->visibleCount())
    {
        Ship* selectedShip = enemy->randomShip();
        double enemySpeed = selectedShip->speed();
        double probability = enemySpeed == 0 ? 1 : [ourspeed,enemySpeed]() -> double { double x = ourspeed/enemySpeed;
            double x2 = x*x;
            return 0.98*x2/(x2 + 0.3) + 0.02;
        }();
        
        unsigned percent = probability * 100;
        unsigned random = rand() % 100;
        if (percent > random)
        {
            salvo.push_back(Shoot(selectedShip, value));
        }

    }
    
}


unsigned Gun::hit(unsigned int damage)
{
    value = 0;
    return 0;
}

void Gun::print()
{
    std::cout << "Gun:" << value << std::endl;
}