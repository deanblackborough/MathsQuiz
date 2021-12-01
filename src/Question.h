#pragma once

#include <iostream>

class Question
{
public:
	enum QuestionType : int
	{
		LongMultiplication = 1, 
		ShortDivison = 2
	};

private:
	QuestionType m_QuestionType;

	int m_LongMultiplication[2];
	int m_ShortDivision[2];

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

	std::string Answer();

	std::string Solution();

private:
	std::string NextLongMultiplication();

	std::string NextShortDivision();
};