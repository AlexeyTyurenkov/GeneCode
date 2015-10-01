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



Gclass* Gclass::loadFromFile(std::string filename)
{
    Gclass* result = nullptr;
    //open file
    ifstream infile(filename, ios_base::binary|ios_base::in|ios::ate);
    //if file opened
    if (infile.is_open())
    {
        //get file size
        size_t buffersize =infile.tellg();
        //create buffer
        char* charArray = new char[buffersize];
        //return to file start
        infile.seekg(ios::beg);
        //read all from file
        infile.read(charArray, buffersize);
        //close file
        infile.close();
        result = new Gclass;
        result->length = buffersize/sizeof(uint32_t);
        result->internalArray = new uint32_t[result->length];
        //copy array to object
        memcpy(result->internalArray, charArray, buffersize);
        //save file name
        result->filename = filename;
        //create fleet
        //result->fleetCreate();

        delete [] charArray;
    }
    return result;
}

bool Gclass::save()
{
    bool result = false;
    ofstream outfile(filename, ios_base::binary|ios_base::out|ios::trunc);
    if (outfile.is_open())
    {
//        mutation();
        outfile.write(reinterpret_cast<char*>(internalArray), length * sizeof(uint32_t));
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

void Gclass::mutation()
{
    for (int i = 0; i < length; i++)
    {
        if (RADIATION > (rand()%MAX_SCALE))
        {
            internalArray[i]^= 1 << rand()%32;
        }
    }
}


Fleet* Gclass::fleetCreate() const
{
    return new Fleet(internalArray, length);
}

Gclass* Gclass::empty()
{
    Gclass* result = new Gclass;
    result->length = 1;
    result->internalArray = new uint32_t[result->length];
    result->internalArray[0] = 0;
    result->filename = string(MAIN_DIR) + random_string(16);
    return result;
}

bool Gclass::betterThan(const Gclass *other) const
{
    return length > other->length;
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
    size_t myGenes = randomMedium(length);
    size_t theirsGenes = randomMedium(gene->length);
    Gclass* result = new Gclass;
    result->length = myGenes + theirsGenes;
    result->internalArray = new uint32_t[result->length];
    if (rand()%2)
    {
        if(myGenes) memcpy(result->internalArray, internalArray,  myGenes);
        if(theirsGenes) memcpy(result->internalArray+myGenes, gene->internalArray + gene->length - theirsGenes - 1, theirsGenes);
    }
    else
    {
        if(theirsGenes) memcpy(result->internalArray, gene->internalArray,  theirsGenes);
        if(myGenes) memcpy(result->internalArray+theirsGenes, internalArray + length - myGenes - 1, myGenes);
    }
    //insert random gene
    if (RADIATION > (rand()%MAX_SCALE))
    {
        result->length++;
        auto rs = new uint32_t[result->length];
        memcpy(rs, result->internalArray, result->length - 1);
        rs[result->length - 1] = 0;
        delete [] result->internalArray;
        result->internalArray = rs;
    }
    result->filename = string(MAIN_DIR) + random_string(16);
    return result;
}

void Gclass::deleteGene()
{
    remove(filename.c_str());
//    if( remove(filename.c_str()) != 0 )
//        perror( "Error deleting file" );
    delete [] internalArray;
}

void Gclass::compare(Gclass* other)
{
    auto myFleet = fleetCreate();
    auto otherFleet = other->fleetCreate();
    myFleet->wins(otherFleet)?score++:other->score++;
    delete myFleet;
    delete otherFleet;
}
