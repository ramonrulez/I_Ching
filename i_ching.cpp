#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

namespace TextLocation
{
    const std::string bookFolder{"I_Ching_book/Book_in_parts/"};
    const std::string intro{"0_intro.txt"}; 
};

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

void printIntro()
{
    std::string inputString;
    std::ifstream inFile;

    inFile.open(TextLocation::bookFolder + TextLocation::intro);
    
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

void printMainMenu()
{
    std::cout << "MAIN MENU\n";
    for (size_t i = 0; i < MenuItems::mainMenu.size(); i++)
        std::cout << i << ") " << MenuItems::mainMenu[i] << '\n';
}

//  MAIN-----------------------------------------------------------------------

int main() {
    
    printIntro();
    printMainMenu();

    return 0;
}