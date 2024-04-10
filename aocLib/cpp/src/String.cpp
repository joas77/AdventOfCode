#include <sstream>
#include <string>
#include "String.hpp"

namespace aoc
{

    String::String(const std::string& data):data_{data}{}

    std::vector<String> String::Split() const
    {
        std::vector<String> substrings;
        auto temp = String{data_};
        temp.Trim();
        std::stringstream substream{temp.Str()};

        while (substream)
        {
            String s;
            substream >> s;
            if(s != "")
                substrings.push_back(s);
        }
        
        return substrings;
    }

    std::string String::Str() const
    {
        return data_;
    }

    std::string& String::Str()
    {
        return data_;
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
    
    bool String::operator==(const std::string& rhs) const
    {
        return Str() == rhs;
    }

    bool String::operator==(const String& rhs) const
    {
        return Str() == rhs.Str();
    }

    char String::operator[](std::size_t index) const
    {
        return Str()[index];
    }

    std::size_t String::size() const
    {
        return Str().size();
    }

    String String::Substr(std::size_t pos, std::size_t count) const
    {
        return String{Str().substr(pos, count)};
    }

} // namespace aoc
