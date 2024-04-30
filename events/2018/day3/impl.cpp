#include <iostream>
#include <algorithm>
#include "solutions.hpp"
#include "File.hpp"
#include "Regex.hpp"
#include "Utils.hpp"

void Part1()
{
    auto input{aoc::File{"../input.txt"}};

    SquaredInches inches;
    for (auto &l : input.ReadLines())
    {
        auto matches = aoc::re::MatchGroups(aoc::String{"#(\\d+) @ (\\d+),(\\d+): (\\d+)x(\\d+)"}, l);
        std::cout << l << std::endl;
        aoc::PrintContainer(matches.cbegin(), matches.cend(), '/');
        const auto start = aoc::geo::LatticePoint{std::stoi(matches.at(1).Str()), std::stoi(matches.at(2).Str())};
        const auto area = aoc::geo::LatticePoint{std::stoi(matches.at(3).Str()), std::stoi(matches.at(4).Str())};

        GenerateArea(start, area, inches);
    }

    auto claimed_points = std::count_if(inches.cbegin(), inches.cend(), [](const auto &si)
                                        { return si.second.claimed; });

    std::cout << "total overlap area: " << claimed_points << std::endl;
}

void GenerateArea(const aoc::geo::LatticePoint &start_point, const aoc::geo::LatticePoint &area, SquaredInches &inches)
{
    for (int x = 0; x < area.x; x++)
    {
        for (int y = 0; y < area.y; y++)
        {
            auto p = aoc::geo::LatticePoint{start_point.x + x, start_point.y + y};
            if (inches.find(p) == inches.cend())
            {
                inches.insert(std::make_pair(p, SquareInch{p, false}));
            }
            else
            {
                inches.at(p).claimed = true;
            }
        }
    }
}

void Part2()
{
}