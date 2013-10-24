#include "parameter_list.h"
#include <iostream>
#include <sstream>

const ParameterList ParameterList::EMPTY_LIST;

ParameterList::ParameterList()
{

}

ParameterList &ParameterList::operator()(const std::string &parameterName, std::string parameterValue)
{
    values_.push_back(make_pair(parameterName, parameterValue));
    return *this;
}

ParameterList &ParameterList::operator()(const std::string &parameterName, const char *parameterValue)
{
    values_.push_back(make_pair(parameterName, std::string(parameterValue)));
    return *this;
}

ParameterList &ParameterList::operator()(const std::string &parameterName, double parameterValue)
{
    std::ostringstream oss;
    oss << parameterValue;
    values_.push_back(std::make_pair(parameterName, oss.str()));
    return *this;
}

ParameterList &ParameterList::operator()(const std::string &parameterName, int parameterValue)
{
    std::ostringstream oss;
    oss << parameterValue;
    values_.push_back(std::make_pair(parameterName, oss.str()));
    return *this;
}

ParameterList &ParameterList::operator()(const std::string &parameterName, bool parameterValue)
{
    values_.push_back(std::make_pair(parameterName, parameterValue ? "true" : "false"));
    return *this;
}

size_t ParameterList::size() const
{
    return values_.size();
}

std::string ParameterList::parameterName(unsigned i) const
{
    return values_[i].first;
}

std::string ParameterList::parameterValue(unsigned i) const
{
    return values_[i].second;
}

