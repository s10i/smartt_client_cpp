/*
    Smartt C++ Client
    Copyright 2013 S10I (s10i.com.br)

    Author: Felipe Menezes Machado (felipe@s10i.com.br)
*/

#include "smartt_client.h"
#include "lexical_cast.h"
#include "parameter_list.h"

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

Json::Value formatMapResponseAsJson(const vector<string> &values,
                                    const vector<string> &parameter_attributes,
                                    const vector<string> &default_attributes)
{
    Json::Value response;

    vector<string> returned_attributes = parameter_attributes.size() ?
                                         parameter_attributes :
                                         default_attributes;

    for (unsigned i = 0; i < returned_attributes.size(); i++) {
        response[returned_attributes[i]] = values[i];
    }

    return response;
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

Json::Value formatListOfMapsResponseAsJson(const vector<string> &values,
                                           unsigned offset,
                                           unsigned values_length,
                                           const vector<string> &parameter_attributes,
                                           const vector<string> &default_attributes)
{
    vector<string> attributes = parameter_attributes.size() ?
                                parameter_attributes :
                                default_attributes;
    if (values_length % attributes.size())
        throw SmarttClientException("Invalid number of values received!");

    Json::Value response;

    for (unsigned i = 0; i < values_length / attributes.size(); i++) {
        Json::Value returnedObject;

        for (unsigned j = 0; j < attributes.size(); j++) {
            returnedObject[attributes[j]] = values[offset + i*attributes.size() + j];
        }

        response.append(returnedObject);
    }

    return response;
}


void appendParameterList(vector<string> &message, const ParameterList &request) {
    for (unsigned i = 0; i < request.size(); i++)
        message.push_back(request.parameterName(i) + "=" + request.parameterValue(i));
}

vector<string> findParameter(const ParameterList &request, string name) {
    for (unsigned i = 0; i < request.size(); i++)
        if (request.parameterName(i) == name) {
            vector<string> names;
            size_t next = string::npos;

            // split names on every ','
            do {
                size_t last = next;
                next = name.find_first_of(',', next+1);
                names.push_back(name.substr(last+1, next - (last+1)));
            } while (next != string::npos);

            return names;
        }
    return vector<string>();
}

/*****************************************************************************
    Smartt functions
*****************************************************************************/

#include "smartt_client_gen.cpp"

