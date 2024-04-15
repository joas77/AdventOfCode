#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP

#include <vector>
#include <iostream>
#include "String.hpp"

void Part1();
void Part2();

struct Reindeer
{
    aoc::String name;
    int velocity=0;
    int time_flight=0;
    int time_rest = 0;
};

using Reindeers = std::vector<Reindeer>;

/*
* Calculates each reindeer distance with next algorithm
* as d = vt, reinder_d = v*total_time_flight
* total_time_flight = N*tf + epsilon*tf
* N = integer_div(time_total, tf+tr)
* epsilon is 1 if modulus is bigger than tf otherwise is less than 1
*/
std::vector<int> Race(const Reindeers& reindeers, int time_total);

Reindeers Parse(aoc::String input);

class ReindeerRunner
{
public:
    ReindeerRunner()=delete;
    ReindeerRunner(const Reindeer& r):reinder_{r}{};

    void Run(int time);
    int Distance() const;
    const Reindeer& Info() const;
private:
    Reindeer reinder_;
    bool is_resting_ = false;
    int time_running_ = 0;
    int time_resting_ = 0;
    int distance_ = 0;
    void RunOneSecond();
};

using ReindeerRunners=std::vector<ReindeerRunner>;

ReindeerRunners& RaceByPoints(ReindeerRunners& runners, int time_total);

std::ostream& operator<<(std::ostream& os, const ReindeerRunner& runner);


#endif // SOUTIONS_HPP