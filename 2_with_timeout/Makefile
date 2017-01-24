#Using MinGW distro from http://nuwen.net/mingw.html that contains boost precompiled
 
all:
	g++ -O2 -c main.cpp
	g++ -O2 -c TimeoutSerial.cpp
	g++ -o timeout.exe main.o TimeoutSerial.o -s -lpthread -lboost_system

clean:
	del timeout.exe main.o TimeoutSerial.o
