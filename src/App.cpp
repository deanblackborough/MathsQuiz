#include <iostream>
#include "Question.h"

int main()
{
    char showSolution = {};
    char quit = {};
    int questionType = {};
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
            !(std::cin >> questionType) || 
            questionType < 1 || 
            questionType > 2
        ) {
            std::cout << " Oops, you selected an option not shown, please try again!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        MathsQuiz::Question question{};
                
        if (questionType == static_cast<int>(MathsQuiz::Question::QuestionType::LongMultiplication))
        {
            question.SetType(MathsQuiz::Question::QuestionType::LongMultiplication);
        }
        else 
        {
            question.SetType(MathsQuiz::Question::QuestionType::ShortDivison);
        }

        // Question
        std::cout << std::endl << question.NextQuestion() << std::endl;

        // User answer
        std::cout << " What is the result?" << std::endl;

        question.UserAnswer();

        if (question.Correct() == 1)
        {
            std::cout << " Well done, you got that right!" << std::endl;
        }
        else
        {
            std::cout << " Nice try but not quite!" << std::endl << std::endl;
            std::cout << question.Answer() << std::endl;

            std::cout << " Would you like to see the solution? (y/N)" << std::endl;
            std::cin >> showSolution;
            if (showSolution == 'y')
            {
                std::cout << " [SHOW THE SOLUTION HERE]" << std::endl;
            }
        }

        std::cout << " Do you want another question? (Y/n)" << std::endl;
        std::cin >> quit;
        if (quit == 'n')
        {
            std::cout << std::endl << " Bye bye!" << std::endl;
            quizz = false;
        }
    }

    return 0;
}