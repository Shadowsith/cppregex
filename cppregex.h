// +------------------------------------------------+
// | CPPREGEX C++ STD::REGEX WRAPPER LIBRARY        |
// |  by Martín del Río (github.com/lartu)          |
// |  edited by Philip Mayer (github.com/Shadowith) |
// +------------------------------------------------+
// |        Released under the MIT License          |
// |                  2019 - 2020                   |
// +------------------------------------------------+

#include <string>
#include <regex>
#include <vector>

namespace regex {

    /**
     * @brief Search for regex matches in string
     * 
     * @return bool
     */
    bool match(std::string _text, std::string _regex){
        std::regex _r(_regex);
        return std::regex_match(_text, _r);
    }

    /**
     * @brief returns if string contains regex
     * 
     * @return bool
     */
    bool contains(std::string _text, std::string _regex){
        std::regex _r(_regex);
        return std::regex_search(_text, _r);
    }

    /**
     * @brief returns index of substring that matches the given regex
     * 
     * @return int, position of substring or -1
     */
    int index(std::string _text, std::string _regex){
        std::smatch m;
        std::regex _r(_regex);
        std::regex_search(_text, m, _r);
        if(m.empty()) return -1;
        return m.position();
    }

    /**
     * @brief returns a vector of ints containing all the positions of the substrings 
     * that match the given regex. Empty if none was found.
     * 
     * @return std::vector<int> 
     */
    std::vector<int> indices(std::string _text, std::string _regex){
        std::regex _r(_regex);
        std::vector<int> ret;
        for(auto it = std::sregex_iterator(_text.begin(), _text.end(), _r); it != std::sregex_iterator(); ++it){
            ret.push_back(it->position());
        }
        return ret;
    }

    /**
     * @brief returns the position of the substring that matches the given regex, 
     * 
     * @return std::pair<int, unsigned int> (<-1, 0> if none was found) 
     */
    std::pair<int, unsigned int> indexLength(std::string _text, std::string _regex){
        std::smatch m;
        std::regex _r(_regex);
        std::regex_search(_text, m, _r);
        if(m.empty()) return std::make_pair(-1, 0);
        return std::make_pair(m.position(), m.length());
    }

    /**
     * @brief returns a vector of pair<int, unsigned int> containing all the positions and lengths.
     * Empty if none was found
     * 
     * @return std::vector<std::pair<int, unsigned int>>
     */
    std::vector<std::pair<int, unsigned int>> indicesLengths(std::string _text, std::string _regex){
        std::regex _r(_regex);
        std::vector<std::pair<int, unsigned int>> ret;
        for(auto it = std::sregex_iterator(_text.begin(), _text.end(), _r); it != std::sregex_iterator(); ++it){
            ret.push_back(std::make_pair(it->position(), it->length()));
        }
        return ret;
    }

    /**
     * @brief returns the first substring in text that matches the passed regex.
     * Empty string if the regex didn't match anything
     * 
     * @return std::string
     */
    std::string search(std::string _text, std::string _regex){
        std::smatch m;
        std::regex _r(_regex);
        std::regex_search(_text, m, _r);
        if(m.empty()) return "";
        return m.str();
    }

    /**
     * @brief returns a vector of strings containing all the substrings in text that
     * matched the passed regex. Empty if the regex didn't match anything.
     * 
     * @return std::vector\<std::string> 
     */
    std::vector<std::string> searchAll(std::string _text, std::string _regex){
        std::regex _r(_regex);
        std::vector<std::string> ret;
        for(auto it = std::sregex_iterator(_text.begin(), _text.end(), _r); it != std::sregex_iterator(); ++it){
            ret.push_back(it->str());
        }
        return ret;
    }


    /**
     * @brief returns all the text found before a regex match was found.
     * Empty if nothing matched the regex
     * 
     * @return std::string 
     */
    std::string before(std::string _text, std::string _regex){
        std::smatch m;
        std::regex _r(_regex);
        std::regex_search(_text, m, _r);
        if(m.empty()) return "";
        return m.prefix().str();
    }

    /**
     * @brief returns all the text found after a regex match was found.
     * Empty if nothing matched the regex.
     * 
     * @return std::string 
     */
    std::string after(std::string _text, std::string _regex){
        std::smatch m;
        std::regex _r(_regex);
        std::regex_search(_text, m, _r);
        if(m.empty()) return "";
        return m.suffix().str();
    }

    /**
     * @brief returns a string with the first match of the regex in text replaced by newValue. 
     * 
     * @return std::string 
     */
    std::string replace(std::string _text, std::string _regex, std::string newValue){
        std::regex _r(_regex);
        return std::regex_replace (_text,_r,newValue,std::regex_constants::format_first_only);
    }

    /**
     * @brief returns a string with all matches of the regex in text replaced by newValue.
     * 
     * @return std::string 
     */
    std::string replaceAll(std::string _text, std::string _regex, std::string newValue){
        std::regex _r(_regex);
        return std::regex_replace (_text,_r,newValue);
    }
}