#include "Puzzle.h"

Puzzle::Puzzle(std::string fileName)
{
	this->correctAnswer = 0;

	std::ifstream inFile(fileName);

	int nrOfAnswers = 0;
	std::string answer = "";
	int correctAnswer = 0;

	if (inFile.is_open())
	{
		std::getline(inFile, this->question);
		inFile >> nrOfAnswers;
		inFile.ignore();

		for (size_t i = 0; i < nrOfAnswers; i++)
		{
			std::getline(inFile, answer);
			this->answers.push_back(answer);
		}

		inFile >> correctAnswer; 
		this->correctAnswer = correctAnswer;
		inFile.ignore();
	}
	else
		throw("Could not open puzzle");

	inFile.close();
}

Puzzle::~Puzzle()
{

}

std::string Puzzle::getAsString()
{
	std::string answers = "";

	for (size_t i = 0; i < this->answers.size(); i++)
	{
		answers += std::to_string(i) + ": " + this->answers[i] + "\n";
	}

	//return this->question + "\n" + "\n"
	//	+ answers + "\n"
	//	+ std::to_string(this->correctAnswer) + "\n";

	return this->question + "\n" + "\n"
		+ answers + "\n";
}

