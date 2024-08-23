#pragma once

#include <vector>
#include <iostream>

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

void printMainMenu()
{
    std::cout << "MAIN MENU\n";
    for (size_t i = 0; i < MenuItems::mainMenu.size(); i++)
        std::cout << i << ") " << MenuItems::mainMenu[i] << '\n';
}
