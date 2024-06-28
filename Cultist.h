#pragma once
#include <string>

using namespace std;

class Cultist
{
public:
	string name = "cultist";
	string lastWord;
	bool sacrifice = false;

	virtual bool sacrificing() = 0;
};

