#include <iostream>
#include "solutions.hpp"

void Solution(std::string_view number, int offset)
{
    int sum = 0;
    for(size_t i=0; i<number.length(); i++)
    {
        int curr_digit = std::stoi(std::string{number[i]});
        int next_digit = std::stoi(std::string{number[(i+offset) % number.length()]});
        
        if (curr_digit == next_digit)
        {
            sum += curr_digit;
        }
    }

    std::cout << number <<std::endl;
    std::cout << "captcha = " << sum << std::endl;
}