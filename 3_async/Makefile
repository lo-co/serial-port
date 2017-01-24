#Using MinGW distro from http://nuwen.net/mingw.html that contains boost precompiled
 
all:
	echo "Compiling main..."
	g++ -O2 -std=c++11 -c main.cpp 
	echo "Compiling AsyncSerial..."
	g++ -O2 -std=c++11 -c AsyncSerial.cpp 
	echo "Compiling BufferedAsyncSerial..."
	g++ -O2 -std=c++11 -c BufferedAsyncSerial.cpp
	echo "Linking..."
	g++ -o -std=c++11 async.exe main.o AsyncSerial.o BufferedAsyncSerial.o -s -lpthread -lboost_system -lboost_thread

#clean:
#	del async.exe main.o AsyncSerial.o BufferedAsyncSerial.o
