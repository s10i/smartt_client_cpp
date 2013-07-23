/*
    Smartt C++ Client
    Copyright 2013 S10I (s10i.com.br)

    Author: Felipe Menezes Machado (felipe@s10i.com.br)
*/

#include "smartt_client.h"

#include <algorithm>
#include <sstream>
#include <iomanip>

/*************************************************************************************************
  SmarttClientException implementation
*************************************************************************************************/
SmarttClientException::SmarttClientException(const string &error_description) {
    error_description_ = error_description;
}

SmarttClientException::~SmarttClientException() throw () {}

const char* SmarttClientException::what() const throw()
{
    return ("Smartt Client Error: " + error_description_).c_str();
}


/*************************************************************************************************
  SmarttClient implementation
*************************************************************************************************/
SmarttClient::SmarttClient(const string &host, const int port, const bool use_ssl, const bool connect_on_init)
        try: smartt_simple_connection_(host, port, use_ssl)
{
    if( connect_on_init ) {
        connect();
    }
}
catch(SmarttSocketException &socket_exception)
{
    throw SmarttClientException(socket_exception.what());
}

void SmarttClient::connect() {
    // Just delegates to the underlying connection object
    try {
        smartt_simple_connection_.connect();
    }
    catch(SmarttSocketException &socket_exception)
    {
        throw SmarttClientException(socket_exception.what());
    }
}

void SmarttClient::disconnect() {
    // Just delegates to the underlying connection object
    try {
        smartt_simple_connection_.disconnect();
    }
    catch(SmarttSocketException &socket_exception)
    {
        throw SmarttClientException(socket_exception.what());
    }
}

vector<string> SmarttClient::smarttFunction(const vector<string> &message) {
    // A Smartt function is the act of sending a message, and receiving another as its
    // response. The first token in the message is the name of the function, the others
    // are its parameters.
    vector<string> response = sendMessage(message);

    // Check for responses that are errors from the server
    if (response.size() > 0 && response[0] == "ERROR")
    {
        throw SmarttClientException("Function '" + message[0] + "' error: " + response[1]);
    }

    return response;
}

vector<string> SmarttClient::sendMessage(const vector<string> &message) {
    try {
        smartt_simple_connection_.sendMessage(message);

        return smartt_simple_connection_.receiveMessage();
    }
    catch(SmarttSocketException &socket_exception)
    {
        throw SmarttClientException(socket_exception.what());
    }
}

string SmarttClient::sendRawMessage(const string &message) {
    try {
        smartt_simple_connection_.sendRawMessage(message);

        return smartt_simple_connection_.receiveRawMessage();
    }
    catch(SmarttSocketException &socket_exception)
    {
        throw SmarttClientException(socket_exception.what());
    }
}

/*****************************************************************************
    Smartt message building helpers
*****************************************************************************/
void appendStringParameter(vector<string> &message, const string &parameter_name, const string &parameter_value, bool optional = true) {
    if (parameter_value == "")
    {
        if(!optional) {
            throw SmarttClientException("Parameter '" + parameter_name + "' can't be empty!");
        }
    }
    else
    {
        message.push_back( parameter_name + "=" + parameter_value );
    }
}

void appendUnsignedIntegerParameter(vector<string> &message, const string &parameter_name, const unsigned int parameter_value, bool optional = true) {
    ostringstream ss;
    ss << parameter_value;
    string stringValue = ss.str();

    if (parameter_value == 0 || parameter_value == (unsigned int)-1)
    {
        if(!optional) {
            throw SmarttClientException("Invalid parameter '" + parameter_name + "' value: " + stringValue);
        }
    }
    else
    {
        message.push_back( parameter_name + "=" + stringValue );
    }
}

void appendFloatParameter(vector<string> &message, const string &parameter_name, const double parameter_value, bool optional = true) {
    ostringstream ss;
    ss << setiosflags(ios::fixed) << setprecision(2) << parameter_value;
    string stringValue = ss.str();

    if (parameter_value < 0.0)
    {
        if(!optional) {
            throw SmarttClientException("Invalid parameter '" + parameter_name + "' value: " + stringValue);
        }
    }
    else
    {
        message.push_back( parameter_name + "=" + stringValue );
    }
}

void appendBooleanParameter(vector<string> &message, const string &parameter_name, const bool parameter_value) {
    message.push_back( parameter_name + "=" + string(parameter_value ? "1" : "0") );
}

void appendDateOrDatetimeParameter(vector<string> &message, const string &parameter_name, const string &parameter_value, const bool is_datetime = true, bool optional = true) {
    if (parameter_value == "")
    {
        if(!optional) {
            throw SmarttClientException("Parameter '" + parameter_name + "' can't be empty!");
        }
    }
    else
    {
        int year, month, day, hour, minute, second;
        int ret = sscanf(parameter_value.c_str(), "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

        if ( year > 3000 || year < 2000 || month < 1 || month > 12 || day < 1 || day > 31 || // Date or datetime
             (is_datetime && (ret != 6 || hour < 0 || hour > 24 || minute < 0 || minute > 59 || second < 0 || second > 59) ) ||
             (!is_datetime && ret != 3)
           )
        {
            throw SmarttClientException("Invalid parameter '" + parameter_name + "' datetime value (expected format: YYYY-MM-DD hh:mm:ss): " + parameter_value);
        }

        char datetimeString[128];
        if (is_datetime)
        {
            snprintf(datetimeString, 128, "%04d-%02d-%02d %02d:%02d:%02d", year, month, day, hour, minute, second);
        }
        else
        {
            snprintf(datetimeString, 128, "%04d-%02d-%02d", year, month, day);
        }
        message.push_back( parameter_name + "=" + string(datetimeString) );
    }
}

void appendDatetimeParameter(vector<string> &message, const string &parameter_name, const string &parameter_value, bool optional = true) {
    appendDateOrDatetimeParameter(message, parameter_name, parameter_value, true, optional);
}

void appendDateParameter(vector<string> &message, const string &parameter_name, const string &parameter_value) {
    appendDateOrDatetimeParameter(message, parameter_name, parameter_value, false, false);
}


void appendEnumParameter(vector<string> &message, const string &parameter_name, const string &parameter_value, const vector<string> &possible_values, bool optional = true) {
    if(parameter_value == "")
    {
        if (!optional)
        {
            throw SmarttClientException("Parameter '" + parameter_name + "' can't be empty!");
        }
    }
    else
    {
        if(find(possible_values.begin(), possible_values.end(), parameter_value) == possible_values.end())
        {
            throw SmarttClientException("Invalid value for parameter '" + parameter_name + "': " + parameter_value);
        }
        message.push_back( parameter_name + "=" + parameter_value );
    }
}

void appendAttributes(vector<string> &message, const vector<string> &attributes, const vector<string> &possible_values) {
    for (unsigned int i = 0; i < attributes.size(); ++i)
    {
        if (find(possible_values.begin(), possible_values.end(), attributes[i]) != possible_values.end())
        {
            message.push_back(attributes[i]);
        }
        else
        {
            throw SmarttClientException("Invalid attribute name: " + attributes[i]);
        }
    }
}

/*****************************************************************************
    Smartt messages response formatting helpers
*****************************************************************************/
map<string,string> formatMapResponseAtIndexes(const vector<string> &values, unsigned int values_start, unsigned int values_length, const vector<string> &parameter_attributes, const vector<string> &default_attributes) {
    const vector<string> attributes = (parameter_attributes.size() == 0 ? default_attributes : parameter_attributes);

    map<string,string> response;

    if (values_start+values_length > values.size() || values_length != attributes.size())
    {
        throw SmarttClientException("Invalid number of values received!");
    }

    for (unsigned int i = 0; i < values_length; ++i)
    {
        response[attributes[i]] = values[values_start+i];
    }

    return response;
}

map<string,string> formatMapResponse(const vector<string> &values, const vector<string> &parameter_attributes, const vector<string> &default_attributes) {
    return formatMapResponseAtIndexes(values, 0, values.size(), parameter_attributes, default_attributes);
}

vector< map<string,string> > formatListOfMapsResponse(const vector<string> &values, int values_start, unsigned int values_length, const vector<string> &parameter_attributes, const vector<string> &default_attributes) {
    const vector<string> attributes = (parameter_attributes.size() == 0 ? default_attributes : parameter_attributes);

    if (values_length % attributes.size() != 0)
    {
        throw SmarttClientException("Invalid number of values received!");
    }

    vector< map<string,string> > response;

    for (unsigned int i = values_start; i < values_length; i += attributes.size())
    {
        response.push_back( formatMapResponseAtIndexes(values, i, attributes.size(), attributes, default_attributes) );
    }

    return response;
}

vector< map<string,string> > formatListOfMapsResponse(const vector<string> &values, const vector<string> &parameter_attributes, const vector<string> &default_attributes) {
    return formatListOfMapsResponse(values, 0, values.size(), parameter_attributes, default_attributes);
}

/*****************************************************************************
    Smartt messages attributes lists
*****************************************************************************/
vector<string> get_client_attributes = {
    "natural_person_or_legal_person",
    "name_or_corporate_name",
    "gender",
    "document",
    "email",
    "s10i_login",
    "address",
    "number",
    "complement",
    "neighborhood",
    "postal_code",
    "city",
    "state",
    "country",
    "birthday",
    "main_phone",
    "secondary_phone",
    "company"
};

vector<string> get_stock_attributes = {
    "stock_code",
    "market_name",
    "company_name",
    "kind_of_stock",
    "isin_code",
    "trading_lot_size",
    "kind_of_quotation",
    "type",
    "code_underlying_stock",
    "exercise_price",
    "expiration_date"
};

vector<string> get_orders_attributes = {
    "order_id",
    "order_id_in_brokerage",
    "investment_code",
    "brokerage_id",
    "is_real",
    "order_type",
    "stock_code",
    "market_name",
    "datetime",
    "number_of_stocks",
    "price",
    "financial_volume",
    "validity_type",
    "validity",
    "number_of_traded_stocks",
    "average_nominal_price",
    "status",
    "absolute_brokerage_tax_cost",
    "percentual_brokerage_tax_cost",
    "iss_tax_cost"
};

vector<string> get_orders_events_attributes = {
    "order_id",
    "investment_code",
    "brokerage_id",
    "number_of_events",
    "datetime",
    "event_type",
    "description"
};

vector<string> get_stop_orders_attributes = {
    "stop_order_id",
    "stop_order_id_in_brokerage",
    "investment_code",
    "brokerage_id",
    "is_real",
    "order_type",
    "stop_order_type",
    "stock_code",
    "market_name",
    "datetime",
    "number_of_stocks",
    "stop_price",
    "limit_price",
    "financial_volume",
    "validity",
    "valid_after_market",
    "status",
    "sent_order_id"
};

vector<string> get_stop_orders_events_attributes = {
    "stop_order_id",
    "investment_code",
    "brokerage_id",
    "number_of_events",
    "datetime",
    "event_type",
    "description"
};

vector<string> get_trades_attributes = {
    "order_id",
    "trade_id_in_brokerage",
    "investment_code",
    "brokerage_id",
    "is_real",
    "trade_type",
    "stock_code",
    "market_name",
    "datetime",
    "number_of_stocks",
    "price",
    "financial_volume",
    "trading_tax_cost",
    "liquidation_tax_cost",
    "register_tax_cost",
    "income_tax_cost",
    "withholding_income_tax_cost",
    "other_taxes_cost"
};

vector<string> get_portfolio_attributes = {
    "stock_code",
    "number_of_stocks",
    "position_type",
    "average_price",
    "financial_volume"
};

vector<string> get_available_limits_attributes = {
    "spot_limit",
    "option_limit",
    "margin_limit"
};

/*****************************************************************************
    Smartt messages enum parameters
*****************************************************************************/
vector<string> market_names = {
    "Bovespa",
    "BMF"
};

vector<string> order_statuses = {
    "canceled",
    "executed",
    "hung",
    "hung_cancellable",
    "hung_pending",
    "partially_canceled",
    "partially_executed",
    "partially_executed_cancellable",
    "rejected",
    "expired"
};

vector<string> order_event_types = {
    "order_sent",
    "order_canceled",
    "order_changed",
    "order_executed",
    "order_expired"
};

vector<string> stop_order_statuses = {
    "canceled_by_client",
    "canceled_expired_option",
    "canceled_not_allowed_market",
    "canceled_not_enough_balance",
    "canceled_not_positioned",
    "canceled_order_limit_exceeded",
    "hung",
    "sent",
    "expired"
};

vector<string> stop_order_event_types = {
    "stop_order_sent",
    "stop_order_canceled",
    "stop_order_triggered",
    "stop_order_expired"
};

vector<string> validity_types = {
    "HJ",
    "DE",
    "AC"
};

/*****************************************************************************
    Smartt functions
*****************************************************************************/
string SmarttClient::login(const string &username, const string &password) {
    vector<string> message;

    message.push_back("login");

    appendStringParameter(message, "s10i_login", username);
    appendStringParameter(message, "s10i_password", password);

    vector<string> response = smarttFunction(message);
    if (response.size() == 1)
    {
        return response[0];
    } else {
        throw SmarttClientException("Invalid response for 'login'");
    }
}

string SmarttClient::logout() {
    vector<string> message;

    message.push_back("logout");

    vector<string> response = smarttFunction(message);
    if (response.size() == 1)
    {
        return response[0];
    } else {
        throw SmarttClientException("Invalid response for 'logout'");
    }
}

string SmarttClient::logged() {
    vector<string> message;

    message.push_back("logged");

    vector<string> response = smarttFunction(message);
    if (response.size() == 1)
    {
        return response[0];
    } else {
        throw SmarttClientException("Invalid response for 'logged'");
    }
}

map<string,string> SmarttClient::getClient(const vector<string> &attributes) {
    vector<string> message;

    message.push_back("get_client");

    appendAttributes(message, attributes, get_client_attributes);

    vector<string> response = smarttFunction(message);

    return formatMapResponse(response, attributes, get_client_attributes);
}

string SmarttClient::getTime() {
    vector<string> message;

    message.push_back("get_time");

    vector<string> response = smarttFunction(message);
    if (response.size() == 1)
    {
        return response[0];
    } else {
        throw SmarttClientException("Invalid response for 'get_time'");
    }
}

map<string,string> SmarttClient::getStock(const string &stock_code, const string &market_name, const vector<string> &attributes) {
    vector<string> message;

    message.push_back("get_stock");

    appendStringParameter(message, "stock_code", stock_code, false);
    appendEnumParameter(message, "market_name", market_name, market_names);
    appendAttributes(message, attributes, get_stock_attributes);

    vector<string> response = smarttFunction(message);

    return formatMapResponse(response, attributes, get_stock_attributes);
}

string SmarttClient::sendOrder(const string &investment_code, const unsigned int brokerage_id, const bool &order_type, const string &stock_code, const string &market_name, const unsigned int number_of_stocks, const float price, const string &validity_type, const string &validity) {
    vector<string> message;

    message.push_back("send_order");

    appendStringParameter(message, "investment_code", investment_code, false);
    appendUnsignedIntegerParameter(message, "brokerage_id",  brokerage_id, true);
    appendBooleanParameter(message, "order_type", order_type);
    appendStringParameter(message, "stock_code", stock_code, false);
    appendEnumParameter(message, "market_name", market_name, market_names);
    appendUnsignedIntegerParameter(message, "number_of_stocks", number_of_stocks, false);
    appendFloatParameter(message, "price", price, false);
    appendEnumParameter(message, "validity_type", validity_type, validity_types);
    if (validity_type == "DE")
    {
        appendDateParameter(message, "validity", validity);
    }

    vector<string> response = smarttFunction(message);

    return response[1];
}

bool SmarttClient::cancelOrder(const string &order_id) {
    vector<string> message;

    message.push_back("cancel_order");

    appendStringParameter(message, "order_id", order_id, false);

    vector<string> response = smarttFunction(message);

    return true;
}

bool SmarttClient::changeOrder(const string &order_id, const unsigned int new_number_of_stocks, const float new_price) {
    vector<string> message;

    message.push_back("change_order");

    appendStringParameter(message, "order_id", order_id, false);
    appendUnsignedIntegerParameter(message, "new_number_of_stocks", new_number_of_stocks, true);
    appendFloatParameter(message, "new_price", new_price, true);

    vector<string> response = smarttFunction(message);

    return true;
}

string SmarttClient::sendStopOrder(const string &investment_code, const unsigned int brokerage_id, const bool order_type, const bool stop_order_type, const string &stock_code, const string &market_name, const unsigned int number_of_stocks, const float stop_price, const float limit_price, const string &validity, const bool valid_after_market) {
    vector<string> message;

    message.push_back("send_stop_order");

    appendStringParameter(message, "investment_code", investment_code, false);
    appendUnsignedIntegerParameter(message, "brokerage_id",  brokerage_id, true);
    appendBooleanParameter(message, "order_type", order_type);
    appendBooleanParameter(message, "stop_order_type", stop_order_type);
    appendStringParameter(message, "stock_code", stock_code, false);
    appendEnumParameter(message, "market_name", market_name, market_names);
    appendUnsignedIntegerParameter(message, "number_of_stocks", number_of_stocks, false);
    appendFloatParameter(message, "stop_price", stop_price, false);
    appendFloatParameter(message, "limit_price", limit_price, false);
    appendDateParameter(message, "validity", validity);
    appendBooleanParameter(message, "valid_after_market", valid_after_market);

    vector<string> response = smarttFunction(message);

    return response[1];
}

bool SmarttClient::cancelStopOrder(const string &stop_order_id) {
    vector<string> message;

    message.push_back("cancel_stop_order");

    appendStringParameter(message, "stop_order_id", stop_order_id, false);

    vector<string> response = smarttFunction(message);

    return true;
}

vector< map<string,string> > SmarttClient::getOrders(const string &order_id, const string &investment_code, const unsigned int brokerage_id, const string &initial_datetime, const string &final_datetime, const string &status, const vector<string> &attributes) {
    vector<string> message;

    message.push_back("get_orders");

    appendStringParameter(message, "order_id", order_id);
    appendStringParameter(message, "investment_code", investment_code);
    appendUnsignedIntegerParameter(message, "brokerage_id",  brokerage_id, true);
    appendDatetimeParameter(message, "initial_datetime", initial_datetime);
    appendDatetimeParameter(message, "final_datetime", final_datetime);
    appendEnumParameter(message, "status", status, order_statuses);
    appendAttributes(message, attributes, get_orders_attributes);

    vector<string> response = smarttFunction(message);

    return formatListOfMapsResponse(response, attributes, get_orders_attributes);
}

vector< map<string,string> > SmarttClient::getOrdersEvents(const string &order_id, const string &investment_code, const unsigned int brokerage_id, const string &initial_datetime, const string &final_datetime, const string &event_type, const vector<string> &attributes) {
    vector<string> message;

    message.push_back("get_orders_events");

    appendStringParameter(message, "order_id", order_id);
    appendStringParameter(message, "investment_code", investment_code);
    appendUnsignedIntegerParameter(message, "brokerage_id",  brokerage_id, true);
    appendDatetimeParameter(message, "initial_datetime", initial_datetime);
    appendDatetimeParameter(message, "final_datetime", final_datetime);
    appendEnumParameter(message, "event_type", event_type, order_event_types);
    appendAttributes(message, attributes, get_orders_events_attributes);

    vector<string> response = smarttFunction(message);

    return formatListOfMapsResponse(response, attributes, get_orders_events_attributes);
}

vector< map<string,string> > SmarttClient::getStopOrders(const string &stop_order_id, const string &investment_code, const unsigned int brokerage_id, const string &initial_datetime, const string &final_datetime, const string &status, const vector<string> &attributes) {
    vector<string> message;

    message.push_back("get_stop_orders");

    appendStringParameter(message, "stop_order_id", stop_order_id);
    appendStringParameter(message, "investment_code", investment_code);
    appendUnsignedIntegerParameter(message, "brokerage_id",  brokerage_id, true);
    appendDatetimeParameter(message, "initial_datetime", initial_datetime);
    appendDatetimeParameter(message, "final_datetime", final_datetime);
    appendEnumParameter(message, "status", status, stop_order_statuses);
    appendAttributes(message, attributes, get_stop_orders_attributes);

    vector<string> response = smarttFunction(message);

    return formatListOfMapsResponse(response, attributes, get_stop_orders_attributes);
}

vector< map<string,string> > SmarttClient::getStopOrdersEvents(const string &stop_order_id, const string &investment_code, const unsigned int brokerage_id, const string &initial_datetime, const string &final_datetime, const string &event_type, const vector<string> &attributes) {
    vector<string> message;

    message.push_back("get_stop_orders_events");

    appendStringParameter(message, "stop_order_id", stop_order_id);
    appendStringParameter(message, "investment_code", investment_code);
    appendUnsignedIntegerParameter(message, "brokerage_id",  brokerage_id, true);
    appendDatetimeParameter(message, "initial_datetime", initial_datetime);
    appendDatetimeParameter(message, "final_datetime", final_datetime);
    appendEnumParameter(message, "event_type", event_type, stop_order_event_types);
    appendAttributes(message, attributes, get_stop_orders_events_attributes);

    vector<string> response = smarttFunction(message);

    return formatListOfMapsResponse(response, attributes, get_stop_orders_events_attributes);
}

vector< map<string,string> > SmarttClient::getTrades(const string &order_id, const string &investment_code, const unsigned int brokerage_id, const string &initial_datetime, const string &final_datetime, const vector<string> &attributes) {
    vector<string> message;

    message.push_back("get_trades");

    appendStringParameter(message, "order_id", order_id);
    appendStringParameter(message, "investment_code", investment_code);
    appendUnsignedIntegerParameter(message, "brokerage_id",  brokerage_id, true);
    appendDatetimeParameter(message, "initial_datetime", initial_datetime);
    appendDatetimeParameter(message, "final_datetime", final_datetime);
    appendAttributes(message, attributes, get_trades_attributes);

    vector<string> response = smarttFunction(message);

    return formatListOfMapsResponse(response, attributes, get_trades_attributes);
}

vector< map<string,string> > SmarttClient::getPortfolio(const string &investment_code, const unsigned int brokerage_id, const vector<string> &attributes) {
    vector<string> message;

    message.push_back("get_portfolio");

    appendStringParameter(message, "investment_code", investment_code);
    appendUnsignedIntegerParameter(message, "brokerage_id",  brokerage_id, true);
    appendAttributes(message, attributes, get_portfolio_attributes);

    vector<string> response = smarttFunction(message);

    return formatListOfMapsResponse(response, 2, response.size()-2, attributes, get_portfolio_attributes);
}

vector< map<string,string> > SmarttClient::getAvailableLimits(const string &investment_code, const unsigned int brokerage_id, const vector<string> &attributes) {
    vector<string> message;

    message.push_back("get_available_limits");

    appendStringParameter(message, "investment_code", investment_code);
    appendUnsignedIntegerParameter(message, "brokerage_id",  brokerage_id, true);
    appendAttributes(message, attributes, get_available_limits_attributes);

    vector<string> response = smarttFunction(message);

    return formatListOfMapsResponse(response, attributes, get_available_limits_attributes);
}

