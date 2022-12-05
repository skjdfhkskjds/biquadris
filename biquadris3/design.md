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
    - run():
        - monitors turns and swaps player command calling
        - handles player effect calling as well, setEffect(effect) to opponent

- player.cc:
    - PlayerImpl::playTurn()
      - ends on "done" -> try whether currBlock is on the floor, if not drop
      - calls currBlock = nextBlock && nextBlock = makeBlock()
      - calls resetEffects() 
      - if generateBlock() == invalid_move, return loss


<!-- michelle is making random numbers work for levels -->
- level.o:
    - implement generateBlock() for all levels.


<!-- dom working on making clockwise and counterclockwise work -->
- block.cc:
    - implement decay() ???
    - penaltyblock.cc:
      - implement ctor as directed

- add a function to render the block to the board
  - need this since nextBlock doesn't "exist" yet while the turn is playing out but must be spawned as the current block (on the squares) by the beginning on the opponents turn

main/command interpreter
- if player level change is invalid, must catch
- send effect commands to other player
- write out all implementations for the commands

<!-- force.apply() needs to implemented in the player effect handler -->
force.cc
- doesnt seem to call apply() anywhere

OVERALL CHANGE
- changing transform format means we have to redo isSafe() as well

- text.o + graphics.o:
    - implement observers with access to game as subject


## Design Plan

### Relevant Design Patterns

**Model, View, Controller** used to handle user input to logic to output

**Observer** used to render outputs to text and graphics

**Decorator** used to decorate AbstractBoard with an Effect layer

**Factory** used to produce Levels (lol!)

