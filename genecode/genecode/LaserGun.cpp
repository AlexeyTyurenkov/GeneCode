//
//  Gun.cpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/1/15.
//  Copyright (c) 2015 com.ovt. All rights reserved.
//

#include "LaserGun.h"
#include <iostream>
#include <cmath>





void LaserGun::fire(std::vector<Shoot> &salvo, Fleet *enemy, double ourspeed)
{
    if (calmdown)
    {
        calmdown--;
    }
    else
    {
        //0.98*(x^2)/(x^2+0.3)+0.02
        if (enemy->visibleCount())
        {
            std::shared_ptr<Ship> selectedShip = enemy->randomShip();
            if(isHitEnemy(ourspeed, selectedShip->speed()))
            {
                salvo.push_back(Shoot(selectedShip, value, 0));
            }
            calmdown = log(value);
        }
    }
}




unsigned LaserGun::hit(unsigned int damage)
{
    value = 0;
    return 0;
}



void LaserGun::print()
{
    std::cout << "Gun:" << value << std::endl;
}

std::string LaserGun::json()
{
    std::ostringstream result;
    result << "{ \"type\":\"Gun\", \"value\":" << value << "}";
    return result.str();
}