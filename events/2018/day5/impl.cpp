#include <list>
#include "solutions.hpp"
#include "File.hpp"
#include "Utils.hpp"

void Part1()
{
    auto protein_chain = ReadProtein(aoc::String{"../input.txt"});

    std::cout << "Protein chain reacting..." << std::endl;
    FullReaction(protein_chain);
    std::cout << "Resulting polymer size = " << protein_chain.size() << std::endl;
}

ProteinChain ReadProtein(const aoc::String &input)
{
    auto input_file{aoc::File{input}};

    auto lines = input_file.ReadLines();
    auto protein_chain = std::list<char>{lines.at(0).cbegin(), lines.at(0).cend()};

    return std::list<char>(protein_chain);
}

std::size_t Reaction(ProteinChain &protein_chain)
{
    if (protein_chain.size() <= 1)
        return 0;

    std::size_t removed_units = 0;
    auto curr = protein_chain.cbegin();
    auto next = curr;
    next++;

    while (next != protein_chain.cend())
    {
        if ((*curr != *next) && (std::tolower(*curr) == std::tolower(*next)))
        {
            protein_chain.erase(curr, ++next);
            removed_units += 2;
        }
        curr = next;
        next++;
    }
    return removed_units;
}

void FullReaction(ProteinChain &protein_chain)
{
    std::size_t removed_units;
    do
    {
        removed_units = Reaction(protein_chain);
    } while (removed_units != 0);
}

void Part2()
{
    auto protein_chain = ReadProtein(aoc::String{"../input.txt"});
    auto units = aoc::String{"abcdefghijklmnopqrstuvwxyz"};

    std::cout << "Improving protein chain..." << std::endl;
    for (auto unit : units)
    {
        std::cout << "Reaction after removing " << unit << "..." << std::endl;
        protein_chain.remove(unit);
        protein_chain.remove(std::toupper(unit));
        FullReaction(protein_chain);
        std::cout << "Size after reaction " << protein_chain.size() << std::endl;
    }
}