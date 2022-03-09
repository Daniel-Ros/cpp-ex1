#include "mat.hpp"

#include <iostream>
#include <stdexcept>
namespace ariel
{
    const char BAD_CHAR = 32;

    std::string mat(int x,int y,char c1,char c2)
    {       
        std::cout << x << " " << y << std::endl;
        if(x % 2 == 0 || y % 2 == 0)
        {
            throw std::invalid_argument("Mat size is always odd");
        }

        if(x < 1 || y < 1)
        {
            throw std::invalid_argument("row/colums should be a positive number");
        }

        if(c1 < BAD_CHAR || c2 < BAD_CHAR)
        {
            throw std::invalid_argument("char should be a symbol( value > 32)");
        }
        return "test";
    }
} // namespace ariel
