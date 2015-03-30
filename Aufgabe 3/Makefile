all:	program

program:	my_String.o testFile.o
	g++ my_String.o testFile.o -o tests.o

myString.o:	my_String.cpp
	g++ -c myString.cpp

testFile.o:	testFile.cpp
	g++ -c testFile.cpp

clean:
	rm *.o
