/*
    Smartt C++ Client
    Copyright 2013 S10I (s10i.com.br)

    Author: Felipe Menezes Machado (felipe@s10i.com.br)
*/

#ifndef SMARTT_SOCKET_H
#define SMARTT_SOCKET_H

// Standard library dependencies
#include <exception>
#include <string>
#include <string.h>

// SSL dependencies
#include <openssl/ssl.h>
#include <openssl/err.h>

using namespace std;


/*************************************************************************************************
  Smartt Socket Exception class
*************************************************************************************************/
// Constants
#define SMARTT_SOCKET_EXCEPTION_SOCKET_INFO_STR_MAX 4096
#define SMARTT_SOCKET_EXCEPTION_ERRNO_STR_MAX       4096

// Class declaration
class SmarttSocketException: public std::exception
{
    string error_description_;
    string socket_info_;

    // Builds the socket tuple string consisted of the socket host and port: "(host,port)"
    string format_socket_info(const string &host, int port);

public:
    // Constructors
    SmarttSocketException(const string &error_description, const string &host, int port);

    SmarttSocketException(const string &error_description, int error_number, const string &host, int port);

    ~SmarttSocketException() throw ();

    virtual const char* what() const throw();
};


/*************************************************************************************************
  Smartt Socket class
    A socket connection to connect with the Smartt server
*************************************************************************************************/
class SmarttSocket {

public:

    // Constructor    
    SmarttSocket(const string &host, int port, bool use_ssl = true);

    void connect();
    void disconnect();

    void write(const string &message);
    string read();

    // Read until socket is exhausted of data
    string readUntilEmpty();

private:

    // Host address
    string host_;

    // Port to connect in the host
    int port_;

    // Socket identifier returned by the socket api
    int socket_id_;

    // -----------
    // SSL Stuff

    // Private static flag used only for SSL Library initialization
    static int ssl_library_init_;

    // SSL context of the socket
    SSL_CTX *ssl_context_;

    // SSL protocol handler
    SSL *ssl_;

    // Does this socket use SSL?
    bool use_ssl_;

    // Inits SSL for this socket
    void setupSSL();

};

#endif // SMARTT_SOCKET_H