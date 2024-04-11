#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP
#include "String.hpp"

class Submarine
{
public:
    void ProcessInstruction(const aoc::String& instruction, int value);
    
    int GetHorizontalPosition()
    {
        return x;
    }

    int GetDepth()
    {
        return depth;
    }

private:
    int x = 0;
    int depth = 0;
};

void Part1();
void Part2();

#endif // SOUTIONS_HPP