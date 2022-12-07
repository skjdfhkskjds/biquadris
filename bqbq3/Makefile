CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
OBJECTS = main.o model/board/board.o model/board/boardstate.o model/board/abstractboard.o model/player.o controller/commands.o common/exceptions.o model/blocks/block.o model/blocks/iblock.o model/blocks/jblock.o model/blocks/lblock.o model/blocks/oblock.o model/blocks/sblock.o model/blocks/tblock.o model/blocks/zblock.o common/square.o common/coordinates.o model/levels/level.o model/levels/levelzero.o model/levels/levelone.o model/levels/leveltwo.o model/levels/levelthree.o model/levels/levelfour.o common/random.o model/effects/blind.o model/effects/force.o model/effects/heavy.o model/effects/effectdecorator.o model/subject.o controller/game.o viewer/graphics.o viewer/text.o viewer/window.o viewer/observer.o
EXEC = main

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11
-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
