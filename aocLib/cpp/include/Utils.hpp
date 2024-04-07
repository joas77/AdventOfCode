#ifndef UTILS_HPP
#define UTILS_HPP
#include <iterator>
#include <iostream>

template <typename InputIt>
void PrintContainer(InputIt first, InputIt last)
{
    for(auto it = first; it!=last; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PrintSeparator();

#endif // UTILS_HPP