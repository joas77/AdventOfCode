#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "solutions.hpp"
#include "File.hpp"
#include "Utils.hpp"

constexpr int target = 2020;
void Part1()
{
    std::unordered_set<int> entries;
    auto nums = ReadNums();

    for (int entry : nums)
    {
        if (entries.find(target - entry) != entries.cend())
        {
            // entries pair found
            int other = target - entry;
            std::cout << entry << " * " << other << " = " << entry * other << std::endl;
            break;
        }
        else
        {
            entries.insert(entry);
        }
    }
}

void Part2()
{
    auto nums = ReadNums();
    auto entries = std::unordered_set<int>{nums.cbegin(), nums.cend()};
    for (auto it = nums.cbegin(); it != nums.cend() - 1; ++it)
    {
        for (auto jt = it + 1; jt < nums.cend(); ++jt)
        {
            int other_entry = target - *it - *jt;
            if (entries.find(other_entry) != entries.cend())
            {
                int a = *entries.find(other_entry);
                int b = *it;
                int c = *jt;
                int solution = a * b * c;
                std::cout << "Found trio!" << std::endl;
                std::cout << a << " * " << b << " * " << c << " = " << solution << std::endl;

                return;
            }
        }
    }
}

std::vector<int> ReadNums()
{
    aoc::File input{"../input.txt"};
    std::vector<int> nums;
    auto lines = input.ReadLines();
    std::transform(lines.cbegin(), lines.cend(), std::back_inserter(nums), [](auto s)
                   { return aoc::Int(s); });
    return nums;
}