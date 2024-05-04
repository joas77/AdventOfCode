#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP
#include "String.hpp"

void Part1();

bool IsPasswordValid(const aoc::String &password, char c, int repmin, int repmax);
bool IsPasswordValid2dnPolicy(const aoc::String &password, char c, int pos_first, int pos_second);

void Part2();

#endif // SOUTIONS_HPP