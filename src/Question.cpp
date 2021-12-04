#include <string>
#include "Question.h"

namespace MathsQuiz {

    std::string Question::NextLongMultiplication()
    {
        m_LongMultiplication[0] = RandomNumber(101, 5000);
        m_LongMultiplication[1] = RandomNumber(5, 99);

        std::string spacing (
            static_cast<size_t>(
                std::to_string(m_LongMultiplication[0]).length() - std::to_string(m_LongMultiplication[1]).length()
            ), 
            ' '
        );

        std::string output = " Your long multiplication question is\n";
        output += "   " + std::to_string(m_LongMultiplication[0]) + "\n";
        output += " x " + spacing + std::to_string(m_LongMultiplication[1]) + "\n";

        return output;
    }

    std::string Question::NextShortDivision()
    {
        m_ShortDivision[0] = RandomNumber(101, 10000);
        m_ShortDivision[1] = RandomNumber(3, 9);

        std::string output = " Your short division question is\n";
        output += " " + std::to_string(m_ShortDivision[0]) + " " + char(246) + " " + std::to_string(m_ShortDivision[1]);

        return output;
    }

    std::string Question::LongMultiplicationAnswer()
    {
        m_LongMultiplicationAnswer = m_LongMultiplication[0] * m_LongMultiplication[1];

        std::string output = " The answer is " + std::to_string(m_LongMultiplicationAnswer);

        return output;
    }

    std::string Question::ShortDivisionAnswer()
    {
        m_ShortDivisionAnswer[0] = m_ShortDivision[0] % m_ShortDivision[1]; // Remainder
        m_ShortDivisionAnswer[1] = (m_ShortDivision[0] - m_ShortDivisionAnswer[0]) / m_ShortDivision[1];

        std::string output = " The answer is " + std::to_string(m_ShortDivisionAnswer[1]);
        if (m_ShortDivisionAnswer[0] > 0)
        {
            output += ", remainder " + std::to_string(m_ShortDivisionAnswer[0]);
        }

        return output;
    }
}