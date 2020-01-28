#define CATCH_CONFIG_MAIN

#include "catch2.hpp"
#include "../cppregex.h"
#include <iostream>

using exception = std::exception;
using string = std::string;

string myString;
string regex1;
string regex2;
string regex3;

TEST_CASE("Regex match", "[match]") {
    try {
        myString = "Hi there! How are you? Hi!";
        regex1 = "(Hi)(.*)(you?)(.*)";
        regex2 = "Potato";
        regex3 = ".*H.. are you..*";

        REQUIRE(regex::match(myString, regex1) == 1);
        REQUIRE(regex::match(myString, regex2) == 0);
        REQUIRE(regex::match(myString, regex3) == 1);
    } catch(exception ex) {
        REQUIRE(false);
    }
}

TEST_CASE("Regex contains", "[contains]") {
    try {
        myString = "Hi there! How are you? Hi!";
        regex1 = "H.. are";
        regex2 = "\\!*";
        regex3 = "era";

        REQUIRE(regex::contains(myString, regex1));
        REQUIRE(regex::contains(myString, regex2));
        REQUIRE(!regex::contains(myString, regex3));
    } catch(exception ex) {
        REQUIRE(false);
    }
}

TEST_CASE("Regex index", "[index]") {
    try {
        myString = "You are using cppregex~!";
        regex1 = "c[p\\+]*regex";
        regex2 = "not found!";

        REQUIRE(regex::index(myString, regex1) == 14);
        REQUIRE(regex::index(myString, regex2) == -1);
    } catch(exception ex) {
        REQUIRE(false);
    }
}

TEST_CASE("Regex indices", "[indices]") {
    try {
        myString = "Cppregex is awesome, don't you love c++regex?";
        regex1 = "[Cc][p\\+]*regex";

        REQUIRE(regex::indices(myString, regex1).size() == 2);
        REQUIRE(regex::indices(myString, regex1)[0] == 0);
        REQUIRE(regex::indices(myString, regex1)[1] == 36);
    } catch(exception ex) {
        REQUIRE(false);
    }
}

TEST_CASE("Regex indexLength", "[indexLength]") {
    try {
        myString = "You are using cppregex~!";
        regex1 = "c[p\\+]*regex";
        regex2 = "not found!";

        REQUIRE(regex::indexLength(myString, regex1).first == 14);
        REQUIRE(regex::indexLength(myString, regex1).second == 8);
        REQUIRE(regex::indexLength(myString, regex2).first == -1);
        REQUIRE(regex::indexLength(myString, regex2).second == 0);
    } catch(exception ex) {
        REQUIRE(false);
    }
}

TEST_CASE("Regex indicesLength", "[indicesLength]") {
    try {
        myString = "Cppregex is awesome, don't you love c+++regex?";
        regex1 = "[Cc][p\\+]*regex";

        REQUIRE(regex::indicesLengths(myString, regex1).size() == 2);
        REQUIRE(regex::indicesLengths(myString, regex1)[0].first == 0);
        REQUIRE(regex::indicesLengths(myString, regex1)[0].second == 8);
        REQUIRE(regex::indicesLengths(myString, regex1)[1].first == 36);
        REQUIRE(regex::indicesLengths(myString, regex1)[1].second == 9);
    } catch(exception ex) {
        REQUIRE(false);
    }
}

TEST_CASE("Regex search", "[search]") {
    try {
        myString = "Cppregex is awesome, don't you love c++regex?";
        regex1 = "[Cc][p\\+]*regex";
        regex2 = "llama";

        REQUIRE(regex::search(myString, regex1) == "Cppregex");
        REQUIRE(regex::search(myString, regex2) == "");
    } catch(exception ex) {
        REQUIRE(false);
    }
}

TEST_CASE("Regex searchAll", "[searchAll]") {
    try {
        myString = "Cppregex is awesome, don't you love c++regex? I love cpppppregex!";
        regex1 = "[Cc][p\\+]*regex";
        regex2 = "llama";

        REQUIRE(regex::searchAll(myString, regex1).size() == 3);
        REQUIRE(regex::searchAll(myString, regex1)[0] == "Cppregex");
        REQUIRE(regex::searchAll(myString, regex1)[1] == "c++regex");
        REQUIRE(regex::searchAll(myString, regex1)[2] == "cpppppregex");
        REQUIRE(regex::searchAll(myString, regex2).size() == 0);
    } catch(exception ex) {
        REQUIRE(false);
    }
}

TEST_CASE("Regex before", "[before]") {
    try {
        myString = "My llama is very fluffy!";
        regex1 = "llama";

        REQUIRE(regex::before(myString, regex1) == "My ");
    } catch(exception ex) {
        REQUIRE(false);
    }
}

TEST_CASE("Regex after", "[after]") {
    try {
        myString = "My llama is very fluffy!";
        regex1 = "llama";

        REQUIRE(regex::after(myString, regex1) == " is very fluffy!");
    } catch(exception ex) {
        REQUIRE(false);
    }
}

TEST_CASE("Regex replace", "[replace]") {
    try {
        myString = "My llama is very fluffy! I love my llama!";
        regex1 = "(l*)(ama)";

        REQUIRE(regex::replace(myString, regex1, "cow") == "My cow is very fluffy! I love my llama!");
    } catch(exception ex) {
        REQUIRE(false);
    }
}

TEST_CASE("Regex replaceAll", "[replaceAll]") {
    try {
        myString = "My llama is very fluffy! I love my llama!";
        regex1 = "(l*)(ama)";

        REQUIRE(regex::replaceAll(myString, regex1, "cow") == "My cow is very fluffy! I love my cow!");
    } catch(exception ex) {
        REQUIRE(false);
    }
}