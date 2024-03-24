#include <iostream>
#include "part1.hpp"

void Part1(std::string_view number)
{
    int sum = 0;
    for(size_t i=0; i<number.length(); i++)
    {
        int curr_digit = std::stoi(std::string{number[i]});
        int next_digit = i < number.length() - 1
            ? std::stoi(std::string{number[i+1]})
            : std::stoi(std::string{number[0]});
        
        if (curr_digit == next_digit)
        {
            sum += curr_digit;
        }
    }

    std::cout << number <<std::endl;
    std::cout << "captcha = " << sum << std::endl;
    std::cout << "=========================================" << std::endl;
}