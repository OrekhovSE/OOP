#pragma once
#include <iostream>
#include "Shalter.h"

using namespace std;
class FireShalter : public Shalter {
public:
	void fire() {
		cout << "fire" << endl;
	}

	void sacrificing(int count) override{
		fire();
		int i = 0;
		while (count != 0 && cultists.getHead() != NULL) {
			if (cultists.get(i)->sacrificing()) {
				cout << cultists.get(i)->name << " will be sacraficed, last words are " << cultists.get(i)->lastWord << endl;
				count--;
			}
			i += 3; 
		}
	}

	void addCultist(Cultist* c) override {
		cultists.insertNode(c);
	}
};

