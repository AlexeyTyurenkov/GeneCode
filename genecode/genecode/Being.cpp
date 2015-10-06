//
//  Being.cpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/6/15.
//  Copyright © 2015 com.ovt. All rights reserved.
//

#include "Being.hpp"

using namespace std;

Being::Being(const std::string& dir, const std::string& filename)
{
    //open file
    ifstream infile(dir+filename, ios_base::binary|ios_base::in|ios::ate);
    //if file opened
    if (infile.is_open())
    {
        infile.close();
        gene.reset(Gclass::loadFromFile(dir, filename));
    }
    else
    {
        gene.reset(Gclass::empty());
    }
}

bool Being::operator>(const Being& other)
{
    return this->gene->betterThan(other.gene.get());
};

bool Being::operator++()
{
    gene->mutation();
    return true;
}

Being Being::operator+(const Being &other)
{
    Being being(*this);
    being.gene->crossover(other.gene.get());
    return being;
}