#pragma once
#include <iostream> 
#include "Shalter.h"
using namespace std;

class IceShalter : public Shalter {
public:
	void ice() {
		std::cout << "ice" << std::endl;
	}

	void sacrificing(int count) override {
		ice();
		int i = 2;
		while (count != 0) {
			if (cultists.get(i)->sacrificing()) {
				cout << cultists.get(i)->name << " will be sacraficed, last words are " << cultists.get(i)->lastWord << endl;
				cultists.deleteNode(i);
				count = 0;
			}
			if (count > 0)
				count--;
		}

		

	}

	void addCultist(Cultist* c) override {
		cultists.insertNode(c);
	}
};

