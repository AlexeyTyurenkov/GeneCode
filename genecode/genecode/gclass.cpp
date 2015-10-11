//
//  gclass.cpp
//  etc
//
//  Created by Oleksii Tiurenkov on 9/30/15.
//  Copyright (c) 2015 Oleksii Tiurenkov. All rights reserved.
//

#include "gclass.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include "GLOBAL_CONST.h"

using namespace std;

std::string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}



Gclass* Gclass::loadFromFile(std::string dir, std::string filename)
{
    Gclass* result = nullptr;
    //open file
    ifstream infile(dir+filename, ios_base::binary|ios_base::in|ios::ate);
    //if file opened
    if (infile.is_open())
    {
        //get file size
        size_t buffersize =infile.tellg();
        //create buffer
        char* bufferArray = new char[buffersize];
        //return to file start
        infile.seekg(ios::beg);
        //read all from file
        infile.read(bufferArray, buffersize);
        //close file
        infile.close();
        result = new Gclass;
        size_t bufferlength = buffersize/sizeof(shima_t);
        shima_t* shimaBuffer = reinterpret_cast<shima_t*>(bufferArray);
        result->internalArray.assign(shimaBuffer, shimaBuffer + bufferlength);
        //save file name
        result->filename = filename;
        delete [] bufferArray;
    }
    return result;
}

bool Gclass::save(std::string dir)
{
    bool result = false;
    ofstream outfile(dir + filename, ios_base::binary|ios_base::out|ios::trunc);
    if (outfile.is_open())
    {
        shima_t* shimaBuffer = new shima_t[internalArray.size()];
        std::copy(internalArray.begin(),internalArray.end(),shimaBuffer);
        outfile.write(reinterpret_cast<char*>(shimaBuffer), internalArray.size() * sizeof(shima_t));
        outfile.close();
        result = true;
    }
    else
    {
        cerr << "Error:" << strerror(errno) << endl;
        cout << "Error opening file";
    }
    return result;
}

void Gclass::saveJSON(std::string dir)
{
    ostringstream realfileName;
    realfileName << dir << score << "-" << filename << ".json";
    ofstream outfile(realfileName.str(), ios_base::out|ios::trunc);
    if (outfile.is_open())
    {
        Fleet* fleet = fleetCreate();
        outfile << fleet->json(score);
        delete fleet;
        outfile.close();

    }
    else
    {
        cerr << "Error:" << strerror(errno) << endl;
        cout << "Error opening file";
    }

}

void Gclass::mutation()
{
    for (int i = 0; i < internalArray.size(); i++)
    {
        if (RADIATION > (rand()%MAX_SCALE))
        {
            internalArray[i]^= 1 << rand()%(sizeof(shima_t)*8);
        }
    }
    //insert random gene
    if (RADIATION > (rand()%MAX_SCALE))
    {
        size_t position = internalArray.size() != 0 ?rand()%internalArray.size() : 0;
        shima_t shima   = rand();
        
        internalArray.insert(internalArray.begin() + position,shima);
    }
    //Swap two or delete
    if ((internalArray.size() > 1) && (RADIATION > (rand()%MAX_SCALE)))
    {
        size_t position1 = rand()%internalArray.size();
        size_t position2 = rand()%internalArray.size();
        if(position1 == position2)
        {
            internalArray.erase(internalArray.begin()+position1);
        }
        else
        {
            std::iter_swap(internalArray.begin() + position1, internalArray.begin() + position2);
        }
    }
}


Fleet* Gclass::fleetCreate() const
{
    return new Fleet(internalArray);
}

Gclass* Gclass::empty()
{
    Gclass* result = new Gclass;
    result->internalArray.push_back(0);
    result->filename = random_string(16);
    return result;
}

bool Gclass::betterThan(const Gclass *other) const
{
    return score > other->score;
}

size_t randomMedium(size_t length)
{
    long result = length/2 + (RADIATION > (rand()%MAX_SCALE)?rand()%3 -1 :0 );
    result = result > 0? result:0;
    result = length < result? length: result;
    return result;
}

Gclass* Gclass::crossover(Gclass *gene)
{
    size_t myGenes = randomMedium(internalArray.size());
    size_t theirsGenes = randomMedium(gene->internalArray.size());
    Gclass* result = new Gclass;
    if (rand()%2)
    {
        for(auto it = internalArray.begin(); it != internalArray.begin()+myGenes && it != internalArray.end(); it++) result->internalArray.push_back(*it);
        for(auto it = gene->internalArray.end() - theirsGenes; it != gene->internalArray.end(); it++) result->internalArray.push_back(*it);
    }
    else
    {
        for(auto it = gene->internalArray.begin(); it != gene->internalArray.begin()+theirsGenes && it != gene->internalArray.end(); it++)
            result->internalArray.push_back(*it);
        for(auto it = internalArray.end() - myGenes; it != internalArray.end(); it++) result->internalArray.push_back(*it);
    }

    result->filename = random_string(16);
    result->mutation();
    return result;
}

void Gclass::deleteGene(std::string dir)
{
    remove((dir + filename).c_str());
}

void Gclass::compare(Gclass* other)
{
    auto myFleet = fleetCreate();
    auto otherFleet = other->fleetCreate();


    switch (myFleet->result(otherFleet)) {
        case WIN:
            score+=3;
            break;
        case DRAW:
            score+=1;
            other->score+=1;
            break;
        case FAIL:
            other->score+=3;
            break;
        default:
            break;
    }
    delete myFleet;
    delete otherFleet;
}


void Gclass::print()
{
    auto fleet = fleetCreate();
    fleet->print();
    delete fleet;
}

void Gclass::clearScore()
{
    score = 0;
}

