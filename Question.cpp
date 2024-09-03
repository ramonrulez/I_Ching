#pragma once

#include <iostream>
#include <string>
#include "CinCleanup.cpp"

class Question
{
    private:
        std::string m_question{};

    public:
        Question(std::string q) :
            m_question{q}
            {}

        Question() :
            m_question{""}
            {}

        std::string_view getQuestion() {return m_question;}  
};

std::istream& operator>>(std::istream& in, Question& question)
{
    std::string q{};

    in >> q;

    if(in)
        question = q;

    return in;
}

std::ostream& operator<<(std::ostream& out, Question& question)
{
    out << question.getQuestion();
    return out;
}

Question getQuestionFromUser()
{
    std::cout << "\nGive the question: \n";

    ignoreLine(); // Clean the cin otherwise it doesn't stay in the getline() 
    std::string question{};
    std::getline(std::cin, question);
    
    return {question};
}

bool isTheQuestionCorrect(Question& question)
{
    system("clear"); // Linux command for clearing the terminal
    while (true)
    {
        std::cout << '\n' << question << '\n';
        std::cout << "Is this question right [Y/N]? ";
        char answer{};
        std::cin >> answer;

        if (clearFailedExtraction() || clearExtraInput() ||
                !(answer == 'Y' || answer == 'N'))
            {
                system("clear");
                std::cout << "Wrong input. Try again!\n";
                continue;
            }
        
        if (answer == 'Y')
            return true;

        break;
    }

    return false;
}