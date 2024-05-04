#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP


struct Position
{
    int x=0;
    int y=0;
};
class SpiralMemory
{   
public:
    int NextIndex();
    const Position Pos() const;
private:
    int index_ = 1;
    Position pos_;
};

void Part1();
void Part2();

#endif // SOUTIONS_HPP