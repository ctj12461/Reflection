#include "stdafx.h"
#include "Exception.h"


NoNameException::NoNameException() noexcept {
}

NoNameException::NoNameException(std::string str) noexcept
    :
    exception(str.c_str())
{
}


NoNameException::~NoNameException(){
}
