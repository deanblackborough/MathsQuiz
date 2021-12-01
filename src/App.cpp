#include <iostream>
#include "Question.h"

int main()
{
	char quit = {};
	int question_type = {};
	bool quizz = { true };

	std::cout << "Welcome to MathsQuizz" << std::endl;
	std::cout << "Time for some maths questions!" << std::endl;
	std::cout << std::endl;

	while (quizz == true)
	{
		MathsQuizz::Question question{};
			
		std::cout << "Please choose the question type" << std::endl;
		std::cout << "--- Enter 1 for Long multiplication:" << std::endl;
		std::cout << "--- Enter 2 for Short division:" << std::endl;
		std::cin >> question_type;

		if (question_type == static_cast<int>(MathsQuizz::Question::QuestionType::LongMultiplication))
		{
			question.SetType(MathsQuizz::Question::QuestionType::LongMultiplication);
		}
		else if (question_type == static_cast<int>(MathsQuizz::Question::QuestionType::ShortDivison))
		{
			question.SetType(MathsQuizz::Question::QuestionType::ShortDivison);
		}
		else
		{
			std::cout << "Oops, you selected an option not shown, I'm going to pick an option for you!" << std::endl;
			question.SetType(MathsQuizz::Question::QuestionType::LongMultiplication);
		}

		// Question
		std::cout << question.NextQuestion() << std::endl;;

		std::cout << "Do you want another question? (y/n)" << std::endl;
		std::cin >> quit;
		if (quit == 'n')
		{
			std::cout << "Bye bye!" << std::endl;
			quizz = false;
		}
	}

	return 0;
}