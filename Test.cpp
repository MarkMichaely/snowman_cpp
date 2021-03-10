/**
 * unit test of snowman.cpp
 * 
 * 
 *
 * AUTHORS: <Mark Michaely>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

//#include <boost/algorithm/string.hpp>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	input.erase(std::remove(input.begin(),input.end(), ' '),input.end());
    input.erase(std::remove(input.begin(),input.end(), '\t'),input.end());
    input.erase(std::remove(input.begin(),input.end(), '\n'),input.end());
    input.erase(std::remove(input.begin(),input.end(), '\r'),input.end());
    // std::erase(input, ' ');
	// std::erase(input, '\t');
	// std::erase(input, '\n');
	// std::erase(input, '\r');
	return input;
}

/**
 * The following test cases will be for good snowman input, 
 * checking every possible body part    
 * so one can be sure it could be correctly created.
 */

TEST_CASE("Good snowman hat code") {
    CHECK(nospaces(snowman(11111111)) == nospaces("     \n _===_ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(21111111)) == nospaces(" ___ \n ..... \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(31111111)) == nospaces("  _  \n  /_\\ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(41111111)) == nospaces(" ___ \n (_*_) \n (.,.) \n<( : )>\n ( : ) "));
    
}

TEST_CASE("Good snowman nose code") {
    CHECK(nospaces(snowman(12111111)) == nospaces("_===_ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(13111111)) == nospaces("_===_ \n (...) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_ \n (._.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(14111111)) == nospaces("_===_ \n (. .) \n<( : )>\n ( : ) "));
    
}

TEST_CASE("Good snowman left eye code") {
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(11211111)) == nospaces("_===_ \n (o,.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(11311111)) == nospaces("_===_ \n (O,.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(11411111)) == nospaces("_===_ \n (-,.) \n<( : )>\n ( : ) "));
}

TEST_CASE("Good snowman right eye code") {
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(11121111)) == nospaces("_===_ \n (.,o) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(11131111)) == nospaces("_===_ \n (.,O) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(11141111)) == nospaces("_===_ \n (.,-) \n<( : )>\n ( : ) "));
}

TEST_CASE("Good snowman left arm code") {
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(11112111)) == nospaces("_===_ \n (.,.) \n( : )>\n ( : ) "));
    CHECK(nospaces(snowman(11113111)) == nospaces("_===_ \n \\(.,.) \n/( : )>\n ( : ) "));
    CHECK(nospaces(snowman(11114111)) == nospaces("_===_ \n (.,.) \n( : )>\n ( : ) "));
}

TEST_CASE("Good snowman right arm code") {
    CHECK(nospaces(snowman(11111211)) == nospaces("_===_ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(11111311)) == nospaces("_===_ \n (.,.)/ \n<( : )\n ( : ) "));
    CHECK(nospaces(snowman(11111411)) == nospaces("_===_ \n (.,.) \n<( : )\\ \n ( : ) "));
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_ \n (.,.) \n<( : )\n ( : ) "));
}

TEST_CASE("Good snowman torso code") {
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(11111121)) == nospaces("_===_ \n (.,.) \n<(] [)>\n ( : ) "));
    CHECK(nospaces(snowman(11111131)) == nospaces("_===_ \n (.,.) \n<(> <)>\n ( : ) "));
    CHECK(nospaces(snowman(11111141)) == nospaces("_===_ \n (.,.) \n<(   )>\n ( : ) "));
}

TEST_CASE("Good snowman body code") {
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(11111112)) == nospaces("_===_ \n (.,.) \n<( : )>\n (" ") "));
    CHECK(nospaces(snowman(11111113)) == nospaces("_===_ \n (.,.) \n<( : )>\n (___) "));
    CHECK(nospaces(snowman(11111114)) == nospaces("_===_ \n (.,.) \n<( : )>\n (   ) "));
}


/**
 * The following test cases will be for bad snowman input, 
 */
TEST_CASE("number too short") {
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(11));
    CHECK_THROWS(snowman(111));
    CHECK_THROWS(snowman(1111));
    CHECK_THROWS(snowman(11111));
    CHECK_THROWS(snowman(111111));
    CHECK_THROWS(snowman(1111111));
}

TEST_CASE("number too long") {
    CHECK_THROWS(snowman(1111111111));
    CHECK_THROWS(snowman(111234111));
    CHECK_THROWS(snowman(112341111));
    CHECK_THROWS(snowman(1143112311));
}

TEST_CASE("number digits out of range") {
    CHECK_THROWS(snowman(51111112));
    CHECK_THROWS(snowman(15111112));
    CHECK_THROWS(snowman(11511112));
    CHECK_THROWS(snowman(11151112));
    CHECK_THROWS(snowman(11115112));
    CHECK_THROWS(snowman(11111512));
    CHECK_THROWS(snowman(11111152));
    CHECK_THROWS(snowman(11111115));
}

/* Add more test cases here */
