#include <fstream>
#include <iostream>
#include "solutions.hpp"

void Part1()
{
    auto banks = ReadMemoryBanks("../input.txt");
    PrintMemoryBanks(banks);

    bool seen_before = false;
    auto dist_count{std::unordered_map<aoc::String, int>{}};

    int realloc_steps = 0;

    while (!seen_before)
    {
        auto banks_repr = BanksToString(banks);
        if (dist_count.find(banks_repr) != dist_count.cend())
        {
            seen_before = true;
        }
        else
        {
            dist_count.insert(std::make_pair(banks_repr, 1));
            realloc_steps++;
            Reallocate(banks);
            std::cout << "=======================" << std::endl;
        }
    }

    std::cout << "Total realloc steps = " << realloc_steps << std::endl;
}

void Part2()
{
}

std::vector<int> ReadMemoryBanks(std::string_view filename)
{
    std::vector<int> banks;
    std::fstream input{filename.data()};
    int b;
    while (input >> b)
    {
        banks.push_back(b);
    }
    input.close();

    return banks;
}

void PrintMemoryBanks(const Banks &banks)
{
    for (const auto b : banks)
    {
        std::cout << b << " ";
    }
    std::cout << std::endl;
}

aoc::String BanksToString(const Banks &banks)
{
    aoc::String banks_repr;
    for (auto b : banks)
    {
        banks_repr.append(std::to_string(b));
    }
    return banks_repr;
}

void Reallocate(Banks &banks)
{
    auto biggest_block_it = std::max_element(banks.begin(), banks.end());
    auto biggest_block = *biggest_block_it;
    auto pos = std::distance(banks.begin(), biggest_block_it);

    std::cout << "Realocating memory: ";
    PrintMemoryBanks(banks);
    std::cout << "biggest block = " << biggest_block << ", pos = " << pos << std::endl;

    *biggest_block_it = 0;

    while (biggest_block > 0)
    {
        pos++;
        banks.at(pos % banks.size())++;
        biggest_block--;
    }

    std::cout << "Memory after reallocation: ";
    PrintMemoryBanks(banks);
}
