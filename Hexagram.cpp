#pragma once

#include <map>
#include <string>

const std::map<std::string, std::string> gramMap{{"hhh", "- -."}, {"hht", "---"}, {"htt", "- - "}, {"ttt", "---."}};

struct Trigram
{
    std::string m_gram_1{};
    std::string m_gram_2{};
    std::string m_gram_3{};
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