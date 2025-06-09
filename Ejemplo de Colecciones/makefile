INTERFACES = ICollection/interfaces/
COLECCIONES = ICollection/collections/


all: Animal.o Gato.o Perro.o Persona.o main.o ICollectible.o IIterator.o ICollection.o ListNode.o ListIterator.o List.o
	g++ Animal.o Gato.o Perro.o Persona.o main.o ICollectible.o IIterator.o ICollection.o ListNode.o ListIterator.o List.o -o programa

ICollectible.o: $(INTERFACES)ICollectible.h
	g++ -c $(INTERFACES)ICollectible.cpp 

IIterator.o: $(INTERFACES)IIterator.h $(INTERFACES)ICollectible.o
	g++ -c $(INTERFACES)IIterator.cpp 

ICollection.o: IIterator.o ICollectible.o $(INTERFACES)ICollection.h
	g++ -c $(INTERFACES)ICollection.cpp

ListNode.o: $(COLECCIONES)ListNode.h ICollectible.o
	g++ -c $(COLECCIONES)ListNode.cpp

ListIterator.o: $(COLECCIONES)ListIterator.h ListNode.o 
	g++ -c $(COLECCIONES)ListIterator.cpp

List.o: ICollection.o ListIterator.o $(COLECCIONES)List.h
	g++ -c $(COLECCIONES)List.cpp

Animal.o: ICollectible.o
	g++ -c Animal.cpp

Gato.o: Animal.o
	g++ -c Gato.cpp

Perro.o: Animal.o
	g++ -c Perro.cpp	

Persona.o: Animal.o Gato.o Perro.o ICollection.o
	g++ -c Persona.cpp

main.o: Animal.o Gato.o Perro.o Persona.o
	g++ -c main.cpp

clean:
	rm -f programa *.o $(INTERFACES)*.o $(COLECCIONES)*.o
run:
	make clean
	make
	clear
	./programa