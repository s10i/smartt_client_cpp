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

// Local dependencies
#include "smartt_simple_connection.h"


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
    string login(const string &username, const string &password);
    string logout();
    string logged();

    map<string,string> getClient(const vector<string> &attributes = vector<string>());
    string getTime();
    map<string,string> getStock(const string &stock_code, const string &market_name = string(), const vector<string> &attributes = vector<string>());

    string sendOrder(const string &investment_code = string(), 
                     const unsigned int brokerage_id = -1,
                     const bool &order_type = true,
                     const string &stock_code = string(),
                     const string &market_name = string(),
                     const unsigned int number_of_stocks = -1,
                     const float price = -1.0,
                     const string &validity_type = string(),
                     const string &validity = string());

    bool changeOrder(const string &order_id,
                     const unsigned int new_number_of_stocks = -1,
                     const float new_price = -1.0);

    bool cancelOrder(const string &order_id);

    string sendStopOrder(const string &investment_code = string(), 
                         const unsigned int brokerage_id = -1,
                         const bool order_type = true,
                         const bool stop_order_type = true,
                         const string &stock_code = string(),
                         const string &market_name = string(),
                         const unsigned int number_of_stocks = -1,
                         const float stop_price = -1.0,
                         const float limit_price = -1.0,
                         const string &validity = string(),
                         const bool valid_after_market = false);

    bool cancelStopOrder(const string &stop_order_id);

    vector< map<string,string> > getOrders(const string &order_id = string(), const string &investment_code = string(), const unsigned int brokerage_id = -1, const string &initial_datetime = string(), const string &final_datetime = string(), const string &status = string(), const vector<string> &attributes = vector<string>());
    vector< map<string,string> > getOrdersEvents(const string &order_id = string(), const string &investment_code = string(), const unsigned int brokerage_id = -1, const string &initial_datetime = string(), const string &final_datetime = string(), const string &event_type = string(), const vector<string> &attributes = vector<string>());
    vector< map<string,string> > getStopOrders(const string &order_id = string(), const string &investment_code = string(), const unsigned int brokerage_id = -1, const string &initial_datetime = string(), const string &final_datetime = string(), const string &status = string(), const vector<string> &attributes = vector<string>());
    vector< map<string,string> > getStopOrdersEvents(const string &order_id = string(), const string &investment_code = string(), const unsigned int brokerage_id = -1, const string &initial_datetime = string(), const string &final_datetime = string(), const string &event_type = string(), const vector<string> &attributes = vector<string>());
    vector< map<string,string> > getTrades(const string &order_id = string(), const string &investment_code = string(), const unsigned int brokerage_id = -1, const string &initial_datetime = string(), const string &final_datetime = string(), const vector<string> &attributes = vector<string>());
    vector< map<string,string> > getPortfolio(const string &investment_code = string(), const unsigned int brokerage_id = -1, const vector<string> &attributes = vector<string>());
    vector< map<string,string> > getAvailableLimits(const string &investment_code = string(), const unsigned int brokerage_id = -1, const vector<string> &attributes = vector<string>());

private:

    // Executes a smartt function by sending the given message to the server
    // and retrieving the response
    vector<string> smarttFunction(const vector<string> &message);

    // The connection with the Smartt server
    SmarttSimpleConnection smartt_simple_connection_;

};

#endif // SMARTT_CLIENT_H