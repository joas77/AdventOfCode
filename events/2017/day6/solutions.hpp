#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP

#include <vector>
#include <unordered_map>
#include <string_view>
#include "File.hpp"

using Banks=std::vector<int>;

void Part1And2();

// Helper functions
std::vector<int> ReadMemoryBanks(std::string_view filename);
void PrintMemoryBanks(const Banks& banks);

// Part 1 helper functions
aoc::String BanksToString(const Banks& banks);
void SaveRedistribution(const Banks& banks, std::unordered_map<aoc::String, int>& dist_count);
void Reallocate(Banks& banks);

#endif // SOUTIONS_HPP