#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP

void Part1();
void Part2();

/* 
* Returns the nth triangular number
*/
constexpr int TriangleNumber(int n)
{
    return n*(n+1)/2;
}

constexpr int CodeIndexFromTablePos(int x, int y);

/*
* Returns nth code
*/
constexpr long long CodeGenerator(long long n, long long acc=20151125);

#endif // SOUTIONS_HPP