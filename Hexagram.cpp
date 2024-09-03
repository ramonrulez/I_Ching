#pragma once

#include <map>
#include <string_view>

const std::map<std::string_view, std::string_view> gramMap{{"hhh", "- -."}, {"hht", "---"}, {"htt", "- - "}, {"ttt", "---."}};

struct Trigram
{
    std::string_view m_gram_1{};
    std::string_view m_gram_2{};
    std::string_view m_gram_3{};
};

class Hexagram
{
    private:
        Trigram m_upTri{};
        Trigram m_loTri{};

    public:
        Hexagram(Trigram& upper, Trigram& lower)
            : m_upTri{upper}, m_loTri{lower}
            {}
            
};