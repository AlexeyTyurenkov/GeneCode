//
//  Being.hpp
//  genecode
//
//  Created by Aleksey Tyurenkov on 10/6/15.
//  Copyright © 2015 com.ovt. All rights reserved.
//

#ifndef Being_hpp
#define Being_hpp

#include "GLOBAL_CONST.h"
#include "gclass.h"

class Being
{
    
private:
    std::shared_ptr<Gclass> gene;

public:
    Being(const std::string& dir, const std::string& fileName);
    
    
    bool operator>(const Being& other);
    bool operator++();
    Being operator+(const Being& other);
};

#endif /* Being_hpp */
