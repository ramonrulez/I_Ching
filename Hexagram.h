#ifndef HEXAGRAM_H
#define HEXAGRAM_H

// The Gram struct defines the building block of the trigram.
// It consists of dashes(-), whitespace( ) and a period(.).
// It can have 4 different patterns.
#include <map>
#include <string>

const std::map<std::string, std::string> gramMap{{"hhh", "- -."}, {"hht", "---"}, {"htt", "- - "}, {"ttt", "---."}};

struct UpperTrigram
{
    std::string m_upGram_1{};
    std::string m_upGram_2{};
    std::string m_upGram_3{};
};

struct LowerTrigram
{
    std::string m_logram_1{};
    std::string m_logram_2{};
    std::string m_logram_3{};
};

class Hexagram
{
    private:
        UpperTrigram upTri{};
        LowerTrigram lowTri{};

    public:
        


};


#endif