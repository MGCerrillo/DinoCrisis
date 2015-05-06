OBJECTS = main.o

CCFLAGS = -lGL -lglut -lGLU

main.out:  $(OBJECTS)
	g++ -o main.out $(OBJECTS) $(CCFLAGS)

main.o: main.cpp
	g++ -c main.cpp $(CCFLAGS)

clean:
	rm -f $(OBJECTS)