/*
    Smartt C++ Client
    Copyright 2013 S10I (s10i.com.br)

    Author: Felipe Menezes Machado (felipe@s10i.com.br)
*/

#ifndef SMARTT_SIMPLE_PROTOCOL_H
#define SMARTT_SIMPLE_PROTOCOL_H

// Standard library dependencies
#include <exception>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*************************************************************************************************
  Simple Stream abstract class
    Represents a duplex stream of data used by the protocol handler to send and receive messages.
    Has just two pure virtual functions for reading and writing data.
*************************************************************************************************/
class SimpleStream {
public:
    virtual string read() = 0;
    virtual void write(const string &data) = 0;
};


/*************************************************************************************************
  Smartt Simple Protocol class
    The protocol used by Smartt for sending and receiving messages that are lists of strings.
    Basically just concatenates the escaped strings with colon as the separator, and $ (dollar
    sign) as the end of message character.
*************************************************************************************************/
class SmarttSimpleProtocol {

public:

    // Constructor
    SmarttSimpleProtocol(SimpleStream &simpleStream);

    void sendMessage(const vector<string> &message);
    vector<string> receiveMessage();

private:

    // The stream to be used for sending and receiving data
    SimpleStream &stream;

    // The buffer of data received from the stream
    string stream_receive_buffer_;

};

#endif // SMARTT_SIMPLE_PROTOCOL_H