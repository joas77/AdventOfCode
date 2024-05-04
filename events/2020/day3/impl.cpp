#include <utility>
#include "solutions.hpp"
#include "File.hpp"
#include "Utils.hpp"

void Part1()
{
    auto input = aoc::File{"../input.txt"};

    auto lines = input.ReadLines();

    int tree_count = CountTreesWithSlope(lines, 1, 3);
    std::cout << "Trees found = " << tree_count << std::endl;
}

void Part2()
{
    auto input = aoc::File{"../input_test.txt"};
    auto lines = input.ReadLines();

    std::vector<std::pair<int, int>> slopes = {
        {1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};

    long long solution = 1;
    for (auto &[dx, dy] : slopes)
    {
        auto trees = CountTreesWithSlope(lines, dy, dx);
        std::cout << "Trees found with slope " << dy << "/" << dx << " = " << trees << std::endl;
        solution *= trees;
    }

    std::cout << "Solution part 2 = " << solution << std::endl;
}

long long CountTreesWithSlope(std::vector<aoc::String> &map, int dy, int dx)
{
    long long tree_count = 0;
    for (int x = 0, y = 0; y < map.size();)
    {
        if (x > map[y].size())
        {
            map[y] = map[y] * (1 + x / map[y].size());
        }

        if (map[y][x] == '#')
        {
            tree_count++;
        }
        y += dy;
        x += dx;
    }
    return tree_count;
}