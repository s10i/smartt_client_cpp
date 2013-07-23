/*
    Smartt C++ Client
    Copyright 2013 S10I (s10i.com.br)

    Author: Felipe Menezes Machado (felipe@s10i.com.br)
*/

#ifndef SMARTT_SIMPLE_CONNECTION_H
#define SMARTT_SIMPLE_CONNECTION_H

// Standard library dependencies
#include <exception>
#include <string>
#include <vector>

using namespace std;

// Local dependencies
#include "smartt_simple_protocol.h"
#include "smartt_socket.h"

/*************************************************************************************************
  Socket Stream class
    A simple stream class for the Smartt Simple Protocol handler. Reads and writes directly
    from an underlying socket.
*************************************************************************************************/
class SocketStream : public SimpleStream {

public:

    // Constructor
    SocketStream(SmarttSocket &socket);

    string read();
    void write(const string &data);

private:

    // Underlying socket object
    SmarttSocket &socket_;

};

/*************************************************************************************************
  Smartt Simple Connection class
    An interface to a connection with the Smartt server using the Smartt Simple Protocol. Simply
    connects to the server, and sends and receives message from it.
*************************************************************************************************/
class SmarttSimpleConnection {

public:
    
    // Constructor
    SmarttSimpleConnection(const string &host, const int port, const bool use_ssl);

    // Connects to the Smartt server
    void connect();

    // Disconnects to the Smartt server
    void disconnect();

    // Sends a message (list of strings) to the server
    void sendMessage(const vector<string> &message);

    // Receives a message from the server
    vector<string> receiveMessage();

    // Sends a raw message string to the server
    void sendRawMessage(const string &message);

    // Receives a raw message from the server
    string receiveRawMessage();

private:

    // Socket connection with the server
    SmarttSocket socket_;

    // Simple socket stream for the smartt protocol to use
    SocketStream socket_stream_;

    // Smartt Simple Protocol handler
    SmarttSimpleProtocol smartt_simple_protocol_;

};

#endif // SMARTT_SIMPLE_CONNECTION_H