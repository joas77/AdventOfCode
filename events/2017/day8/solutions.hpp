#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP

#include <unordered_map>
#include "String.hpp"

struct Instruction
{
    aoc::String op_reg;
    aoc::String op;
    int op_value;
    aoc::String cmp_reg;
    aoc::String cmp;
    int cmp_value;
};

void Part1();

using RegistersTable = std::unordered_map<aoc::String, int>;
void ProcessInstruction(const Instruction &inst, RegistersTable &regs);
bool Cmp(const aoc::String &reg, const aoc::String cmp, int value, const RegistersTable &regs);

using RegisterVal = std::pair<aoc::String, int>;
void PrintRegisters(const std::vector<RegisterVal> &registers);

void Part2();

#endif // SOUTIONS_HPP