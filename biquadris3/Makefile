CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
OBJECTS = controller/main.o misc/coordinates.o #board.o boardstate.o player.o subject.o observer.o commands.o exceptions.o  block.o 
EXEC = main

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11
-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
