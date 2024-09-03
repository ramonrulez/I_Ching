#include "BookPartsLocation.cpp"
#include "Menus.cpp"
#include "Random.h"
#include "Question.cpp"
#include "Quote.cpp"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

void question()
{
    // Print the rules
    printBookPart(getTextLocation(BookPartsLocation::question));

    std::string q{};
    std::getline(std::cin, q);

    Question question{getQuestionFromUser()};

    std::cout << "\nIs this question right?\n";
    std::cout << question << '\n';
}
//  MAIN-----------------------------------------------------------------------

int main() {
    
    printBookPart(getTextLocation(BookPartsLocation::intro));
    
    printMainMenu();
    int choise{selectFromMainMenu()};

    switch (choise)
    {
    case 0:
        question();
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