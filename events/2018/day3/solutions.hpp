#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP
#include <unordered_map>
#include <unordered_set>
#include "Geometry.hpp"

struct SquareInch
{
    aoc::geo::LatticePoint pos;
    bool claimed = false;
    int id = -1;
};

void Part1();
void Part2();
using SquaredInches = std::unordered_map<aoc::geo::LatticePoint, SquareInch>;
void GenerateArea(const aoc::geo::LatticePoint &start_point,
                  const aoc::geo::LatticePoint &area,
                  SquaredInches &inches,
                  int id,
                  std::unordered_map<int, bool> &ids_status);

#endif // SOUTIONS_HPP