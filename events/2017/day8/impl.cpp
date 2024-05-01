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
    Cpu cpu;
    cpu.ReadInstructions(aoc::String{"../input.txt"});

    cpu.ProcessInstructions();
    cpu.PrintRegisters();

    aoc::PrintSeparator();
    std::cout << "Highest reg value = " << cpu.HighestValueRegVal() << std::endl;
}

void Cpu::ReadInstructions(const aoc::String &input_file)
{
    aoc::File input{input_file};

    for (auto &line : input.ReadLines())
    {
        aoc::String pattern{"(\\w+) (\\w+) (-?\\d+) if (\\w+) (.?.?) (-?\\d+)"};
        auto matches = aoc::re::MatchGroups(pattern, line);
        // aoc::PrintContainer(matches.cbegin(), matches.cend(), '/');
        instructions_.push_back(Instruction{
            matches.at(0),
            matches.at(1),
            StrToInt(matches.at(2)),
            matches.at(3),
            matches.at(4),
            StrToInt(matches.at(5))});
    }
}

void Cpu::ProcessInstructions()
{
    for (auto &ins : instructions_)
    {
        ProcessInst(ins, regs_);
    }

    reg_values_ = std::vector<RegisterVal>(regs_.begin(), regs_.end());
    std::sort(reg_values_.begin(), reg_values_.end(), [](const RegisterVal &rega, const RegisterVal &regb)
              { return rega.second > regb.second; });
}

void Cpu::ProcessInst(const Instruction &inst, RegistersTable &regs)
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

    highest_val_ = regs_.at(inst.op_reg) > highest_val_ ? regs_.at(inst.op_reg) : highest_val_;
}

bool Cpu::Cmp(const aoc::String &reg, const aoc::String cmp, int value, const RegistersTable &regs)
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

void Cpu::PrintRegisters()
{
    for (const auto &[reg, value] : reg_values_)
    {
        std::cout << reg << " == " << value << std::endl;
    }
}

int Cpu::HighestValueRegVal() const
{
    return highest_val_;
}

void Part2()
{
}