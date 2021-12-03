#include <string>
#include "Question.h"

namespace MathsQuiz {

	std::string Question::NextLongMultiplication()
	{
		m_LongMultiplication[0] = RandomNumber(101, 2500);
		m_LongMultiplication[1] = RandomNumber(5, 99);

		std::string output = " Your long multiplication question is\n";
		output += " " + std::to_string(m_LongMultiplication[0]) + " x " + std::to_string(m_LongMultiplication[1]);

		return output;
	}

	std::string Question::NextShortDivision()
	{
		m_ShortDivision[0] = RandomNumber(101, 2500);
		m_ShortDivision[1] = RandomNumber(1, 9);

		std::string output = " Your short division question is\n";
		output += " " + std::to_string(m_ShortDivision[0]) + " " + char(246) + " " + std::to_string(m_ShortDivision[1]);

		return output;


		return " Your short division question: ";
	}

	std::string Question::LongMultiplicationAnswer()
	{
		std::string output = " The answer is " + std::to_string(m_LongMultiplication[0] * m_LongMultiplication[1]);

		return output;
	}

	std::string Question::ShortDivisionAnswer()
	{
		int remainder = m_ShortDivision[0] % m_ShortDivision[1];
		int answer = (m_ShortDivision[0] - remainder) / m_ShortDivision[1];

		std::string output = " The answer is " + std::to_string(answer);
		if (remainder > 0) 
		{
			output += ", remainder " + std::to_string(remainder);
		}

		return output;
	}
}