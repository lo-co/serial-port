
#include <iostream>
#include "SimpleSerial.h"

using namespace std;
using namespace boost;

int main(int argc, char* argv[])
{
    try {

        SimpleSerial serial("/dev/ttyO2",19200);
        serial.writeString("\r\r");
        serial.writeString("B\r");

        cout<<"Received : "<<serial.readLine()<<" : end"<<endl;

    } catch(boost::system::system_error& e)
    {
        cout<<"Error: "<<e.what()<<endl;
        return 1;
    }
}

