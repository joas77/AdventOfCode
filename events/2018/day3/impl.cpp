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
    std::unordered_map<int, bool> ids;
    for (auto &l : input.ReadLines())
    {
        auto matches = aoc::re::MatchGroups(aoc::String{"#(\\d+) @ (\\d+),(\\d+): (\\d+)x(\\d+)"}, l);
        const auto start = aoc::geo::LatticePoint{std::stoi(matches.at(1).Str()), std::stoi(matches.at(2).Str())};
        const auto area = aoc::geo::LatticePoint{std::stoi(matches.at(3).Str()), std::stoi(matches.at(4).Str())};

        int id = std::stoi(matches.at(0).Str());
        GenerateArea(start, area, inches, id, ids);
    }

    auto claimed_points = std::count_if(inches.cbegin(), inches.cend(), [](const auto &si)
                                        { return si.second.claimed; });

    std::cout << "total overlap area: " << claimed_points << std::endl;

    aoc::PrintSeparator();
    // Find the non-overlapped id
    // auto no_overlaped_ids = std::count_if(ids.cbegin(), ids.cend(), [](const auto &id_status)
    //                                       { return id_status.second == false; });
    // std::cout << "Total no overlapped ids " << no_overlaped_ids << std::endl;
}

void GenerateArea(const aoc::geo::LatticePoint &start_point,
                  const aoc::geo::LatticePoint &area,
                  SquaredInches &inches,
                  int id, std::unordered_map<int, bool> &ids_status)
{
    for (int x = 0; x < area.x; x++)
    {
        for (int y = 0; y < area.y; y++)
        {
            auto p = aoc::geo::LatticePoint{start_point.x + x, start_point.y + y};
            if (inches.find(p) == inches.cend())
            {
                inches.insert(std::make_pair(p, SquareInch{p, false, id}));
                // ids_status.insert(std::make_pair(id, false));
            }
            else
            {
                inches.at(p).claimed = true;
                // ids_status.at(id) = true;
            }
        }
    }
}

void Part2()
{
}