#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP
#include <list>
#include "String.hpp"

using ProteinChain = std::list<char>;
ProteinChain ReadProtein(const aoc::String &input);
std::size_t Reaction(ProteinChain &protein_chain);
void FullReaction(ProteinChain &protein_chain);
void Part1();
void Part2();

#endif // SOUTIONS_HPP