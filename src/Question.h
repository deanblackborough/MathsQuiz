#pragma once

#include <iostream>

namespace MathsQuiz {
    
    class Question
    {
    public:
        enum class QuestionType : int
        {
            LongMultiplication = 1,
            ShortDivison = 2
        };

    private:
        QuestionType m_QuestionType;

        int m_LongMultiplication[2];
        int m_ShortDivision[2];

        int m_LongMultiplicationAnswer;
        int m_ShortDivisionAnswer[2];

    public:
        void SetType(QuestionType questionType)
        {
            m_QuestionType = questionType;
        }

        std::string NextQuestion()
        {
            if (m_QuestionType == QuestionType::LongMultiplication)
            {
                return NextLongMultiplication();
            }
            else
            {
                return NextShortDivision();
            }
        }

        void UserAnswer();

        std::string Answer()
        {
            if (m_QuestionType == QuestionType::LongMultiplication)
            {
                return LongMultiplicationAnswer();
            }
            else
            {
                return ShortDivisionAnswer();
            }
        }

        std::string Solution();

    private:
        std::string NextLongMultiplication();

        std::string NextShortDivision();

        std::string LongMultiplicationAnswer();

        std::string ShortDivisionAnswer();

        int RandomNumber(int min, int max)
        {
            return min + (rand() % static_cast<int>(max - min + 1));
        }
    };
}