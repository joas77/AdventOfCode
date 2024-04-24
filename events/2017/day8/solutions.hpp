#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP

#include <unordered_map>
#include <vector>
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

using RegisterVal = std::pair<aoc::String, int>;
using RegistersTable = std::unordered_map<aoc::String, int>;
class Cpu
{
public:
    void ReadInstructions(const aoc::String &input_file);
    void ProcessInstructions();
    void PrintRegisters();
    int HighestValueRegVal() const;

private:
    std::vector<Instruction> instructions_;
    RegistersTable regs_;
    std::vector<RegisterVal> reg_values_;
    int highest_val_{0};

    bool Cmp(const aoc::String &reg, const aoc::String cmp, int value, const RegistersTable &regs);
    void ProcessInst(const Instruction &inst, RegistersTable &regs);
};

void Part1();

void PrintRegisters(const std::vector<RegisterVal> &registers);

void Part2();

#endif // SOUTIONS_HPP