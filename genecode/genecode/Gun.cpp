//
//  Gun.cpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/1/15.
//  Copyright (c) 2015 com.ovt. All rights reserved.
//

#include "Gun.h"
#include <iostream>






void Gun::fire(std::vector<Shoot> &salvo, Fleet *enemy, double ourspeed)
{
    //0.98*(x^2)/(x^2+0.3)+0.02
    if (enemy->visibleCount())
    {
        Ship* selectedShip = enemy->randomShip();
        if(isHitEnemy(ourspeed, selectedShip->speed()))
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