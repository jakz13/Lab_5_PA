CXX = g++
CXXFLAGS = -std=c++11 -Wall -I./ICollection -I./ICollection/interfaces -I./ICollection/collections

# Buscar automáticamente todos los archivos fuente .cpp
SRCS = $(wildcard *.cpp) \
       $(wildcard ICollection/*.cpp) \
       $(wildcard ICollection/collections/*.cpp) \
       $(wildcard ICollection/interfaces/*.cpp)

# Generar los nombres de objetos a partir de los nombres de fuente
OBJS = $(SRCS:.cpp=.o)

PROG = restopub

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(PROG)

run: all
	./$(PROG)
