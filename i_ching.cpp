#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <iostream>

namespace TextLocation
{
    std::string bookFolder{"I_Ching_book/Book_in_parts/"};
    std::string intro{"0_intro.txt"}; 
}

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
    
    inFile.close();
}   

//  MAIN-----------------------------------------------------------------------

int main() {
    
    printIntro();

    return 0;
}