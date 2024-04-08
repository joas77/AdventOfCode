#include "solutions.hpp"
#include <iostream>
#include "File.hpp"

void Part1()
{
    Computer aocPc;
    aocPc.ReadInstructions("../input.txt");
    aocPc.ExecuteProgram();

    std::cout << "REG B = " << aocPc.ReadRegisterB() << std::endl;
}

void Part2()
{
    
}

void Computer::ReadInstructions(std::string_view file_program)
{
    auto input = aoc::File(file_program);
    instructions_ = input.ReadLines();
}

void Computer::ExecuteProgram()
{
    while (stack_pointer_ < instructions_.size())
    {
        const auto& ins_str = instructions_[stack_pointer_];
        auto opcode = ins_str.Substr(0, 3);
        std::cout <<  ins_str << std::endl;
        char reg;
        if (opcode != "jmp")
        {
            reg = ins_str[4];
        }

        int offset = 0;
        if ("hlf" == opcode)        SetRegister(reg, ReadRegister(reg)/2);
        else if("tpl" == opcode)    SetRegister(reg, ReadRegister(reg)*3);
        else if("inc" == opcode)    SetRegister(reg, ReadRegister(reg) + 1);
        else if("jmp" == opcode)
        {
            offset = stoi(ins_str.Substr(4).Str());
            stack_pointer_ += offset-1;
        }
        else if("jie" == opcode)
        {
            //jie a, +4
            if(ReadRegister(reg) %2 == 0)
            {
                offset = stoi(ins_str.Substr(8).Str());
                stack_pointer_ += offset-1;
            }
        }
        else if("jio" == opcode)
        {
            if(ReadRegister(reg) ==  1)
            {
                offset = stoi(ins_str.Substr(8).Str());
                stack_pointer_ += offset-1;
            }
        }
        
        stack_pointer_++;
        std::cout << "SP = " << stack_pointer_ << ", " << 
            "REG A = " << rega_ << ", " << 
            "REG B = " << regb_ << std::endl;  
    }
    
}

void Computer::SetRegister(char reg, int val)
{
    if(reg == 'a')
        rega_ = val;
    else if (reg == 'b')
        regb_ = val;
}

int Computer::ReadRegister(char reg) const
{
    if(reg == 'a')
        return ReadRegisterA();

    return ReadRegisterB();
}

int Computer::ReadRegisterA() const
{
    return rega_;
}

int Computer::ReadRegisterB() const
{
    return regb_;
}