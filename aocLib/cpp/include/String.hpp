#ifndef STRING_HPP
#define STRING_HPP

#include <string>
#include <vector>

namespace aoc
{
    class String
    {
    public:
        String() = default;
        String(const std::string &data);

        // String is splitted in sub-String(s) each time
        // an blank space is found
        std::vector<String> Split() const;
        std::string Str() const;
        std::string &Str();

        bool operator==(const std::string& rhs) const;
        bool operator==(const String& rhs) const;

        // trim from start (in place)
        void Ltrim()
        {
            data.erase(data.begin(), std::find_if(data.begin(), data.end(), [this](unsigned char ch)
                                                  { return !IsSpace(ch); }));
        }

        // trim from end (in place)
        void Rtrim()
        {
            data.erase(std::find_if(data.rbegin(), data.rend(), [this](unsigned char ch)
                                    { return !IsSpace(ch); })
                           .base(),
                       data.end());
        }

        // trim from both ends (in place)
        void Trim()
        {
            Rtrim();
            Ltrim();
        }

    private:
        std::string data;

        bool IsSpace(char c) { return std::isspace(c) || c == '\0'; }
    };

    std::ostream &operator<<(std::ostream &os, const String &str);
    std::istream &operator>>(std::istream &is, String &str);
} // namespace aoc

template <>
struct std::hash<aoc::String>
{
    std::size_t operator()(const aoc::String& s) const noexcept
    {
        return std::hash<std::string>{}(s.Str());
    }
};


#endif // STRING_HPP