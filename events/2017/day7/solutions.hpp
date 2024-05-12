#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP

#include <vector>
#include <unordered_map>
#include <iostream>
#include "String.hpp"

struct Program
{
    aoc::String name;
    Program *parent = nullptr;
    std::vector<Program *> programs;
};

class ProgramTower
{
public:
    void AddProgram(const aoc::String &name, const aoc::String &parent = aoc::String{""});
    // void AddProgramAbove(const aoc::String &name, const aoc::String &parent);
    aoc::String GetBottomProgrma();

private:
    std::unordered_map<aoc::String, Program> programs_table_;
};

void Part1();
void Part2();

#endif // SOUTIONS_HPP