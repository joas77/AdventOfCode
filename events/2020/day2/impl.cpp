#include <iostream>
#include <algorithm>
#include "solutions.hpp"
#include "File.hpp"
#include "Regex.hpp"
#include "Utils.hpp"

void Part1()
{
    aoc::File input{"../input.txt"};

    int valid_password_count = 0;

    for (auto &l : input.ReadLines())
    {
        const auto matches = aoc::re::MatchGroups(aoc::String{"(\\d+)-(\\d+) (\\w): (\\w+)"}, l);

        auto password = matches.at(3);

        int reps_min = aoc::Int(matches.at(0));
        int reps_max = aoc::Int(matches.at(1));
        char rep_char = matches.at(2).Str()[0];

        bool is_valid = IsPasswordValid(password, rep_char, reps_min, reps_max);

        valid_password_count += is_valid;
    }
    std::cout << "Total valid passwords with policy 1 = " << valid_password_count << std::endl;
}

bool IsPasswordValid(const aoc::String &password, char c, int repmin, int repmax)
{
    const auto hist = aoc::hist<std::string::const_iterator, char>(password.cbegin(), password.cend());
    int count = hist.find(c) == hist.cend() ? 0 : hist.at(c);
    return repmin <= count && count <= repmax;
}

void Part2()
{
    aoc::File input{"../input.txt"};

    int valid_password_count = 0;

    for (auto &l : input.ReadLines())
    {
        const auto matches = aoc::re::MatchGroups(aoc::String{"(\\d+)-(\\d+) (\\w): (\\w+)"}, l);

        auto password = matches.at(3);

        int pos_first = aoc::Int(matches.at(0));
        int pos_second = aoc::Int(matches.at(1));
        char rep_char = matches.at(2).Str()[0];

        bool is_valid = IsPasswordValid2dnPolicy(password, rep_char, pos_first, pos_second);

        valid_password_count += is_valid;
    }
    std::cout << "Total valid passwords with policy 2 = " << valid_password_count << std::endl;
}

bool IsPasswordValid2dnPolicy(const aoc::String &password, char c, int pos_first, int pos_second)
{
    char first_char = password[pos_first - 1];
    char second_char = password[pos_second - 1];

    return (first_char == c || second_char == c) &&
           (first_char != second_char);
}