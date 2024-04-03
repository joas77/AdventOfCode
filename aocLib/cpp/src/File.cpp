#include "File.hpp"

namespace aoc
{

    File::File(const fs::path &path) : file{path}
    {
    }

    File::~File()
    {
        if (file.is_open())
        {
            file.close();
        }
    }

    std::vector<String> File::ReadLines()
    {
        std::vector<String> lines;
        if (file.is_open())
        {
            while (file)
            {
                std::string line;
                std::getline(file, line);
                if(line != "")
                    lines.push_back(String{line});
            }
        }

        return lines;
    }
}