all:
	g++ -g -c -o main.o main.cpp
	g++ -g -c -o manualTests.o manualTests.cpp
	g++ -g -c -o hashFunctions.o dst/hashFunctions.cpp
	g++ -g -o main main.o hashFunctions.o
	g++ -g -o manualTests manualTests.o hashFunctions.o


clean:
	rm -f *.o
	rm -f main
	rm -f manualTests
