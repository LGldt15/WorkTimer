all: executable.out
executable.out: main.o settings.o
	g++ -g main.o settings.o -o executable.out
main.o: main.cpp settings.h
	g++ -g -Wall -c main.cpp
settings.o: settings.h settings.cpp
	g++ -g -Wall -c settings.cpp
clean:
	rm *.o
veryclean: clean
	rm *.out