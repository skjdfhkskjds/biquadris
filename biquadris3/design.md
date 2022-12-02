# Biquadris

## Things to Implement
- main.cc:
  - update this version to be biquadris 2.0's main

- commands.cc:
    - update apply() to use enums instead of switch case int
    - if rename is allowed:
        - fix rename to modify the least num of characters
        - every time rename() is called, call a function to rebuild least num of characters (maybe theres an algorithm that produces the least number of chars required to differentiate)
    - if macro:
        - add macro to the least num of characters list

- game.cc:
    - Game():
        - constructs players -> board -> states & levels
    - run():
        - monitors turns and swaps player command calling
        - handles player effect calling as well, setEffect(effect) to opponent
    - getState()
      - returns vector<vector<char>>, contains both boards for p1 and p2

- player.cc:
    - PlayerImpl::PlayerImpl()
    - PlayerImpl::playTurn()
      - ends on "done" -> try whether currBlock is on the floor, if not drop
      - calls currBlock = nextBlock && nextBlock = makeBlock()
      - calls resetEffects() 
    - levelUp()
      - maybe? make a new function that returns a unique_ptr<Level> based on int for levelUp and levelDown
    - levelDown()

- level.o:
    - implement generateBlock() for all levels.

- block.cc:
    - implement decay() ???
    - penaltyblock.cc:
      - implement ctor as directed

- boardstate.cc:
    - change clearRow() to update Coordinates to -1 when removed
    - getScore(row):
      - implement such that returns the score of clearing row
    - placeBlock():
        - emplace_back() to placed when the turn is over

- text.o + graphics.o:
    - implement observers with access to game as subject


## Design Plan

### Relevant Design Patterns

**Model, View, Controller** used to handle user input to logic to output

**Observer** used to render outputs to text and graphics

**Decorator** used to decorate AbstractBoard with an Effect layer

**Factory** used to produce Levels

