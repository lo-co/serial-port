#Using MinGW distro from http://nuwen.net/mingw.html that contains boost precompiled
 
all:
	g++ -O2 -c main.cpp
	g++ -o simple.exe main.o -s -lpthread -lboost_system

clean:
	del simple.exe main.o
