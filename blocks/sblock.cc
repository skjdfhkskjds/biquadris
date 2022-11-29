// #include "../block.h"
#include "sblock.h"
#include "coordinates.h"
#include <vector>
#include <memory>

using namespace std;

SBlock::SBlock() : Block{} 
{
    pImpl->coords = {make_unique<Coordinates>(new Coordinates(2, 4)),
    make_unique<Coordinates>(new Coordinates(2, 5)),
    make_unique<Coordinates>(new Coordinates(1, 5)),
    make_unique<Coordinates>(new Coordinates(1, 6))}
}

bool SBlock::isSafe()
{
    for (unique_ptr<Coordinates> coord : pImpl->coords)
    {
        if (!isSafe()) return false;
    }
    return true;
}

void SBlock::rotateClockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    int r = pImpl->rotationState % 4;
    switch (r)
    {
    case 0:
        pImpl->coords.at(0)->updateCoords(0,-2);
        pImpl->coords.at(1)->updateCoords(-1,-1);
        pImpl->coords.at(2)->updateCoords(0,0);
        pImpl->coords.at(3)->updateCoords(-1,1);
        break;
    case 1:
        pImpl->coords.at(0)->updateCoords(2,0);
        pImpl->coords.at(1)->updateCoords(1,-1);
        pImpl->coords.at(2)->updateCoords(0,0);
        pImpl->coords.at(3)->updateCoords(-1,-1);
        break;
    case 2:
        pImpl->coords.at(0)->updateCoords(0,2);
        pImpl->coords.at(1)->updateCoords(1,1);
        pImpl->coords.at(2)->updateCoords(0,0);
        pImpl->coords.at(3)->updateCoords(1,-1);
        break;
    case 3:
        pImpl->coords.at(0)->updateCoords(-2,0);
        pImpl->coords.at(1)->updateCoords(-1,1);
        pImpl->coords.at(2)->updateCoords(0,0);
        pImpl->coords.at(3)->updateCoords(1,1);
        break;
    }
    rotationState++;
}

void SBlock::rotateCounterClockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    int r = rotationState % 4;
    switch (r)
    {
    case 0:
        pImpl->coords.at(0)->updateCoords(2,0);
        pImpl->coords.at(1)->updateCoords(1,-1);
        pImpl->coords.at(2)->updateCoords(0,0);
        pImpl->coords.at(3)->updateCoords(-1,-1);
        break;
    case 1:
        pImpl->coords.at(0)->updateCoords(0,-2);
        pImpl->coords.at(1)->updateCoords(1,-1);
        pImpl->coords.at(2)->updateCoords(0,0);
        pImpl->coords.at(3)->updateCoords(-1,1);
        break;
    case 2:
        pImpl->coords.at(0)->updateCoords(-2,0);
        pImpl->coords.at(1)->updateCoords(-1,1);
        pImpl->coords.at(2)->updateCoords(0,0);
        pImpl->coords.at(3)->updateCoords(1,1);
        break;
    case 3:
        pImpl->coords.at(0)->updateCoords(0,2);
        pImpl->coords.at(1)->updateCoords(1,1);
        pImpl->coords.at(2)->updateCoords(0,0);
        pImpl->coords.at(3)->updateCoords(1,-1);
        break;
    }
    rotationState--;
}

void SBlock::shiftRight() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    pImpl->coords.at(0)->updateCoords(1,0);
    pImpl->coords.at(1)->updateCoords(1,0);
    pImpl->coords.at(2)->updateCoords(1,0);
    pImpl->coords.at(3)->updateCoords(1,0);
}

void SBlock::shiftLeft() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    pImpl->coords.at(0)->updateCoords(-1,0);
    pImpl->coords.at(1)->updateCoords(-1,0);
    pImpl->coords.at(2)->updateCoords(-1,0);
    pImpl->coords.at(3)->updateCoords(-1,0);
}


/*
void decay();
    */
