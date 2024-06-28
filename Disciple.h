#pragma once
#include "Cultist.h"

class Disciple : public Cultist {
public:
	Disciple() {
		name = " I am Descriple";
		lastWord = "Disciple";
	}

	Disciple(string a, string p_name) {
		lastWord = a;
		name = p_name;
	}

	bool sacrificing() override{
		sacrifice = true;
		return sacrifice;
	}
};

