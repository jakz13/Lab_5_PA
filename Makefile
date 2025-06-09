CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = restopub

all: $(EXEC)

$(EXEC): $(OBJ)
    $(CXX) $(CXXFLAGS) -o $@ $^

clean:
    del *.o *.exe