#include <iostream>

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
		std::cout << "Please choose the question type" << std::endl;
		std::cout << "--- Enter 1 for Long multiplication:" << std::endl;
		std::cout << "--- Enter 2 for Short division:" << std::endl;
		std::cin >> question_type;

		if (question_type == 1)
		{
			std::cout << "Your long multiplication question is: " << std::endl;
		}
		else if (question_type == 2)
		{
			std::cout << "Your short division question is: " << std::endl;
		}
		else
		{
			std::cout << "Oops, you selected an option not shown, I'm going to pick an option for you!" << std::endl;
			question_type = 1;
			std::cout << "Your long multiplication question is: " << std::endl;
		}

		// Question



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