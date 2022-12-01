CXX = g++
CXXFLAGS = std=c++14 -Werror=vla -Wall -MMD
OBJECTS = main.o board.o boardstate.o player.o subject.o observer.o commands.o exceptions.o coordinates.o block.o 
EXEC = main

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS} -X11

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
