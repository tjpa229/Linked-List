OBJECTS = main.o LinkedList.o 

myEditor: $(OBJECTS)
	g++ $^ -o myEditor



%.o: %.cpp
	g++ -c $< -o $@

HEADERS = LinkedList.h

%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

clean:
	rm -f *.o myEditor

