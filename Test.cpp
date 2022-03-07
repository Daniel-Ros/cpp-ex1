/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Daniel
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>


/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
std::string nospaces(std::string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

int numOfSymbol(std::string str,char c){
    return std::count(str.begin(),str.end(),c);
}

TEST_CASE("Good input"){
    SUBCASE("small input"){
        //sainity check 
        CHECK(nospaces(mat(1,1, '@', '-')) == "@");
        CHECK(nospaces(mat(1, 7, '@', '-')) == "@@@@@@@");
        CHECK(nospaces(mat(7, 1, '@', '-')) == "@@@@@@@");
    }
    

    //some problmes we can manually inspect
    SUBCASE("large input"){
        CHECK(mat(3,5,'$','+') == "$$$\n"
                                  "$+$\n"
                                  "$+$\n"
                                  "$+$\n"
                                  "$$$\n");

        CHECK(mat(5,3,'$','+') == "$$$$$\n"
                                  "$+++$\n"
                                  "$$$$$\n");

        CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                        "@-------@\n"
                                                        "@-@@@@@-@\n"
                                                        "@-@---@-@\n"
                                                        "@-@@@@@-@\n"
                                                        "@-------@\n"
                                                        "@@@@@@@@@"));

        CHECK(nospaces(mat(9, 9, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                        "@-------@\n"
                                                        "@-@@@@@-@\n"
                                                        "@-@---@-@\n"
                                                        "@-@-@-@-@\n"
                                                        "@-@---@-@\n"
                                                        "@-@@@@@-@\n"
                                                        "@-------@\n"
                                                        "@@@@@@@@@"));
    }


    SUBCASE("huge input"){
        //Lets check that we are on the right output size
        CHECK(mat(101,101,'1','1').length() == 102*101);

        // The mat should me symetrical pon the horizontal axis
        std::string res = nospaces(mat(101,101,'!','@'));
        for (size_t i = 0; i < 50; i++)
        {
            CHECK(res.substr(i*101,101) == res.substr((res.length()-(101*(i+1))),101));
        }

        for (size_t i = 2; i < 50; i+=2)
        {
            int dnum1 = numOfSymbol(res.substr((i-2)*101,101),'!');
            int num1 = numOfSymbol(res.substr(i*101,101),'!');
            int dnum2 = numOfSymbol(res.substr((i-1)*101,101),'@');
            int num2 = numOfSymbol(res.substr((i+1)*101,101),'@');

            CHECK(num1 + 2 == dnum1);
            CHECK(num2 + 2 == dnum2);
  


        }

        // check to see that the character does not influance the final resualt
        std::string res2 = nospaces(mat(101,101,'^','$'));
        std::replace(res2.begin(),res2.end(),'$','@');
        std::replace(res2.begin(),res2.end(),'^','!');
        for (size_t i = 0; i < 50; i++)
        {
            CHECK(res.substr(i*101,101) == res.substr((res2.length()-(101*(i+1))),101));
        }
    }
}

TEST_CASE("Bad input") {
    SUBCASE("bad rows/columns"){
        CHECK_THROWS(mat(10, 5, '$', '%'));
        CHECK_THROWS(mat(5, 10, '$', '%'));
        CHECK_THROWS(mat(-1, 5, '$', '%'));
        CHECK_THROWS(mat(5, -1, '$', '%'));
    }
    
    
    SUBCASE("bad char"){
        for (size_t i = 0; i < 32; i++)
        {
            CHECK_THROWS(mat(7,5, i, '%'));
            CHECK_THROWS(mat(7,5, '^', i));
        }
        
    }
}

