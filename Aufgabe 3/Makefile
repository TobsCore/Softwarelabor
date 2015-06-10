all: program

program: my_String.o testFile.o
	g++ my_String.o testFile.o -o tests

myString.o:	my_String.cpp
	g++ -c myString.cpp -Wall

testFile.o: testFile.cpp
	g++ -c testFile.cpp -Wall

clean:
	rm *.o tests
