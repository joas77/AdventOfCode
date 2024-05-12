#include <sstream>
#include <string>
#include "String.hpp"

namespace aoc
{

    String::String(const std::string &data) : data_{data} {}
    // String::String(const char *data) : data_{data} {}

    String::String(int n) : data_{std::to_string(n)} {}

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
            if (s != "")
                substrings.push_back(s);
        }

        return substrings;
    }

    std::vector<String> String::Split(const String &sep) const
    {
        std::vector<String> substrings;
        if (sep.size() == 0)
        {
            substrings.push_back(*this);
            return substrings;
        }

        size_t start_pos = 0;
        for (size_t i = 0; i < size(); i++)
        {
            if ((*this)[i] == sep[0] && Substr(i, sep.size()) == sep)
            {
                substrings.push_back(Substr(start_pos, i - start_pos));
                start_pos = i + sep.size();
            }
        }
        substrings.push_back(Substr(start_pos, size() - start_pos));

        return substrings;
    }

    std::string String::Str() const
    {
        return data_;
    }

    std::string &String::Str()
    {
        return data_;
    }

    std::ostream &operator<<(std::ostream &os, const String &str)
    {
        os << str.Str();
        return os;
    }

    std::istream &operator>>(std::istream &is, String &str)
    {
        is >> str.Str();
        return is;
    }

    bool String::operator==(const std::string &rhs) const
    {
        return Str() == rhs;
    }

    bool String::operator==(const String &rhs) const
    {
        return Str() == rhs.Str();
    }

    String String::operator+(const String s) const
    {
        return String{Str() + s.Str()};
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

aoc::String operator*(const aoc::String &lhs, int rhs)
{
    std::string s;
    s.reserve(lhs.size() * rhs);

    for (int i = 0; i < rhs; i++)
    {
        s.append(lhs.Str());
    }
    return aoc::String{s};
}

aoc::String operator*(int lhs, const ::aoc::String &rhs)
{
    std::string s;
    s.reserve(rhs.size() * lhs);

    for (int i = 0; i < lhs; i++)
    {
        s.append(rhs.Str());
    }
    return aoc::String{s};
}
