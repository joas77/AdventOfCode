#ifndef FILE_HPP
#define FILE_HPP

#include <istream>
#include <filesystem>

namespace aoc
{
    namespace fs = std::filesystem;
    class File
    {
    public:
        File(const fs::path& path);
        File()=delete;
        ~File();

        std::vector<std::string> ReadLines();

    private:
        std::ifstream file; // TODO should I use the parent class instead?
        bool is_open_ = false;
    };

}

#endif