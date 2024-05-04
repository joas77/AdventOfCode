#include "solutions.hpp"
#include <iostream>

void Part1()
{
   SpiralMemory spyroMem;
   
   for (int i = 1; i <= 23; i++)
   {
        std::cout << "index: " << spyroMem.NextIndex() << std::endl;
        std::cout << "pos: (" << spyroMem.Pos().x << ", " << spyroMem.Pos().y << ")" << std::endl;
   }
   
}

void Part2()
{

}

int SpiralMemory::NextIndex()
{
    return 0;
}

const Position SpiralMemory::Pos() const
{
    return pos_;
}