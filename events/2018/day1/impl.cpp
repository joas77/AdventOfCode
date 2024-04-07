#include <fstream>
#include <numeric>
#include <unordered_set>
#include "solutions.hpp"

void Part1()
{
    auto freqs = ReadFreqChanges("../input.txt");
    auto freq_sum = std::accumulate(freqs.cbegin(), freqs.cend(), 0);
    std::cout << "Sum of frequencies = " << freq_sum << std::endl;
}

void Part2()
{
    auto freqs = ReadFreqChanges("../input.txt");
    auto freq_sum = int{0};
    auto freqs_set = std::unordered_set<int>{};
    std::size_t i = 0;
    while (freqs_set.find(freq_sum) == freqs_set.cend())
    {
        auto f = freqs[i % freqs.size()];
        freqs_set.insert(freq_sum);
        freq_sum += f;
        i++;
    }

    std::cout << "First repetead frequency = " << freq_sum << std::endl;
}

std::vector<int> ReadFreqChanges(std::string_view inputfile)
{
    std::fstream input{inputfile.data()};
    std::vector<int> freqs;

    int f;
    while (input >> f)
    {
        freqs.push_back(f);
    }
    input.close();
    return freqs;
}