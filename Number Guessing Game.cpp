#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;

enum enGuessDiff
{
	High = 1,
	Low = 2,
	Equal = 3
};

struct stRound
{
	int userGuess = 0;
	int computerGuess = 0;
	enGuessDiff isCorrectGuess{};
};

struct stGame
{
	int numberOfRounds = 0;
	int bestScore = 0;
};

int readValidateUserInput(int from,int to)
{
	int number = 0;
	cout << "\n\tPlease Enter Your Guess Number from 1 to 100 : ";

	while (!(cin >> number) || number < from || number > to)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "\n\tWrong DataType, Can You Please Enter You Guess Number Again : ";
	}

	return number;
}

int randomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void printGameHeader()
{
	cout << "\n\t========================================\n";
	cout << "\t	Number Guessing Game\n";
	cout << "\t========================================\n";
	cout << "\n\tI'm thinking of a number between 1-100.\n";
	cout << "\tCan you guess it ? \n\n";
}

enGuessDiff whatGuess(int computerGuess, int userGuess)
{
	if (userGuess > computerGuess)
		return enGuessDiff::High;
	else if (userGuess < computerGuess)
		return enGuessDiff::Low;
	else
		return enGuessDiff::Equal;
}

string printGuess(int guess, int x)
{
	string guessesArr[3] = { "\n\tToo High! Try lower.","\n\tToo Low! Try higher.","\n\tCorrect! You got it in " + to_string(x) + " attempts!" };
	return guessesArr[guess - 1];
}

void updateScore(int& bestScore, int rounds)
{
	if (bestScore == 0 || rounds < bestScore)
		bestScore = rounds;
}

void playRound(stGame& game)
{
	stRound round{};
	int rounds = 0;

	round.computerGuess = randomNumber(1, 100);

	do
	{
		round.userGuess = readValidateUserInput(1,100);
		round.isCorrectGuess = whatGuess(round.computerGuess, round.userGuess);
		cout << printGuess(static_cast<int>(round.isCorrectGuess), ++rounds);

		if (round.isCorrectGuess == enGuessDiff::Equal)
			updateScore(game.bestScore, rounds);

		updateScore(game.bestScore, rounds);

	} while (round.isCorrectGuess != enGuessDiff::Equal);
}

void playGame()
{
	char play = 'y';
	stGame game{};

	printGameHeader();
	
	do
	{
		cout << "\n\n========================================================\n\n";
		playRound(game);
		

		cout << "\n\tBest Score So Far: " << game.bestScore << " attempts.\n\n";

		cout << "\tPlay Again ? [Y/N] : ";
		cin >> play;
	} while (tolower(play) == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	playGame();
}