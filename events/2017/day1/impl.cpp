#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include "solutions.hpp"

int main()
{
    std::ifstream input("input.txt");
    std::string number;
    if (input.is_open())
    {
        input >> number;
    }
    input.close();

    std::array<std::string, 4> examples{
        "1122",
        "1111",
        "1234",
        "91212129"};
    for (const auto &example : examples)
    {
        std::cout << "Example for part 1, offset = 1" << std::endl;
        Solution(example);
        std::cout << "=========================================" << std::endl;

        std::cout << "Example for part 2, offset = numer.length()/2" << std::endl;
        Solution(example, example.length() / 2);
        std::cout << "=========================================" << std::endl;
        std::cout << "=========================================" << std::endl;
    }

    std::cout << "solution part 1" << std::endl;
    Solution(number);

    std::cout << "=========================================" << std::endl;

    std::cout << "solution part 2" << std::endl;
    Solution(number, number.length() / 2);

    return 0;
}