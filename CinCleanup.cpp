#pragma once

#include <limits> // for std::numeric_limits
#include <iostream>

inline void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline bool clearFailedExtraction()
{
    if (!std::cin) // if the previous extraction failed
    {
        std::cin.clear(); // put us back in 'normal' operation mode
        ignoreLine();
        return true;
    }

    return false;
}

inline bool clearExtraInput()
{
    if (!std::cin.eof() && std::cin.peek() != '\n')
    {
        ignoreLine();
        return true;
    }

    return false;
}