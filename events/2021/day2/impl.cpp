#include <iostream>
#include "solutions.hpp"
#include "File.hpp"

void Part1()
{
   aoc::File input{"../input.txt"};

    Submarine yellow;
    for (auto &line : input.ReadLines())
    {
        auto words = line.Split();
        auto ins = words[0];
        int value = std::stoi(words[1].Str());
        yellow.ProcessInstruction(ins, value);
    }

    int x = yellow.GetHorizontalPosition();
    int depth = yellow.GetDepth();
    std::cout << "Submarine final pos (x, y) = " << x <<
        " , " << depth << std::endl;

    std::cout << x << " *  " << depth << " = " << x * depth << std::endl;
}

void Part2()
{
    
}

void Submarine::ProcessInstruction(const aoc::String& instruction, int value)
{
    if (instruction == "forward")
    {
        x += value;
    }
    else if (instruction == "down")
    {
        depth += value;
    }
    else if (instruction == "up")
    {
        depth -= value;
    }
    else
    {
        std::cerr << instruction <<  " Is an nvalid instruction!" << std::endl;
    }
       
}