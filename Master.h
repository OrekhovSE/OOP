#pragma once
#include "Cultist.h"

class Master : public Cultist {
private:
	int health = 3;
public:
	Master() {
		name = "I am master";
		lastWord = "Master";
	}

	Master(string a, string p_name) {
		lastWord = a;
		name = p_name;
	}

	bool sacrificing() override {
		health--;
		return health < 0;
	}
};

