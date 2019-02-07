#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

class NoNameException : public std::exception
{
public:
    NoNameException() noexcept;
    NoNameException(std::string str) noexcept;
    ~NoNameException();
};

#endif // !EXCEPTION_H



