#pragma once

#include <iostream>
#include <string>

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

        std::string getQuestion() {return m_question;}  
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
    std::cout << "\nGive the question:\n";

    std::string question{};
    std::getline(std::cin, question);
    
    return {question};
}