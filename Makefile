CXX = g++
CXXFLAGS = std=c++14 -Werror=vla -Wall -MMD
OBJECTS = main.o board.o player.o subject.o observer.o exceptions.o
EXEC = main

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
