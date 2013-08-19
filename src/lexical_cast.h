/*
    S10I Smartt
    Autor: Gabriel Poesia
 */

#ifndef LEXICAL_CAST_H
#define LEXICAL_CAST_H

#include <string>
#include <sstream>

template <typename T>
T lexical_cast(std::string s) {
    T returnValue;
    istringstream iss(s);
    iss >> returnValue;
    return returnValue;
}

template <>
std::string lexical_cast(std::string s) {
    return s;
}

#endif
