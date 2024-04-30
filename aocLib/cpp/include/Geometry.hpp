#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP
#include "String.hpp"

namespace aoc
{
    namespace geo
    {
        struct LatticePoint
        {
            int x = 0;
            int y = 0;
        };
    } // namespace geo
} // namespace aoc

template <>
struct std::hash<aoc::geo::LatticePoint>
{
    std::size_t operator()(const aoc::geo::LatticePoint &s) const noexcept
    {
        return std::hash<aoc::String>{}(aoc::String{s.x} + aoc::String{s.y});
    }
};

template <>
struct std::equal_to<aoc::geo::LatticePoint>
{
    bool operator()(const aoc::geo::LatticePoint &lhs, const aoc::geo::LatticePoint &rhs) const noexcept
    {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};

#endif