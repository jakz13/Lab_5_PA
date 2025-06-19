CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = restopub.exe

all: $(EXEC)

$(EXEC): $(OBJ)
    $(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $<

clean:
    del /Q *.o *.exe

run: all
    $(EXEC)