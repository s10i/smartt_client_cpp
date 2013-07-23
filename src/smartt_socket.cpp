/*
    Smartt C++ Client
    Copyright 2013 S10I (s10i.com.br)

    Author: Felipe Menezes Machado (felipe@s10i.com.br)
*/

#include "smartt_socket.h"

// Standard library dependencies
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <poll.h>

// Socket dependencies
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

// Internal constants
#define RECEIVE_BUFFER_SIZE 4096

/*************************************************************************************************
  Helper functions
*************************************************************************************************/
struct sockaddr_in dns_lookup(const string &host, int port) {
    // Setup hints
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Setup port string
    char port_string[128];
    sprintf(port_string, "%d", port);
    
    // Get address info
    struct addrinfo *result = NULL;
    int return_value = getaddrinfo(host.c_str(), port_string, &hints, &result);

    if (result == NULL)
    {
        throw (string("host name not found: ") + host);
    }
    if (return_value != 0) {
        throw (string("getaddrinfo error: ") + gai_strerror(return_value));
    }

    // Convert and retrieve return value
    struct sockaddr_in resolved_address = *((sockaddr_in*)result->ai_addr);

    freeaddrinfo(result);

    return resolved_address;
}

/*************************************************************************************************
  SSL functions
*************************************************************************************************/
int SSLInit()
{
    SSL_library_init();

    // Loads and register all crypto methods, ciphers, etc.
    OpenSSL_add_all_algorithms();
    // Loads all SSL error messages
    SSL_load_error_strings();

    return 0;
}

string getSSLErrorString(const string &prefix = "") {
    char error_string_buffer[4096];
    ERR_error_string_n(ERR_get_error(), error_string_buffer, 4096);

    if (prefix.size() > 0)
    {
        return prefix + ": " + string(error_string_buffer);
    }

    return string(error_string_buffer);
}

SSL_CTX* initSSLContext()
{
    // Client SSL method - it means we are a SSL client connecting to a SSL server
    const SSL_METHOD *method = SSLv3_client_method();

    // Creates a SSL context for the given method (client method in this case)
    SSL_CTX *ssl_context = SSL_CTX_new(method);
    
    if ( ssl_context != NULL )
    {
        // Set a secure cipher list
        SSL_CTX_set_cipher_list(ssl_context, "ECDHE-RSA-AES128-SHA256:AES128-GCM-SHA256:RC4:HIGH:!MD5:!aNULL:!EDH");
    }

    return ssl_context;
}

void checkCertificates(SSL* ssl)
{
    X509 *cert;
    char *line;
    
    cert = SSL_get_peer_certificate(ssl); /* Get certificates (if available) */
    if ( cert != NULL )
    {
        //printf("Server certificates:\n");
        line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
        //printf("Subject: %s\n", line);
        free(line);
        line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
        //printf("Issuer: %s\n", line);
        free(line);
        X509_free(cert);
    }
    else
    {
        // No certificates
    }
}


/*************************************************************************************************
  SmarttSocketException implementation
*************************************************************************************************/
string SmarttSocketException::format_socket_info(const string &host, int port) {
    char socket_info_string[SMARTT_SOCKET_EXCEPTION_SOCKET_INFO_STR_MAX];
    sprintf(socket_info_string, "(%s,%d)", host.c_str(), port);
    return string(socket_info_string);
}

SmarttSocketException::SmarttSocketException(const string &error_description, const string &host, int port) {
    // Build and store socket info and error description strings
    socket_info_ = format_socket_info(host, port);
    error_description_ = error_description;
}

SmarttSocketException::SmarttSocketException(const string &error_description, int error_number, const string &host, int port) {
    // Build and store socket info string
    socket_info_ = format_socket_info(host, port);

    // Translate 'errno' error code to a readable string and append to the error description
    char errno_string[SMARTT_SOCKET_EXCEPTION_ERRNO_STR_MAX];
    strerror_r(error_number, errno_string, SMARTT_SOCKET_EXCEPTION_ERRNO_STR_MAX);

    error_description_ = error_description + string(errno_string);
}

SmarttSocketException::~SmarttSocketException() throw () {}

const char* SmarttSocketException::what() const throw()
{
    return ("Smartt Socket Error (socket: " + socket_info_ + "): " + error_description_).c_str();
}


/*************************************************************************************************
  SmarttSocket implementation
*************************************************************************************************/
int SmarttSocket::ssl_library_init_ = SSLInit();

SmarttSocket::SmarttSocket(const string &host, const int port, bool use_ssl) {
    host_ = host;
    port_ = port;

    use_ssl_ = use_ssl;
    ssl_context_ = NULL;
    ssl_ = NULL;

    // Create IPV4, stream TCP socket
    socket_id_ = ::socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
    if (socket_id_ == -1)
    {
        throw SmarttSocketException("Error creating socket: ", errno, host_, port_);
    }
}

void SmarttSocket::connect() {
    if ( use_ssl_ )
    {
        ssl_context_ = ::initSSLContext();
        if (ssl_context_ == NULL)
        {
            throw SmarttSocketException(getSSLErrorString("Error creating SSL context"), host_, port_);
        }
    }

    // Setup socket address
    sockaddr_in socket_address;
    socket_address.sin_family = AF_INET; // IPV4 address
    socket_address.sin_port = htons( port_ ); // Convert to network byte order

    try {
        socket_address.sin_addr = ::dns_lookup( host_, port_ ).sin_addr; // Lookups host name (DNS)
    } catch (const string &error_string) {
        throw SmarttSocketException("Error connecting: "+error_string, host_, port_);   
    }

    if (::connect( socket_id_, ( sockaddr * ) &socket_address, sizeof( socket_address ) ) == -1)
    {
        throw SmarttSocketException("Error connecting: ", errno, host_, port_);
    }

    if (use_ssl_)
    {
        setupSSL();
    }
}

void SmarttSocket::disconnect() {
    int ret = ::shutdown(socket_id_, 2);
    if (ret == -1)
    {
        throw SmarttSocketException("Error disconnecting: ", errno, host_, port_);
    }
}

void SmarttSocket::write(const string &message) {
    int bytes_written = 0;
    if (use_ssl_)
    {
        bytes_written = ::SSL_write( ssl_, message.c_str(), message.size() );
    }
    else
    {
        bytes_written = ::send( socket_id_, message.c_str(), message.size(), 0 );
    }

    // Check for errors
    if (bytes_written == -1)
    {
        throw SmarttSocketException("Error sending data: ", errno, host_, port_);
    }
}

string SmarttSocket::read() {
    char buffer[RECEIVE_BUFFER_SIZE];

    int bytes_received = 0;
    if (use_ssl_)
    {
        bytes_received = ::SSL_read( ssl_, (void *)buffer, (size_t) (RECEIVE_BUFFER_SIZE-1) );
    }
    else
    {
        bytes_received = ::recv( socket_id_, (void *)buffer, (size_t) (RECEIVE_BUFFER_SIZE-1), 0 );
    }
    
    // Check for errors
    if (bytes_received == -1)
    {
        throw SmarttSocketException("Error receiving data: ", errno, host_, port_);
    } else {
        buffer[bytes_received] = 0;
        return string( buffer );
    }
}

string SmarttSocket::readUntilEmpty() {
    string data = read();

    struct pollfd polling_params;
    polling_params.fd = socket_id_;
    polling_params.events = POLLIN;

    while( poll(&polling_params, 1, 500) > 0 ) {
        data.append(read());
    }
    return data;
}

void SmarttSocket::setupSSL()
{
    if( !ssl_context_ ) {
        throw SmarttSocketException("Can't setup SSL: SSL Context is null!", host_, port_);
    }

    // Create the SSL handler
    ssl_ = SSL_new(ssl_context_);

    if (ssl_ == NULL)
    {
        throw SmarttSocketException(getSSLErrorString(), host_, port_);
    }

    // Sets the socket for the SSL handler
    if( SSL_set_fd(ssl_, socket_id_) == 0 ) {
        throw SmarttSocketException(getSSLErrorString(), host_, port_);
    }

    // Connects to the server issuing the SSL handshake
    if ( SSL_connect(ssl_) == -1 )
    {
        throw SmarttSocketException(getSSLErrorString(), host_, port_);
    }
    
    // Check server certificates
    checkCertificates(ssl_);
}
