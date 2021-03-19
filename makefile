CXX = g++

CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

SpaceSaving: SpaceSaving.o main.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f SpaceSaving *.o