#ifndef REGEX_HPP
#define REGEX_HPP

/*
* Library for utilities related with regular expressions
* in order to make easier to parse input files in aoc
*/

#include <vector>
#include <regex>
#include <String.hpp>

namespace aoc
{
    namespace re
    {
        /**
         * Matches all the groups
         * The regex shall contains gruoups, e.g (\w) otherwise it will return an empty vector
        */
        std::vector<String> MatchGroups(const std::regex& pattern, const String& string);
    } // namespace re
    
} // namespace aoc


#endif // REGEX_HPP