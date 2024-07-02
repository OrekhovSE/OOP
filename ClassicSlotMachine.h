#pragma once
#include <iostream>
#include "SlotMachine.h"
using namespace std;

class ClassicSlotMachine : public SlotMachine {
private:
	int exten = 2;
public:
	ClassicSlotMachine() {};
	ClassicSlotMachine(int p_exten) : exten(p_exten) {};


	void play(int bet) override {
		if (!choices.empty()) {
			int number = rand() / choices.size();
			Choice* choice = choices.get(number);

			int winning = choice->CalculateTheWinnings(bet);
			if (winning < bet) {
				cout << choice->startPhrase << choice->endPhrase << winning << endl;
				choices.deleteNode(number);
			}
			else {
				cout << choice->startPhrase << choice->endPhrase << winning * exten << endl;
				choices.deleteNode(number);
			}
		}
		else {
			cout << "ClassicSlotMachine requires recharging" << endl;
		}
	}

	void addChoice(Choice* c) override {
		choices.insertNode(c);
	}
};

