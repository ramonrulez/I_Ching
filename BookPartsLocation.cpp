#pragma once

#include <iostream>
#include <string_view>
#include <string>
#include <fstream>

namespace BookPartsLocation
{
    constexpr std::string_view bookFolder{"I_Ching_book/Book_in_parts/"};
    constexpr std::string_view hexagrams{"Hexagrams/Hex_"};

    constexpr std::string_view intro{"0_intro"};
    constexpr std::string_view question{"1_question"};
    constexpr std::string_view castCoin{"2_cast_coins"};
    constexpr std::string_view buildTrigram{"3_build_trigram"};
    constexpr std::string_view buildHexagram{"4_build_hexagram"};
    constexpr std::string_view findHexagram{"5_find_hexagram"};
    constexpr std::string_view interpretHexagram{"6_Interpret_hexagrams"};
    constexpr std::string_view dottedLines {"7_dotted_lines"};
};

// A helper function that returns a std::string from std::string_view objects
// It's used to find easy the location of a file
const std::string getTextLocation(std::string_view bookPart)
{
    std::cout << '\n';
    return {std::string(BookPartsLocation::bookFolder) + std::string(bookPart)};
}

// The same function for the Hexagrams
const std::string getTextLocation(int hexNum)
{
    std::cout << '\n';
    return {std::string(BookPartsLocation::bookFolder) + std::string(BookPartsLocation::hexagrams) + std::to_string(hexNum)};
}

// This function prints out a choosen part of the book
void printBookPart(const std::string& bookPart)
{
    std::string inputString; 
    std::ifstream inFile;

    inFile.open(bookPart);
    
    if (!inFile)
    {
        std::cout << "Unable to open file\n";
        exit(1);
    }
    
    while(std::getline(inFile, inputString)){
        std::cout << inputString << '\n';
    }
    
    std::cout << '\n';

    inFile.close();
}   