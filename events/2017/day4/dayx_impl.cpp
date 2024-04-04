#include <iostream>
#include <unordered_map>
#include "solutions.hpp"
#include "File.hpp"

void Day1()
{
    std::cout << "hello aoc 2017 day4!" << std::endl;
    aoc::File input("../input.txt");

    int count_valids = 0;
    for (const auto& line: input.ReadLines())
    {   
        bool is_passphrase_valid = true; 
        std::unordered_map<aoc::String, int> word_freq;
        for(const auto& word : line.Split())
        {
            //std::cout << "hash(" << word <<") = " << std::hash<aoc::String>{}(word) << std::endl;
            if(word_freq.find(word) == word_freq.end());
            {
                //std::cout << "first aparition of word: " << word <<std::endl;
                word_freq.insert(std::make_pair(word, 0));
            }
            word_freq[word]++;

            if (word_freq[word] > 1)
            {
                std::cout << "Passphrase [ " << line << " ] is invalid (" << word << ") is repeated" << std::endl;
                is_passphrase_valid = false;
                break;
            }
        }

        if (is_passphrase_valid)
        {
            count_valids++;
        }
        
    }

    std::cout << "================================" << std::endl;
    std::cout << "total valid pass phrases = " << count_valids << std::endl;
}