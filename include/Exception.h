#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

/*
Simple class to create instances of exceptions with custom message
*/
class Exception
{
    std::string _msg{""};

public:
    Exception();
    Exception(std::string msg) : _msg{msg} {}

    std::string get_message() const { return _msg; }
};

#endif