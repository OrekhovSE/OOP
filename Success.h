#pragma once
#include "Choice.h"

class Success : public Choice {
public:
	Success() {
		endPhrase = "won, prize = ";
	}

	Success(string p_endPhrase) {
		endPhrase = p_endPhrase;
	}

	int CalculateTheWinnings(int a) override {
		return a * (rand() % 20 + 2);
	}
};

