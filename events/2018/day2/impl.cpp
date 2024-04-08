#include <iostream>
#include <unordered_map>
#include "solutions.hpp"
#include "File.hpp"

void Part1()
{
    aoc::File input("../input.txt");
    
    int count_three_letter = 0;
    int count_two_letter = 0;
    for (auto &line : input.ReadLines())
    {   
        if(ContainsLetterPairs(line))
            count_two_letter++;

        if (ContainsLetterTrios(line))
            count_three_letter++;
            
    }

    std::cout << "Checksum = " << count_two_letter << " * " << count_three_letter <<
       " = " <<  count_two_letter * count_three_letter << std::endl;
   
}

void Part2()
{
    aoc::File input("../input.txt");
    auto lines = input.ReadLines();
    for(auto it=lines.cbegin(); it != lines.cend() - 1; ++it)
    {
        for (auto jit=it+1; jit != lines.cend(); ++jit)
        {
            auto d = HammingDistance(*it, *jit);
            if (d==1)
                std::cout << "distance(" << *it << ", " << *jit << ") = " << d << std::endl;
        }
    }
}

std::unordered_map<char, int>StrHist(const aoc::String& str)
{
    std::unordered_map<char, int>h;
    for (char c : str)
    {
        if(h.find(c) == h.cend(0))
        {
            h.insert(std::make_pair(c, 1));
        }
        else
        {
            h[c]++;
        }
    }
    return h;
}

bool ContainsLetterPairs(const aoc::String& str)
{
    auto char_freq = StrHist(str);
    for (auto &[_, count] : char_freq)
    {
        if(count == 2)
            return true;
            
    }

    return false;
}

bool ContainsLetterTrios(const aoc::String& str)
{
    auto char_freq = StrHist(str);
    for (auto &[_, count] : char_freq)
    {
        if(count == 3)
            return true;
            
    }

    return false;
}

int HammingDistance(const aoc::String& str1, const aoc::String& str2)
{
    if (str1.size() != str2.size())
    {
        return 0;
    }
    
    int distance = 0;
    for(auto it1=str1.cbegin(), it2=str2.cbegin(); it1!=str1.cend(); ++it1, ++it2)
    {
        if (*it1 != *it2)
        {
            distance++;
        }
        
    }

    return distance;
}