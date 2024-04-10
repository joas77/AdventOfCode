#include <fstream>
#include <iostream>
#include <vector>
#include <numeric>
#include "solutions.hpp"
#include "Utils.hpp"

void Part1()
{
    std::fstream input("../input.txt");

    int depth;
    std::vector<int> depths;
    while (input >> depth)
    {
        depths.push_back(depth);
    }
    input.close();

    std::vector<int> depthDiffs(depths.size(), 0);
    std::adjacent_difference(depths.cbegin(), depths.cend(),  depthDiffs.begin());


    // first element NA as not previous measurement
    int incCount = std::count_if(depthDiffs.cbegin(), depthDiffs.cend(), [](int d){
        return d > 0;
    }) - 1;

    std::cout << incCount << std::endl;
}

void Part2()
{
    
}