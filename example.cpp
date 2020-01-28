#include "cppregex.h"
#include <iostream>
#include <string>

using string = std::string;

string myString;
string regex1;
string regex2;
string regex3;

int main(){

    // -- regex::match Examples --
    // Checks if a string matches a given regex.
    std::cout << "regex::match" << std::endl;

    myString = "Hi there! How are you? Hi!";
    regex1 = "(Hi)(.*)(you?)(.*)";
    regex2 = "Potato";
    regex3 = ".*H.. are you..*";

    std::cout << regex::match(myString, regex1) << std::endl; // matches
    std::cout << regex::match(myString, regex2) << std::endl; // doesn't match
    std::cout << regex::match(myString, regex3) << std::endl; // matches

    // -- regex::contains Examples --
    // Checks if a string contains a substring that matches
    // a given regex.
    std::cout << std::endl << "regex::contains" << std::endl;

    myString = "Hi there! How are you? Hi!";
    regex1 = "H.. are";
    regex2 = "\\!*";
    regex3 = "era";

    std::cout << regex::contains(myString, regex1) << std::endl; // contains
    std::cout << regex::contains(myString, regex2) << std::endl; // contains
    std::cout << regex::contains(myString, regex3) << std::endl; // doesn't contain



    // -- regex::index Examples --
    // Returns the position of the substring that matches the given regex,
    // -1 if none was found.
    std::cout << std::endl << "regex::index" << std::endl;

    myString = "You are using cppregex~!";
    regex1 = "c[p\\+]*regex";
    regex2 = "not found!";

    std::cout << regex::index(myString, regex1) << std::endl; // will print 14
    std::cout << regex::index(myString, regex2) << std::endl; // will print -1



    // -- regex::indices Examples --
    // returns a vector of ints containing all the positions of the
    // substrings that match the given regex. Empty if none was found.
    std::cout << std::endl << "regex::indices" << std::endl;

    myString = "Cppregex is awesome, don't you love c++regex?";
    regex1 = "[Cc][p\\+]*regex";

    std::cout << regex::indices(myString, regex1).size() << std::endl; // will print 2
    std::cout << regex::indices(myString, regex1)[0] << std::endl; // will print 0
    std::cout << regex::indices(myString, regex1)[1] << std::endl; // will print 36



    // -- regex::indexLength Examples --
    // returns the position of the substring that matches the given regex,
    // and its length. <-1, 0> if none was found.
    std::cout << std::endl << "regex::indexLength" << std::endl;

    myString = "You are using cppregex~!";
    regex1 = "c[p\\+]*regex";
    regex2 = "not found!";

    std::cout << regex::indexLength(myString, regex1).first << std::endl; // will print 14
    std::cout << regex::indexLength(myString, regex1).second << std::endl; // will print 8
    std::cout << regex::indexLength(myString, regex2).first << std::endl; // will print -1
    std::cout << regex::indexLength(myString, regex2).second << std::endl; // will print 0



    // -- regex::indicesLengths Examples --
    // returns a vector of pair<int, unsigned int> containing all the positions and lengths
    // of the substrings that match the given regex. Empty if none was found.
    std::cout << std::endl << "regex::indicesLengths" << std::endl;

    myString = "Cppregex is awesome, don't you love c+++regex?";
    regex1 = "[Cc][p\\+]*regex";

    std::cout << regex::indicesLengths(myString, regex1).size() << std::endl; // will print 2
    std::cout << regex::indicesLengths(myString, regex1)[0].first << std::endl; // will print 0
    std::cout << regex::indicesLengths(myString, regex1)[0].second << std::endl; // will print 8
    std::cout << regex::indicesLengths(myString, regex1)[1].first << std::endl; // will print 36
    std::cout << regex::indicesLengths(myString, regex1)[1].second << std::endl; // will print 9



    // -- regexSearch Examples --
    // returns the first substring in text that matches the passed regex.
    // Empty if the regex didn't match anything.
    std::cout << std::endl << "regexSearch" << std::endl;

    myString = "Cppregex is awesome, don't you love c++regex?";
    regex1 = "[Cc][p\\+]*regex";
    regex2 = "llama";

    std::cout << regex::search(myString, regex1) << std::endl; // will print Cppregex
    std::cout << regex::search(myString, regex2) << std::endl; // will print ""



    // -- regexSearchAll Examples --
    // returns a vector of strings containing all the substrings in text that
    // matched the passed regex. Empty if the regex didn't match anything.
    std::cout << std::endl << "regexSearchAll" << std::endl;

    myString = "Cppregex is awesome, don't you love c++regex? I love cpppppregex!";
    regex1 = "[Cc][p\\+]*regex";
    regex2 = "llama";

    std::cout << regex::searchAll(myString, regex1).size() << std::endl; // will print 3
    std::cout << regex::searchAll(myString, regex1)[0] << std::endl; // will print Cppregex
    std::cout << regex::searchAll(myString, regex1)[1] << std::endl; // will print c++regex
    std::cout << regex::searchAll(myString, regex1)[2] << std::endl; // will print cpppppregex
    std::cout << regex::searchAll(myString, regex2).size() << std::endl; // will print 0



    // -- regexBefore Examples --
    // returns all the text found before a regex match was found.
    // Empty if nothing matched the regex.
    std::cout << std::endl << "regexBefore" << std::endl;

    myString = "My llama is very fluffy!";
    regex1 = "llama";

    std::cout << regex::before(myString, regex1) << std::endl; // will print "My "



    // -- regexAfter Examples --
    // returns all the text found after a regex match was found.
    // Empty if nothing matched the regex.
    std::cout << std::endl << "regexAfter" << std::endl;

    myString = "My llama is very fluffy!";
    regex1 = "llama";

    std::cout << regex::after(myString, regex1) << std::endl; // will print " is very fluffy!"

    

    // -- regexReplace Examples --
    // returns a string with the first match of the regex in text replaced by newValue.
    std::cout << std::endl << "regexReplace" << std::endl;

    myString = "My llama is very fluffy! I love my llama!";
    regex1 = "(l*)(ama)";

    std::cout << regex::replace(myString, regex1, "cow") << std::endl;
    // will print "My cow is very fluffy! I love my llama!"

    // -- regexReplaceAll Examples --
    // returns a string with all matches of the regex in text replaced by newValue.
    std::cout << std::endl << "regexReplaceAll" << std::endl;

    myString = "My llama is very fluffy! I love my llama!";
    regex1 = "(l*)(ama)";

    std::cout << regex::replaceAll(myString, regex1, "cow") << std::endl;
    // will print "My cow is very fluffy! I love my cow!"

    return 0;
}
