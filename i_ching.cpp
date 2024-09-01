#include "BookPartsLocation.cpp"
#include "Menus.cpp"
#include "CinCleanup.cpp"
#include "Random.h"

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

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

// User input for the main menu
int selectFromMenu()
{
    int choise;
    while (true)
    {
        std::cout << "Choose what you want to do[0-" << MenuItems::mainMenu.size() - 1 << "]: ";
        std::cin >> choise;

        if (clearFailedExtraction() || clearExtraInput())
        {
            std::cout << "Wrong input. Try again!\n";
            continue;
        }
        
        if (!(choise >= 0 && choise < static_cast<int>(MenuItems::mainMenu.size())))
        {
            std::cout << "Wrong input. Try again!\n";
            continue;
        }

        break;
    }
    
    return choise;
}

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

//  MAIN-----------------------------------------------------------------------

int main() {
    
    printBookPart(getTextLocation(BookPartsLocation::intro));
    
    printMainMenu();
    int choise{selectFromMenu()};

    switch (choise)
    {
    case 0:
        // Question
        break;
    case 1:
        printBookPart("I_Ching_book/i_ching_full_text");
        break;
    case 2:
        findQuote(selectQuote());
        break;
    case 3:
        // See the Hexagrams
        break;
    case 4:
        // See the Hexagram cross reference
        break;
    case 5:
        // Recall
        break;
    case 6:
        printBookPart(getTextLocation(Random::get(1, 64))); // 64 different quotes from the book
        break;
    default:
        std::cout << "\n\n`Goodbye!\n";
        break;
    }
    
    return 0;
}