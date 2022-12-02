# Biquadris

## Things to Implement
- commands.cc:
    - update apply() to use enums instead of switch case int
    - if rename is allowed:
        - fix rename to modify the least num of characters
        - every time rename() is called, call a function to rebuild least num of characters (maybe theres an algorithm that produces the least number of chars required to differentiate)
    - if macro:
        - add macro to the least num of characters list

- game.cc:
    - Game()
    - run()
    - getState()

- player.cc:
    - PlayerImpl::PlayerImpl()
    - PlayerImpl::playTurn()
    - levelUp()
    - levelDown()

- level factory
    - make this somehow idk lol
    - each product should be a level (e.g. LevelZero)
    - the levels contain:
        - char generateBlock() which returns a char indicating which block should be made by board.makeBlock(char type)

- block.cc
    - implement decay() ???

- text.o + graphics.o
    - implement observers with access to game as subject




## Design Plan

### Relevant Design Patterns

**Model, View, Controller** used to handle user input to logic to output

**Observer** used to render outputs to text and graphics

**Decorator** used to decorate AbstractBoard with an Effect layer

**Factory** used to produce Levels

