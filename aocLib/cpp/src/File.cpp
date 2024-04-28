#include "File.hpp"

namespace aoc
{

    File::File(const fs::path &path) : file_{path}
    {
    }

    File::File(const aoc::String &path) : file_{path.Str()} {}

    File::~File()
    {
        if (file_.is_open())
        {
            file_.close();
        }
    }

    std::vector<String> File::ReadLines()
    {
        std::vector<String> lines;
        if (file_.is_open())
        {
            while (file_)
            {
                std::string line;
                std::getline(file_, line);
                if (line != "")
                    lines.push_back(String{line});
            }
        }

        return lines;
    }
}