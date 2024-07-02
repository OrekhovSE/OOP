#pragma once
#include "Choice.h"

class Failure : public Choice {
public:
	Failure() {
		endPhrase = "lost, ñonsolation prize = ";
	}

	Failure(string p_EndPhrase) {
		endPhrase = p_EndPhrase;
	}

	int CalculateTheWinnings(int a) override{
		return a * 0.15;
	}
};

