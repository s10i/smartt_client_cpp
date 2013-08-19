/*
    Smartt C++ Client
    Copyright 2013 S10I (s10i.com.br)

    Author: Felipe Menezes Machado (felipe@s10i.com.br)
*/

#include "smartt_client.h"
#include "lexical_cast.h"

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

void appendCharParameter(vector<string> &message, const string &parameter_name, char parameter_value, bool optional = true) {
    if (parameter_value == 0)
    {
        if (!optional) {
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

void appendDateParameter(vector<string> &message, const string &parameter_name, const string &parameter_value, bool optional = false) {
    appendDateOrDatetimeParameter(message, parameter_name, parameter_value, false, optional);
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
/*
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

vector<string> get_client_brokerages_attributes = {
    "brokerage_id",
    "brokerage_login"
};

vector<string> get_investments_attributes = {
    "name",
    "code",
    "brokerage_id",
    "setup_code",
    "is_real",
    "initial_datetime",
    "final_datetime"
};

vector<string> get_report_attributes = {
    "investment_code",
    "brokerage_id",
    "setup_code",
    "initial_datetime",
    "final_datetime",
    "number_of_days"
};

vector<string> get_setups_attributes = {
    "name",
    "code",
    "initial_capital",
    "slippage",
    "absolute_brokerage_tax",
    "percentual_brokerage_tax",
    "position_trading_tax",
    "position_liquidation_tax"
}
*/

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

#include "smartt_client_gen.cpp"

