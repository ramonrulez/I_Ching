#pragma once

#include <iostream>
#include "CinCleanup.cpp"
#include "BookPartsLocation.cpp"


int selectQuote()
{
    int choise;
    while (true)
    {
        std::cout << "Choose what quote you want to read[1-64]: ";
        std::cin >> choise;

        if (clearFailedExtraction() || clearExtraInput())
        {
            std::cout << "Wrong input. Try again!\n";
            continue;
        }
        
        if (!(choise > 0 && choise < 65))
        {
            std::cout << "Wrong input. Try again!\n";
            continue;
        }

        break;
    }
    
    return choise;
}

// This function is not really needed but is there for clarity
inline void findQuote(int quote)
{
    printBookPart(getTextLocation(quote));
}