#include <iostream>
#include "solutions.hpp"
#include "File.hpp"
#include "Regex.hpp"
#include "Utils.hpp"

void Part1()
{
    aoc::File input{aoc::String{"../input.txt"}};
    auto program_tower = ProgramTower{};
    for (auto &line : input.ReadLines())
    {

        auto sides = line.Split(aoc::String("->"));
        std::cout << sides.size() << std::endl;
        std::cout << line << std::endl;
        aoc::PrintContainer(sides, '/');
        // parsing program name and weight
        const auto matches = aoc::re::MatchGroups(aoc::String{"(\\w+)"}, sides.at(0));
        aoc::PrintContainer(matches, '-');
        const auto &program_parent_name = matches.at(0);
        program_tower.AddProgram(program_parent_name);
        if (sides.size() == 2)
        {
            const auto matches = aoc::re::MatchGroups(aoc::String{"(\\w+)"}, sides.at(1));
            aoc::PrintContainer(matches, '-');
            for (const auto &progam_name : matches)
            {
                program_tower.AddProgram(progam_name, program_parent_name);
            }
        }
    }

    std::cout << "Part 1 solution: " << program_tower.GetBottomProgrma() << std::endl;
}

void Part2()
{
}

void ProgramTower::AddProgram(const aoc::String &name, const aoc::String &parent)
{
    if (programs_table_.find(name) == programs_table_.cend())
    {
        programs_table_.insert({name, Program{name}});
    }

    if (parent != "")
    {
        auto &program = programs_table_.at(name);
        program.parent = &programs_table_.at(parent);
        programs_table_.at(parent).programs.push_back(&program);
    }
}

aoc::String ProgramTower::GetBottomProgrma()
{
    // get any program from table and go up until find the bottom
    auto *p = &programs_table_.begin()->second;

    while (p->parent)
    {
        p = p->parent;
    }

    return p->name;
}