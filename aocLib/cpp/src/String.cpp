#include <sstream>
#include <string>
#include "String.hpp"

namespace aoc
{

    String::String(const std::string& data):data{data}{}

    std::vector<String> String::Split() const
    {
        std::vector<String> substrings;
        auto temp = String{data};
        temp.Trim();
        std::stringstream substream{temp.Str()};

        while (substream)
        {
            String s;
            substream >> s;
            // TODO overload == operator
            if(s.Str() != "")
                substrings.push_back(s);
        }
        
        return substrings;
    }

    std::string String::Str() const
    {
        return data;
    }

    std::string& String::Str()
    {
        return data;
    }

    std::ostream& operator<<(std::ostream& os, const String& str)
    {
        os << str.Str();
        return os;
    }

    std::istream& operator>>(std::istream& is, String& str)
    {
        is >> str.Str();
        return is;
    }

} // namespace aoc
