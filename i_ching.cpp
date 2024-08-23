#include "BookPartsLocation.cpp"
#include "Menus.cpp"

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <iostream>

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

//  MAIN-----------------------------------------------------------------------

int main() {
    
    printBookPart(getTextLocation(BookPartsLocation::intro));
    printMainMenu();
    
    return 0;
}