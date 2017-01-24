/* 
 * File:   BufferedAsyncSerial.h
 * Author: Terraneo Federico
 * Distributed under the Boost Software License, Version 1.0.
 * Created on January 6, 2011, 3:31 PM
 */

#include "AsyncSerial.h"

using namespace boost;
using namespace std;

#ifndef BUFFEREDASYNCSERIAL_H
#define	BUFFEREDASYNCSERIAL_H

class BufferedAsyncSerial: public AsyncSerial
{
public:
    BufferedAsyncSerial();

    /**
    * Opens a serial device.
    * \param devname serial device name, example "/dev/ttyS0" or "COM1"
    * \param baud_rate serial baud rate
    * \param opt_parity serial parity, default none
    * \param opt_csize serial character size, default 8bit
    * \param opt_flow serial flow control, default none
    * \param opt_stop serial stop bits, default 1
    * \throws boost::system::system_error if cannot open the
    * serial device
    */
    BufferedAsyncSerial(const std::string& devname, unsigned int baud_rate,
        asio::serial_port_base::parity opt_parity=
            asio::serial_port_base::parity(
                asio::serial_port_base::parity::none),
        asio::serial_port_base::character_size opt_csize=
            asio::serial_port_base::character_size(8),
        asio::serial_port_base::flow_control opt_flow=
            asio::serial_port_base::flow_control(
                asio::serial_port_base::flow_control::none),
        asio::serial_port_base::stop_bits opt_stop=
            asio::serial_port_base::stop_bits(
                asio::serial_port_base::stop_bits::one));

    /**
     * Read some data asynchronously. Returns immediately.
     * \param data array of char to be read through the serial device
     * \param size array size
     * \return numbr of character actually read 0<=return<=size
     */
    size_t read(char *data, size_t size);

    /**
     * Read all available data asynchronously. Returns immediately.
     * \return the receive buffer. It iempty if no data is available
     */
    vector<char> read();

    /**
     * Read a string asynchronously. Returns immediately.
     * Can only be used if the user is sure that the serial device will not
     * send binary data. For binary data read, use read()
     * The returned string is empty if no data has arrived
     * \return a string with the received data.
     */
    string readString();

     /**
     * Read a line asynchronously. Returns immediately.
     * Can only be used if the user is sure that the serial device will not
     * send binary data. For binary data read, use read()
     * The returned string is empty if the line delimiter has not yet arrived.
     * \param delimiter line delimiter, default='\n'
     * \return a string with the received data. The delimiter is removed from
     * the string.
     */
    string readStringUntil(const std::string delim="\n");

    virtual ~BufferedAsyncSerial();

private:

    /**
     * Read callback, stores data in the buffer
     */
    void readCallback(const char *data, size_t len);

    /**
     * Finds a substring in a vector of char. Used to look for the delimiter.
     * \param v vector where to find the string
     * \param s string to find
     * \return the beginning of the place in the vector where the first
     * occurrence of the string is, or v.end() if the string was not found
     */
    static vector<char>::iterator findStringInVector(vector<char>& v,
            const string& s);

    vector<char> readQueue;
    mutex readQueueMutex;
};

#endif //BUFFEREDASYNCSERIAL_H
