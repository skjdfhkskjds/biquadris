CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
OBJECTS = main.o

DEPENDS = ${OBJECTS:.o=.d}
EXEC = main

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

.PHONY: clean

clean:
	rm *.o main
