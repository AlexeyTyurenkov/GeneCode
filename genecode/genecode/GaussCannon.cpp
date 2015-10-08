//
//  GaussCannon.cpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/4/15.
//  Copyright © 2015 com.ovt. All rights reserved.
//

#include "GaussCannon.hpp"
#include <cmath>

void GaussCannon::fire(std::vector<Shoot> &salvo, Fleet *enemy, double ourspeed)
{
    if (reloadTurns)
    {
        reloadTurns--;
    }
    else
    {
        //0.98*(x^2)/(x^2+16)+0.02
        if (enemy->visibleCount())
        {
            for (int i = value; i > 0; i--)
            {
                std::shared_ptr<Ship> selectedShip = enemy->randomShip();
                if(isHitEnemy(ourspeed, selectedShip->speed()))
                {
                    salvo.push_back(Shoot(selectedShip, 1,7));
                }
            }
            //When we fired to object
            reloadTurns = sqrt(value);
        }
    }
}


unsigned GaussCannon::hit(unsigned int damage)
{
    value = 0;
    return 0;
}

void GaussCannon::print()
{
    std::cout << "GaussCannon:" << value << std::endl;
}

std::string GaussCannon::json()
{
    std::ostringstream result;
    result << "{ \"type\":\"GaussCannon\", \"value\":" << value << "}";
    return result.str();
}