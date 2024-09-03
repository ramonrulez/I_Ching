#include "BookPartsLocation.cpp"
#include "Menus.cpp"
#include "Random.h"
#include "Question.cpp"
#include "Quote.cpp"
#include "ParallelCoinToss.cpp"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

Question getQuestion()
{
    // Print the rules
    printBookPart(getTextLocation(BookPartsLocation::question));

    Question question{};
    bool answer{};
    do
    {
        // In this section the user gives his question
        question = getQuestionFromUser();

        // Here we check if the question that the user gave is the correct answer
        answer = isTheQuestionCorrect(question);    
    } while (!(answer));

    return question;
}

void printQuestion(Question& question)
{
    system("clear");
    std::cout << '\n' << question.getQuestion() << '\n';
}
//  MAIN-----------------------------------------------------------------------

int main() {
    
    printBookPart(getTextLocation(BookPartsLocation::intro));
    
    printMainMenu();
    int choise{selectFromMainMenu()};

    Question qusetion{};

    switch (choise)
    {
    case 0:
        qusetion = getQuestion();
        printQuestion(qusetion);
        parallelCoinToss();
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