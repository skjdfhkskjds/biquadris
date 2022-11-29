// #include "../block.h"
#include "sblock.h"
#include "coordinates.h"
#include <vector>

SBLock::SBlock() : Block{} 
{
    unique_ptr<Coordinates> p0(new Coordinates(2, 4));
    unique_ptr<Coordinates> p1(new Coordinates(2, 5));
    unique_ptr<Coordinates> p2(new Coordinates(1, 5));
    unique_ptr<Coordinates> p3(new Coordinates(1, 6));
    coords = {p0, p1, p2, p3};
}

void SBlock::rotateClockwise() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    int r = rotationState % 4;
    switch (r)
    {
    case 0:
        coords.at(0)->updateCoords(0,-2);
        coords.at(1)->updateCoords(-1,-1);
        coords.at(2)->updateCoords(0,0);
        coords.at(3)->updateCoords(-1,1);
        break;
    case 1:
        coords.at(0)->updateCoords(2,0);
        coords.at(1)->updateCoords(1,-1);
        coords.at(2)->updateCoords(0,0);
        coords.at(3)->updateCoords(-1,-1);
        break;
    case 2:
        coords.at(0)->updateCoords(0,2);
        coords.at(1)->updateCoords(1,1);
        coords.at(2)->updateCoords(0,0);
        coords.at(3)->updateCoords(1,-1);
        break;
    case 3:
        coords.at(0)->updateCoords(-2,0);
        coords.at(1)->updateCoords(-1,1);
        coords.at(2)->updateCoords(0,0);
        coords.at(3)->updateCoords(1,1);
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
        coords.at(0)->updateCoords(2,0);
        coords.at(1)->updateCoords(1,-1);
        coords.at(2)->updateCoords(0,0);
        coords.at(3)->updateCoords(-1,-1);
        break;
    case 1:
        coords.at(0)->updateCoords(0,-2);
        coords.at(1)->updateCoords(1,-1);
        coords.at(2)->updateCoords(0,0);
        coords.at(3)->updateCoords(-1,1);
        break;
    case 2:
        coords.at(0)->updateCoords(-2,0);
        coords.at(1)->updateCoords(-1,1);
        coords.at(2)->updateCoords(0,0);
        coords.at(3)->updateCoords(1,1);
        break;
    case 3:
        coords.at(0)->updateCoords(0,2);
        coords.at(1)->updateCoords(1,1);
        coords.at(2)->updateCoords(0,0);
        coords.at(3)->updateCoords(1,-1);
        break;
    }
    rotationState--;
}

void SBlock::shiftRight() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    coords.at(0)->updateCoords(1,0);
    coords.at(1)->updateCoords(1,0);
    coords.at(2)->updateCoords(1,0);
    coords.at(3)->updateCoords(1,0);
}

void SBlock::shiftLeft() 
{
    //IMPLEMENT A COLLISION CHECK METHOD AND CALL IT BEFORE UPDATECOORDS
    coords.at(0)->updateCoords(-1,0);
    coords.at(1)->updateCoords(-1,0);
    coords.at(2)->updateCoords(-1,0);
    coords.at(3)->updateCoords(-1,0);
}


/*
void decay();
    */
