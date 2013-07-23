/*
    Smartt C++ Client
    Copyright 2013 S10I (s10i.com.br)

    Author: Felipe Menezes Machado (felipe@s10i.com.br)
*/

#include "smartt_simple_connection.h"

/*************************************************************************************************
  SocketStream implementation
*************************************************************************************************/
SocketStream::SocketStream(SmarttSocket &socket) :
        socket_(socket)
{
}

string SocketStream::read() {
    return socket_.read();
}

void SocketStream::write(const string &data) {
    socket_.write(data);
}


/*************************************************************************************************
  SmarttSimpleConnection implementation
*************************************************************************************************/
SmarttSimpleConnection::SmarttSimpleConnection(const string &host, const int port, const bool use_ssl) :
        socket_(host, port, use_ssl),
        socket_stream_(socket_),
        smartt_simple_protocol_(socket_stream_)
{
}

void SmarttSimpleConnection::connect() {
    socket_.connect();
}

void SmarttSimpleConnection::disconnect() {
    socket_.disconnect();
}

void SmarttSimpleConnection::sendMessage(const vector<string> &message) {
    smartt_simple_protocol_.sendMessage(message);
}

vector<string> SmarttSimpleConnection::receiveMessage() {
    return smartt_simple_protocol_.receiveMessage();
}

void SmarttSimpleConnection::sendRawMessage(const string &message) {
    socket_.write(message);
}

string SmarttSimpleConnection::receiveRawMessage() {
    return socket_.readUntilEmpty();
}
