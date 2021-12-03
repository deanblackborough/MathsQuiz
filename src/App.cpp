#include <iostream>
#include "Question.h"

int main()
{
	char quit = {};
	int question_type = {};
	bool quizz = { true };

	std::cout << R"(
  __  __    _  _____ _   _ ____     ___  _   _ ___ _____
 |  \/  |  / \|_   _| | | / ___|   / _ \| | | |_ _|__  /
 | |\/| | / _ \ | | | |_| \___ \  | | | | | | || |  / / 
 | |  | |/ ___ \| | |  _  |___) | | |_| | |_| || | / /_ 
 |_|  |_/_/   \_\_| |_| |_|____/   \__\_\\___/|___/____|
                                                        
)";

	std::cout << " Time for some Maths!" << std::endl << std::endl;

	while (quizz == true)
	{
		MathsQuiz::Question question{};
			
		std::cout << " Please choose a question type" << std::endl;
		std::cout << " - Enter 1 for Long multiplication:" << std::endl;
		std::cout << " - Enter 2 for Short division:" << std::endl;
		std::cout << " * More options are coming soon(tm)" << std::endl << std::endl;
		std::cin >> question_type;

		if (question_type == static_cast<int>(MathsQuiz::Question::QuestionType::LongMultiplication))
		{
			question.SetType(MathsQuiz::Question::QuestionType::LongMultiplication);
		}
		else if (question_type == static_cast<int>(MathsQuiz::Question::QuestionType::ShortDivison))
		{
			question.SetType(MathsQuiz::Question::QuestionType::ShortDivison);
		}
		else
		{
			std::cout << " Oops, you selected an option not shown, I'm going to pick an option for you!" << std::endl;
			question.SetType(MathsQuiz::Question::QuestionType::LongMultiplication);
		}

		// Question
		std::cout << question.NextQuestion() << std::endl << std::endl;
		std::cout << question.Answer() << std::endl;

		std::cout << " Do you want another question? (y/n)" << std::endl;
		std::cin >> quit;
		if (quit == 'n')
		{
			std::cout << std::endl << " Bye bye!" << std::endl;
			quizz = false;
		}
	}

	return 0;
}