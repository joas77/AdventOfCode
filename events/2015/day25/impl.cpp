#include <iostream>
#include <cassert>
#include "solutions.hpp"

void Part1()
{
    std::cout << "Testing part 1..." << std::endl;
    for (size_t y = 1; y <= 6; y++)
    {
        for (size_t x = 1; x <= 6; x++)
        {
            auto codeIndex = CodeIndexFromTablePos(x, y);
            std::cout << "(" << x << "," << y << ") --> " <<
                codeIndex << " --> " << 
                CodeGenerator(codeIndex) << std::endl; 
        }
        std::cout << std::endl;
    }
    // input data:
    // To continue, please consult the code grid in the manual.  Enter the code at row 2981, column 3075.
    // Compile with optimitations to avoid stack overflow
    auto index = CodeIndexFromTablePos(3075, 2981);
    std::cout << "Searching " << index << "-th code" << std::endl;
    std::cout << "Solution = " << CodeGenerator(index) << std::endl;    
    
}

void Part2()
{
    
}

constexpr int CodeIndexFromTablePos(int x, int y)
{
    assert(y > 0);
    assert(x > 0);

    if (y == 1)
    {
        return TriangleNumber(x);
    }
    
    return CodeIndexFromTablePos(x+1, y-1) - 1;
}

constexpr long long CodeGenerator(long long n, long long acc)
{
    if(n == 1) return acc;

    return CodeGenerator(n-1,  (acc* 252533) % 33554393);
}