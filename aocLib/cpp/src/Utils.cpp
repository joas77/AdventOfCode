#include "Utils.hpp"

namespace aoc
{
    void PrintSeparator()
    {
        std::cout << "============================================================" << std::endl;
    }

    int Int(const aoc::String &str_num, int base)
    {
        return std::stoi(str_num.Str(), 0, base);
    }

} // namespace aoc