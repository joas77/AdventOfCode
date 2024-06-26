#ifndef STRING_HPP
#define STRING_HPP

#include <string>
#include <algorithm>
#include <vector>

namespace aoc
{
    class String
    {
    public:
        String() = default;
        String(const std::string &data);
        // String(const char *data);
        String(int n);

        // String is splitted in sub-String(s) each time
        // an blank space is found
        std::vector<String> Split() const;
        std::vector<String> Split(const String &sep) const;
        std::string Str() const;
        std::string &Str();

        bool operator==(const std::string &rhs) const;
        bool operator==(const String &rhs) const;
        char operator[](std::size_t index) const;
        String operator+(const String s) const;
        std::size_t size() const;
        String Substr(std::size_t pos = 0, std::size_t count = std::string::npos) const;
        inline void append(const std::string &str)
        {
            data_.append(str);
        }

        inline std::string::iterator begin()
        {
            return data_.begin();
        }

        inline std::string::iterator end()
        {
            return data_.end();
        }

        inline std::string::const_iterator begin() const
        {
            return data_.cbegin();
        }

        inline std::string::const_iterator end() const
        {
            return data_.cend();
        }

        inline std::string::const_iterator cbegin() const
        {
            return data_.cbegin();
        }

        inline std::string::const_iterator cend() const
        {
            return data_.cend();
        }

        // trim from start (in place)
        void Ltrim()
        {
            data_.erase(data_.begin(), std::find_if(data_.begin(), data_.end(), [this](unsigned char ch)
                                                    { return !IsSpace(ch); }));
        }

        // trim from end (in place)
        void Rtrim()
        {
            data_.erase(std::find_if(data_.rbegin(), data_.rend(), [this](unsigned char ch)
                                     { return !IsSpace(ch); })
                            .base(),
                        data_.end());
        }

        // trim from both ends (in place)
        void Trim()
        {
            Rtrim();
            Ltrim();
        }

    private:
        std::string data_;

        bool IsSpace(char c) { return std::isspace(c) || c == '\0'; }
    };

    std::ostream &operator<<(std::ostream &os, const String &str);
    std::istream &operator>>(std::istream &is, String &str);
} // namespace aoc

template <>
struct std::hash<aoc::String>
{
    std::size_t operator()(const aoc::String &s) const noexcept
    {
        return std::hash<std::string>{}(s.Str());
    }
};

aoc::String operator*(const aoc::String &lhs, int rhs);
aoc::String operator*(int lhs, const ::aoc::String &rhs);

#endif // STRING_HPP