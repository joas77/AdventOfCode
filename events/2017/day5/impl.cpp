#include <iostream>
#include <fstream>
#include <algorithm>
#include "solutions.hpp"

void Part1()
{
    std::cout << "Year 2017 day 5 part 1" << std::endl;

    auto instructions{ReadJumps("../input.txt")};

    std::size_t curr_pos = 0;
    int steps = 0;
    while (curr_pos < instructions.size())
    {
        // 1. mark current position as visited
        // 2. do the jump
        // 3. increase offset from previous position

        // 1
        instructions[curr_pos].visited = true;

        // 2
        int jumps = instructions[curr_pos].offset;
        curr_pos += jumps;

        // 3
        instructions[curr_pos - jumps].offset++;

        steps++;

        // PrintJumps(instructions, curr_pos);
    }
    std::cout << "total steps = " << steps << std::endl;
    std::cout << "====================================" << std::endl;
}

void Part2()
{
    std::cout << "Year 2017 day 5 part 2" << std::endl;

    auto instructions{ReadJumps("../input.txt")};

    std::size_t curr_pos = 0;
    int steps = 0;
    // PrintJumps(instructions, curr_pos);
    while (curr_pos < instructions.size())
    {
        // 1. mark current position as visited
        // 2. do the jump
        // 3. if offset >= 3 decrease by one from previous position,
        // Otherwise increase by one

        // 1
        instructions[curr_pos].visited = true;

        // 2
        int jumps = instructions[curr_pos].offset;
        curr_pos += jumps;

        // 3
        int prev_pos = curr_pos - jumps;
        if (instructions[prev_pos].offset >= 3)
        {
            instructions[prev_pos].offset--;
        }
        else
        {
            instructions[prev_pos].offset++;
        }

        steps++;

        // PrintJumps(instructions, curr_pos);
    }
    std::cout << steps << std::endl;
}

void PrintJumps(const std::vector<JmpInstruction> &jmps, std::size_t curr_pos)
{
    for (std::size_t i = 0; i < jmps.size(); i++)
    {
        if (curr_pos == i)
        {
            std::cout << "(" << jmps[i].offset << ") ";
        }
        else
        {
            std::cout << jmps[i].offset << " ";
        }
    }
    std::cout << std::endl;
}

std::vector<JmpInstruction> ReadJumps(std::string_view filename)
{
    std::vector<JmpInstruction> instructions;
    std::fstream input(filename.data());
    int jmp_offset;
    while (input >> jmp_offset)
    {
        instructions.push_back(JmpInstruction{jmp_offset, false});
    }
    input.close();

    return instructions;
}