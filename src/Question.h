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

        int m_LongMultiplicationUserAnswer;
        int m_ShortDivisionUserAnswer[2];

        int m_LongMultiplicationCorrect;
        int m_ShortDivisionCorrect;

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

        void UserAnswer()
        {
            if (m_QuestionType == QuestionType::LongMultiplication)
            {
                LongMultiplicationUserAnswer();
            }
            else
            {
                ShortDivisionAnswerUserAnswer();
            }
        }

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

        int Correct()
        {
            if (m_QuestionType == QuestionType::LongMultiplication)
            {
                return m_LongMultiplicationCorrect;
            }
            else
            {
                return m_ShortDivisionCorrect;
            }
        }

        std::string Solution()
        {
            if (m_QuestionType == QuestionType::LongMultiplication)
            {
                return LongMultiplicationSolution();
            }
            else
            {
                return ShortDivisionSolution();
            }
        }

    private:
        std::string NextLongMultiplication();

        std::string NextShortDivision();

        std::string LongMultiplicationAnswer();

        std::string ShortDivisionAnswer();

        std::string LongMultiplicationSolution();

        std::string ShortDivisionSolution();

        void LongMultiplicationUserAnswer();

        void ShortDivisionAnswerUserAnswer();

        int RandomNumber(int min, int max)
        {
            return min + (rand() % static_cast<int>(max - min + 1));
        }
    };
}