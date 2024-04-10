#include <fstream>
#include <iostream>
#include "solutions.hpp"

void Part1()
{
    std::fstream input("../input.txt");
    int mass;
    int fuel_sum = 0;
    while (input >> mass)
    {
        int fuel = mass/3 - 2;
        fuel_sum += fuel;
    }
    input.close();
    
    std::cout << "total fuel required = " << fuel_sum << std::endl;
}

void Part2()
{
    std::fstream input("../input.txt");
    int mass;
    int fuel_sum = 0;
    while (input >> mass)
    {
        int fuel = mass;
        while (fuel > 0)
        {
            fuel = CalculateFuel(fuel);
            if(fuel > 0)
                fuel_sum += fuel;
        }
           
    }
    input.close();
    
    std::cout << "total fuel required = " << fuel_sum << std::endl;
}

int CalculateFuel(int mass)
{
    return mass/3 - 2;
}