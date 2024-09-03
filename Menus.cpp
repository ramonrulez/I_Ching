#pragma once

#include <vector>
#include <iostream>
#include "CinCleanup.cpp"

namespace MenuItems
{
    const std::vector mainMenu{"Ask a question",
                                "Read the I Ching",
                                "Find a quote",
                                "See the Hexagrams",
                                "See the Hexagram cross reference",
                                "Recall past questions",
                                "Print a random quote",
                                "Exit"};
};

// Prints the main menu
void printMainMenu()
{
    std::cout << "MAIN MENU\n";
    for (size_t i = 0; i < MenuItems::mainMenu.size(); i++)
        std::cout << i << ") " << MenuItems::mainMenu[i] << '\n';
}

// User input for the main menu
int selectFromMainMenu()
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