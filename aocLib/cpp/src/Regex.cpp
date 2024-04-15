#include "Regex.hpp"

namespace aoc::re{
    std::vector<String> MatchGroups(const std::regex& pattern, const String& string)
    {
        std::vector<String> group_matches;

        auto matches_begin = std::sregex_iterator(string.begin(), string.end(), pattern);
        auto matches_end = std::sregex_iterator();

        for (auto it = matches_begin; it != matches_end; ++it)
        {
            auto matches = *it;
            for (size_t i = 1; i < matches.size(); i++)
            {
                group_matches.push_back(String{matches[i]});
            }
        }

        return group_matches;
    }
}