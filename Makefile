Draw: Color.o Draw.o main.o
	g++ -o Draw Color.o Draw.o main.o -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio -lsfml-network

main.o: main.cpp
	g++ -c main.cpp

Draw.o: Draw.cpp
	g++ -c Draw.cpp

Color.o: Color.cpp
	g++ -c Color.cpp

.PHONY: clean

clean:
	rm -rf *.o