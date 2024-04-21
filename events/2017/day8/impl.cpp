#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "solutions.hpp"
#include "File.hpp"
#include "Regex.hpp"
#include "Utils.hpp"

void Part1()
{
    aoc::File input{"../input.txt"};

    std::vector<Instruction> instructions;

    RegistersTable registers;

    for (auto &line : input.ReadLines())
    {
        aoc::String pattern{"(\\w+) (\\w+) (-?\\d+) if (\\w+) (.?.?) (-?\\d+)"};
        auto matches = aoc::re::MatchGroups(pattern, line);
        // aoc::PrintContainer(matches.cbegin(), matches.cend(), '/');
        instructions.push_back(Instruction{
            matches.at(0),
            matches.at(1),
            StrToInt(matches.at(2)),
            matches.at(3),
            matches.at(4),
            StrToInt(matches.at(5))});
    }

    for (const auto &ins : instructions)
    {
        ProcessInstruction(ins, registers);
    }

    std::vector<RegisterVal> register_values(registers.begin(), registers.end());
    std::sort(register_values.begin(), register_values.end(), [](const RegisterVal &rega, const RegisterVal &regb)
              { return rega.second > regb.second; });

    PrintRegisters(register_values);
}

void Part2()
{
}

void ProcessInstruction(const Instruction &inst, RegistersTable &regs)
{
    if (regs.find(inst.op_reg) == regs.cend())
    {
        regs.insert(std::make_pair(inst.op_reg, 0));
    }

    if (regs.find(inst.cmp_reg) == regs.cend())
    {
        regs.insert(std::make_pair(inst.cmp_reg, 0));
    }

    bool cmp_result = Cmp(inst.cmp_reg, inst.cmp, inst.cmp_value, regs);

    if (inst.op == "inc" && cmp_result)
    {
        regs.at(inst.op_reg) += inst.op_value;
    }
    else if (inst.op == "dec" && cmp_result)
    {
        regs.at(inst.op_reg) -= inst.op_value;
    }
}

bool Cmp(const aoc::String &reg, const aoc::String cmp, int value, const RegistersTable &regs)
{
    if (cmp == "==")
    {
        return regs.at(reg) == value;
    }
    else if (cmp == "<")
    {
        return regs.at(reg) < value;
    }
    else if (cmp == ">")
    {
        return regs.at(reg) > value;
    }
    else if (cmp == "<=")
    {
        return regs.at(reg) <= value;
    }
    else if (cmp == ">=")
    {
        return regs.at(reg) >= value;
    }
    else if (cmp == "!=")
    {
        return regs.at(reg) != value;
    }
    else
    {
        std::cerr << "Invalid operation" << std::endl;
    }

    return false;
}

void PrintRegisters(const std::vector<RegisterVal> &registers)
{
    for (const auto &[reg, value] : registers)
    {
        std::cout << reg << " == " << value << std::endl;
    }
}