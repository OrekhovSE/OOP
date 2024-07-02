#pragma once
#include <string>

using namespace std;

class Choice
{
public:
	string startPhrase = "You have ";
	string endPhrase = "";

	virtual int CalculateTheWinnings(int) = 0;
};

