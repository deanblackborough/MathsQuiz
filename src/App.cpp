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
		std::cout << " Please choose a question type" << std::endl;
		std::cout << " - Enter 1 for Long multiplication:" << std::endl;
		std::cout << " - Enter 2 for Short division:" << std::endl;
		std::cout << " * More options are coming soon(tm)" << std::endl << std::endl;

		while (
			!(std::cin >> question_type) || 
			question_type < 1 || 
			question_type > 2
		) {
			std::cout << "Oops, you selected an option not shown, please try again!";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		MathsQuiz::Question question{};

		std::cout << question_type << std::endl;
		
		if (question_type == static_cast<int>(MathsQuiz::Question::QuestionType::LongMultiplication))
		{
			question.SetType(MathsQuiz::Question::QuestionType::LongMultiplication);
		}
		else 
		{
			question.SetType(MathsQuiz::Question::QuestionType::ShortDivison);
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