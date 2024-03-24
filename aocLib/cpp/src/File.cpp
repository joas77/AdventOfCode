#include "File.hpp"

namespace aoc
{

    File::File(const fs::path& path) : file{path}
    {
    }

    File::~File()
    {
        if (is_open_)
        {
            // close file
        }
    }
}