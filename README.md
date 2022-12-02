# biquadris

hewwo everyone!!!<3333 welcome to our wittle biqwuadris project plan!!uwu :D hope u likeyy hehe :3

## Problems to Solve Still

1. implement all of the blocks
2. implement file interpretation and reading for level 0
3. make command line arg processing
4. make effect factory to apply effects


## Current Changes

### Block

block uses a pImpl that processes all computation of updating and checking whether a transformation is valid



# Actual Design Plan

## Controller Classes

### main.o
- wraps the entire program
- takes in command line input and sets up a "game" accordingly
- runs the game until game returns winner
- prints final statement and returns 0

### game.o
- contains game data (two players, sequences, seed, startinglevel)
- calls for user input per move and passes it along to command interpreter
- returns to main when game is over with an int (indicates who won)

### commandinterpreter.o
- contains logic to process string input and runs the appropriate command
- allows setting macros and rename existing commands

**command calling**

- left, right, down, clockwise, counterclockwise, drop: sent to player->block?
- levelup, leveldown, norandom, random, sequence: sent to player
- I, J, L, O, S, Z, T: sent to player->board
- force, heavy, blind: sent to player->board
- restart: sent to game

## Model Classes

### player.o
- contains player data
  - level (level class)
  - board (board class)
  - sequence (respective to player, could be a vector of strings or something)
  - turns (int)
  - newTurn(effect=""): calls a new turn for the player, if an effect is applied then apply on all output, returns when turn is done
- returns boardstate to observers through notifyobservers()

### board.o
- contains board info and wrapper class for boardstate
  - board size
  - boardstate vector
- depends on boardstate to store and manipulate the board state of board
- returns boardstate to player on update
  - depends on effects to apply effects onto current state
    - not long lasting effects get reset on conclusion of turn

### boardstate.o
- contains
  - vector to represent the board in 1D array
  - currBlock: contains the coordinates to the most recent block (if not dropped)
  - checkRow(int row): checks whether row is full (true/false)
  - clearRow(int row): removes all values occupied by row (setting to -1), shifts everything above row down
  - clearPiece(int x, int y): removes the value at (x, y) and sets old value store to -1
  - isSafe(transform): returns bool to represent whether transform is safe
  - addBlock(block): adds the block to boardstate

### levels.o
- parent class for the various levels
- handles level generation, and sets the respective player's level object to be the current level
- contains blockGen (returns a new block according to block generation logic)

### block.o
- parent class for various blocks
- contains:
  - vector of coordinates (doesn't have to be a type)
  - blockType (could be the char itself)
  - age
  - maxDuration
  - decays (flag for whether block decays, default=false)
- block transformations are handled here
  - let transform be vector<int> or vector<Coordinates>
  - isSafe(transform): returns true if a transformation can be done safely
  - updateBlock(transform): applies a 
- handle decay if true
  - in coordinates, if not -1, remove from boardstate and set to -1


### POTENTIAL IMPLEMENTATIONS OF BLOCKS

### blocks as a decorator


### blocks as a factory

**Advantages**
- BIG ADVANTAGE: BASICALLY HOW WE PROGRAMMED IT ALREADY (without the abstraction)
- easy to produce new blocks without worrying about underlying type
- simple storage (we can store board as either a char vector or vector of unique_ptr to blocks)
- allows us to make standard issue checks and comparisons with individual non-connected blocks
- each block type would have overrides on movement and transformation, with an external interface to block which allows public users to access and manipulate the block
- would have some getState() function that returns the current coordinates of the block (maybe we can just access the field and modify directly (removes the need for coordinates as unique_ptr))


**Disadvantages**
- difficult to implement decay and effects, as blocks are more "static" as they are produced without consideration for different effects on the board
  - decay:
    - every end of turn, increment the age values of each of the blocks in the vector
    - if age == limit && decays: set coordinates to -1
  - heavy:
    - this effect needs to be implemented in different ways depending on the way that it is called
      - as an effect
        - applyHeavy() is applied on left and right shifts only
      - as a level
        - applyHeavy() is applied on all moves (rotations and shifts)
    - this means that some external class must handle transformations, that can be decorated with an effect
      - at runtime, we apply a layer over the transformation wrapper class to handle the "next block" such that it overrides the original interpretation of commands
      - the decorator takes in the current transformation wrapper as a unique_ptr
        - in this case decorates a block? class since the block class handles block transformations in current implementation

### effects.o
- parent class for various effects
- contains:
  - longLasting: flag for whether an effect is long lasting (should persist after the conclusion of this turn)
  - boardstate: temporary boardstate (could be just a vector to simplify storage)
- handles creating and applying effects onto boardstate

## Viewer Classes

### textviewer.o
- text-based output of boardstates
- on notify(), refreshes its view of both players boardstates (stored as vectors (whole class is excessive))

### graphicsviewer.o
- graphical window-based output of boardstates
- maybe? contains logic to more intelligently render boardstate (check differences between old and new vector and only rerender those indices)
- depends on xwindow to run graphics

### xwindow.o
- logic for all graphical output (written by cs246 staff)



**player:**
- unqiue_ptr<Block> getNext();
  - asks level to produce a new block
- vector<char> getState();
  - gets state from the abstract board
- bool changeLvl(int newLvl);
  - acutlaly should be 2 methods, one going up and one going down
  - returns whether a level has been successfully changed (not sure if this is useful)

contains:
- **abstractboard**
  - handles board functions that are overriden by the base class and decorator
  - contains:
    - **level:**
      - 

**abstractboard:**
- virtual apply(Board &board) = 0;

contains:
- **board:**
  - 
- **effectdecorator:**
  - shared_ptr<abstractboard> board
  - virtual apply(Board &board) = 0;
  - contains:
    - **heavy:**
      - apply(Board &board) override;
        - 