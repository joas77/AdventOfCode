#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP

#include <vector>
#include <string_view>

void Part1();
void Part2();
// helper functions

struct JmpInstruction
{
    int offset = 0;
    bool visited = false;
};

void PrintJumps(const std::vector<JmpInstruction>& jmps, std::size_t curr_pos);
std::vector<JmpInstruction> ReadJumps(std::string_view filename);

#endif