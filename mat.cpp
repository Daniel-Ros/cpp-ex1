#include "mat.hpp"

#include <iostream>
#include <stdexcept>
namespace ariel
{
    
    const char SMALL_BOUND = 33;     //userd to bound the symbols in the [33,126] range
    const char BIG_BOUND = 126;
    
    std::string mat(int columns,int rows,char sys1,char sys2)
    {      
        // Error checking
        if((columns % 2 != 1 ) || (rows % 2 != 1))
        {
            throw std::invalid_argument("Mat size is always odd");
        }

        if(columns < 1 || rows < 1)
        {
            throw std::out_of_range("size should be positive!");
        }

        if(sys1 < SMALL_BOUND || sys2 < SMALL_BOUND || sys1 > BIG_BOUND || sys2 > BIG_BOUND)
        {
            throw std::invalid_argument("Char should not be special character");
        }
        
        std::string ret; // output string

        /**
         * @brief Simple algorithm to draw the carpet.
         * for every entery in out carpet we caculate 4 parameters 
         * - i
         * - j
         * - k = columns - (j + 1) [the +1 is becuse we start our count from 0 and not 1]
         * - l = rows - (i +1)
         * 
         * printing each entery with the  the minimum between i,j indexs gives us (on a 3x3 example):
         * 000
         * 011
         * 012   
         * 
         * printing each entery with the  the minimum between k,l indexs gives us:
         * 210
         * 110
         * 000
         * 
         * taking the minimum of those two matricies gives us:
         * 000 
         * 010
         * 000
         * 
         * when we use the mod operation on each enetry, we can use that to know if we need to put the first or second symbol
         */
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                int pos1 = (int)std::min(i,j);
                int pos2 = (int)std::min(rows-(i + 1),columns- (j + 1));
                int pos = std::min(pos1,pos2);
                if(pos % 2 == 1)
                {
                    ret+= sys2;
                }
                else
                {
                    ret += sys1;
                }
            }
            ret += "\n";
        }
        
        return ret;
    }
} // namespace ariel
