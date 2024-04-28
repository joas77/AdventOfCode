#ifndef FILE_HPP
#define FILE_HPP

#include <fstream>
#include <vector>
#include <filesystem>
#include "String.hpp"

namespace aoc
{
    namespace fs = std::filesystem;
    class File
    {
    public:
        File(const fs::path &path);
        File(const aoc::String &path);
        File() = delete;
        ~File();

        std::vector<String> ReadLines();

    private:
        std::fstream file_;
    };

} // namespace aoc

#endif