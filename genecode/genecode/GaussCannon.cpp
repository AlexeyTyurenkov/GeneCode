//
//  GaussCannon.cpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/4/15.
//  Copyright © 2015 com.ovt. All rights reserved.
//

#include "GaussCannon.hpp"
void GaussCannon::fire(std::vector<Shoot> &salvo, Fleet *enemy, double ourspeed)
{
    //0.98*(x^2)/(x^2+0.3)+0.02
    if (enemy->visibleCount())
    {
        for (int i = value; i > 0; i--)
        {
            Ship* selectedShip = enemy->randomShip();
            double enemySpeed = selectedShip->speed();
            double probability = enemySpeed == 0 ? 1 : [ourspeed,enemySpeed]() -> double { double x = ourspeed/enemySpeed;
                double x2 = x*x;
                return 0.98*x2/(x2 + 16) + 0.02;
            }();
            
            unsigned percent = probability * 100;
            unsigned random = rand() % 100;
            if (percent > random)
            {
                salvo.push_back(Shoot(selectedShip, 1));
            }
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