#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP
#include <unordered_map>
#include "String.hpp"

void Part1();
void Part2();

std::unordered_map<char, int>StrHist(const aoc::String& str);
void PrintHist();

bool ContainsLetterPairs(const aoc::String& str);
bool ContainsLetterTrios(const aoc::String& str);
int HammingDistance(const aoc::String& str1, const aoc::String& str2);

#endif // SOUTIONS_HPP