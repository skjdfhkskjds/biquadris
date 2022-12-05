#ifndef _BLOCK_
#define _BLOCK_

#include <vector>
#include <memory>
#include "../../common/coordinates.h"

class Block
{
    class BlockImpl;
    std::unique_ptr<BlockImpl> impl;

protected:
    int getState(); // returns the rotation state

    // setter methods
    void setCoords(std::vector<Coordinates> &coords); // sets the coordinates of block
    void setState(int newState);                      // sets the rotation state
    vector<vector<int>> getVVICoords();               // returns the coords in vvi form
    void decay();                                     // decays the block

    vector<vector<int>> spawnTransformation(vector<vector<int>> coords, map<int, vector<vector<int>>> spawnState, int currState);
    vector<vector<int>> vviAddition(vector<vector<int>> a, vector<vector<int>> b);    // a + b
    vector<vector<int>> vviSubtraction(vector<vector<int>> a, vector<vector<int>> b); // a - b

public:
    Block(char c, int lvl) noexcept;
    ~Block();

    // getter methods
    char getChar();                       // returns the block's char
    std::vector<Coordinates> getCoords(); // returns the block's coordinates
    int getLvl();                         // returns the level that the block was made
    bool fullCleared();                   // returns whether a block has been fully cleared
    bool isHeavy();                       // returns whether a block is heavy

    // setter methods
    void updateCoords(Coordinates oldCoords, Coordinates newCoords=Coordinates{-1, -1});

    // block transformations
    std::vector<std::vector<int>> right(); // shifts the block right
    std::vector<std::vector<int>> left();  // shifts the block left
    std::vector<std::vector<int>> down();  // shifts the block down

    virtual std::vector<std::vector<int>> clockwise() = 0;        // rotates the block clockwise
    virtual std::vector<std::vector<int>> counterClockwise() = 0; // rotates the block counters clockwise
};

#endif
