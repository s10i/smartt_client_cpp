/*
    Smartt C++ Client
    Copyright 2013 S10I (s10i.com.br)

    Author: Felipe Menezes Machado (felipe@s10i.com.br)
*/
#ifndef SMARTT_CLIENT_H
#define SMARTT_CLIENT_H

// Standard library dependencies
#include <exception>
#include <string>
#include <vector>
#include <map>

using namespace std;

// External dependencies
#include <jsoncpp/json/json.h>

// Local dependencies
#include "smartt_simple_connection.h"
#include "parameter_list.h"

// Convenience include (so that client code doesn't need to do it)
#include "smartt_term.h"


/*************************************************************************************************
  Smartt Client Exception class
*************************************************************************************************/
class SmarttClientException: public std::exception
{
    string error_description_;

public:
    SmarttClientException(const string &error_description);

    ~SmarttClientException() throw ();

    virtual const char* what() const throw();
};



/*************************************************************************************************
  Smartt Client class
    An interface to the Smartt Server API. Connects to the server and communicates
    using the Smartt Simple Protocol.
*************************************************************************************************/
// Class constants
#define DEFAULT_SMARTT_CLIENT_CONNECT true
#define DEFAULT_SMARTT_CLIENT_HOST "smartt.s10i.com.br"
#define DEFAULT_SMARTT_CLIENT_PORT 5060
#define DEFAULT_SMARTT_CLIENT_USE_SSL true

// Class declaration
class SmarttClient {

public:

    // Constructor
    SmarttClient(const string &host = DEFAULT_SMARTT_CLIENT_HOST,
                 const int port = DEFAULT_SMARTT_CLIENT_PORT,
                 const bool use_ssl = DEFAULT_SMARTT_CLIENT_USE_SSL,
                 const bool connect_on_init = DEFAULT_SMARTT_CLIENT_CONNECT);

    // Connects to the Smartt server
    void connect();

    // Disconnects from the Smartt server
    void disconnect();

    // Sends a message using the Smartt Protocol
    vector<string> sendMessage(const vector<string> &message);

    // Sends a raw message using the underlying socket
    string sendRawMessage(const string &message);

    // Smartt functions

    #include "smartt_client_gen.h"

private:

    // Executes a smartt function by sending the given message to the server
    // and retrieving the response
    vector<string> smarttFunction(const vector<string> &message);

    // The connection with the Smartt server
    SmarttSimpleConnection smartt_simple_connection_;

};

#endif // SMARTT_CLIENT_H
