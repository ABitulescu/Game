#pragma once
#include <string>
#include <vector>
#include<fstream>
#include<iostream>


class Puzzle
{
private:
	std::string question;
	std::vector<std::string> answers;
	int correctAnswer;

public:
	Puzzle(std::string fileName);
	virtual ~Puzzle();
	std::string getAsString();

	inline const int& getCorrectAnswer()const { return this->correctAnswer;  }
};

