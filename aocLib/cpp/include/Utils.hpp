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

    template <typename Container>
    void PrintContainer(Container c, char sep = ' ')
    {
        PrintContainer(c.cbegin(), c.cend(), sep);
    }

    // TODO: test this function
    template <typename InputIt, typename DataType>
    std::unordered_map<DataType, int> hist(InputIt first, InputIt last)
    {
        std::unordered_map<DataType, int> hist;
        for (auto it = first; it != last; ++it)
        {
            if (hist.find(*it) == hist.cend())
            {
                hist.insert(std::make_pair(DataType{*it}, 1));
            }
            else
            {
                hist.at(*it)++;
            }
        }
        return hist;
    }

    void PrintSeparator();

    int Int(const aoc::String &str_num, int base = 10);

} // namespace aoc

#endif // UTILS_HPP