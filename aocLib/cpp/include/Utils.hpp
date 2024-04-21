#ifndef UTILS_HPP
#define UTILS_HPP
#include <iterator>
#include <iostream>
#include <unordered_map>
#include "String.hpp"

namespace aoc
{

    template <typename InputIt>
    void PrintContainer(InputIt first, InputIt last, char sep = ' ')
    {
        for (auto it = first; it != last; ++it)
        {
            std::cout << *it << sep;
        }
        std::cout << std::endl;
    }

    // TODO: test this function
    template <typename InputIt, typename DataType>
    std::unordered_map<DataType, int> hist(InputIt first, InputIt last)
    {
        std::unordered_map<DataType, int> hist;
        for (auto it = first; it != last; ++it)
        {
            if (hist.find() == hist.end())
            {
                hist.insert(std::make_pair(DataType{*it}, 1));
            }
            else
            {
                hist[*it]++;
            }
        }
        return hist;
    }

    void PrintSeparator();

    int StrToInt(const aoc::String &str_num, int base = 10);

} // namespace aoc

#endif // UTILS_HPP