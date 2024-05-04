#include <regex>
#include <vector>
#include "solutions.hpp"
#include "File.hpp"
#include "Utils.hpp"
#include "Regex.hpp"

Reindeers Parse(aoc::String input)
{
    aoc::String regex{"(\\w+) can fly (\\d+) km/s for (\\d+) seconds, but then must rest for (\\d+) seconds."};
    aoc::File file_input{input};
    Reindeers reindeers;

    for (auto &line : file_input.ReadLines())
    {
        auto matches_begin = std::sregex_iterator(line.begin(), line.end(), regex);
        auto matches_end = std::sregex_iterator();

        auto matches = aoc::re::MatchGroups(regex, line);

        reindeers.push_back(Reindeer{
            aoc::String{matches[0]},
            stoi(matches[1].Str()),
            stoi(matches[2].Str()),
            stoi(matches[3].Str())});
    }
    return reindeers;
}

void Part1()
{
    Reindeers reindeers = Parse(aoc::String{"../input_test.txt"});

    for (auto &r : reindeers)
    {
        std::cout << "name: " << r.name << ", v = " << r.velocity << ", Tf = " << r.time_flight << ", Tr = " << r.time_rest << std::endl;
    }

    auto distances = Race(reindeers, 10);
    aoc::PrintContainer(distances.cbegin(), distances.cend());

    std::cout << "best distance = " << *std::max_element(distances.cbegin(), distances.cend()) << std::endl;
}

std::vector<int> Race(const Reindeers &reindeers, int time_total)
{
    std::vector<int> distances;

    for (auto &r : reindeers)
    {
        int N = time_total / (r.time_flight + r.time_rest);
        int mod = time_total % (r.time_flight + r.time_rest);

        int epsilon_flight = mod < r.time_flight ? mod : r.time_flight;

        int time_flight_total = N * r.time_flight + epsilon_flight;

        distances.push_back(time_flight_total * r.velocity);
    }

    return distances;
}

void Part2()
{
    Reindeers reindeers = Parse(aoc::String{"../input_test.txt"});
    std::vector<ReindeerRunner> runners;

    for (auto &r : reindeers)
    {
        runners.push_back(ReindeerRunner{r});
    }

    runners = RaceByPoints(runners, 10);

    aoc::PrintContainer(runners.cbegin(), runners.cend());
}

ReindeerRunners &RaceByPoints(ReindeerRunners &runners, int time_total)
{
    for (int i = 1; i <= time_total; i++)
    {
        std::for_each(runners.begin(), runners.end(), [i](ReindeerRunner &r)
                      { r.Run(i); });
    }

    return runners;
}

void ReindeerRunner::Run(int time)
{
    for (int i = 0; i < time; i++)
    {
        RunOneSecond();
    }
}

void ReindeerRunner::RunOneSecond()
{
    if (!is_resting_)
    {
        distance_ += reinder_.velocity;
        time_running_++;
        if (time_running_ >= reinder_.time_flight)
        {
            is_resting_ = true;
            time_running_ = 0;
        }
    }
    else
    {
        time_resting_++;
        if (time_resting_ >= reinder_.time_rest)
        {
            is_resting_ = false;
            time_resting_ = 0;
        }
    }
}

int ReindeerRunner::Distance() const
{
    return distance_;
}

const Reindeer &ReindeerRunner::Info() const
{
    return reinder_;
}

std::ostream &operator<<(std::ostream &os, const ReindeerRunner &runner)
{
    os << runner.Info().name << " stats: v = " << runner.Info().velocity << " km/s"
       << ", tf = " << runner.Info().time_flight << "s, tr = " << runner.Info().time_rest << "s, distance = " << runner.Distance() << " km" << std::endl;

    return os;
}