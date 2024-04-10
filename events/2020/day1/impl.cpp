#include <iostream>
#include <fstream>
#include <unordered_set>
#include "solutions.hpp"

void Part1()
{
    std::fstream input("../input.txt");

    std::unordered_set<int> entries;
    constexpr int target = 2020;
    int entry;
    while (input>>entry)
    {
        if (entries.find(target - entry) != entries.cend())
        {
            // entries pair found
            int other = target - entry;
            std::cout << entry << " * " << other <<
                " = " << entry * other << std::endl;
            break;
        }
        else
        {
            entries.insert(entry);
        }
        
    }
    input.close();
    
}

void Part2()
{
    
}