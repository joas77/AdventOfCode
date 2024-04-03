#include <iostream>
#include <algorithm>

#include "solutions.hpp"
#include "File.hpp"
#include "String.hpp"

void Part1()
{
    std::ifstream input("input.txt");

    int checksum = 0;
    while (input)
    {
        std::string line;
        std::getline(input, line);
        std::istringstream sline(line);
        // Calculate min and max number for each line
        int max = -1;
        int min = INT32_MAX;
        while (sline)
        {
            int cellnumber;
            sline >> cellnumber;
            std::cout << cellnumber << ",";
            max = max < cellnumber ? cellnumber : max;
            min = min > cellnumber ? cellnumber : min;
        }
        std::cout << "====> min => " << min << " max => " << max << std::endl;
        auto maxmin_diff = max - min;
        checksum += maxmin_diff;
    }
    input.close();

    std::cout << "Spreadsheet sheetsum ==> " << checksum << std::endl;
}

void Part2()
{
    aoc::File input("./input.txt");
    auto lines = input.ReadLines();

    int checksum = 0;
    for (auto line : lines)
    {
        line.Trim();

        const auto str_nums = line.Split();
        std::vector<int> nums;
        std::transform(str_nums.cbegin(), str_nums.cend(), std::back_inserter(nums),
                       [](const aoc::String &snum)
                       {
                           return stoi(snum.Str());
                       });

        
        // if size == 0 this code gets stuck inside of for
        for (std::size_t i = 0; i < nums.size() - 1; i++)
        {
            for (size_t j = i + 1; j < nums.size(); j++)
            {
                auto minmax_pair = std::minmax(nums[i], nums[j]);
                // Check if numbers are divisible
                if (minmax_pair.second % minmax_pair.first == 0)
                {
                    checksum += minmax_pair.second / minmax_pair.first;
                    break;
                }
            }
        }
        std::cout << checksum << std::endl;
    }
    std::cout << checksum << std::endl;
}