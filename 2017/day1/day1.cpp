#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include "part1.hpp"

int main()
{
    std::ifstream input("input.txt");
    std::string number;
    if(input.is_open())
    {
        input >> number;
    }
    input.close();

    std::array<std::string, 4> examples{
        "1122",
        "1111",
        "1234",
        "91212129"
    };
    for (const auto& example : examples)
    {
        Part1(example);
    }

    Part1(number);

    return 0;
}