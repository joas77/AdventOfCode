#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP
#include <string_view>
#include <vector>
#include "String.hpp"

void Part1();
void Part2();

class Computer
{
public:
    void ReadInstructions(std::string_view file_program);
    void ExecuteProgram();
    int ReadRegisterA() const;
    int ReadRegisterB() const;
private:
    int ReadRegister(char reg) const;
    void SetRegister(char reg, int val);
    int rega_ = 1; // part 1 reg = 0, part 2 reg = 1
    int regb_ = 0;
    std::size_t stack_pointer_ = 0;
    std::vector<aoc::String> instructions_;
};

#endif // SOUTIONS_HPP