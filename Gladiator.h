#pragma once
#include <iostream> 
#include "SlotMachine.h"
using namespace std;

class Gladiator : public SlotMachine {
private:
	int price = 0;
public:
	Gladiator() {};
	Gladiator(int p_price) : price(p_price) {};

	void play(int bet) override {
		if (!choices.empty()) {
			int number = rand() / choices.size();
			Choice* choice = choices.get(number);

			int winning = choice->CalculateTheWinnings(bet);
			if (winning < bet) {
				price += bet;
				cout << choice->startPhrase << choice->endPhrase << winning << endl;
				choices.deleteNode(number);
			}
			else {
				cout << choice->startPhrase << choice->endPhrase << winning + price << endl;
				choices.deleteNode(number);
				price = 0;
			}
		}
		else {
			cout << "Gladiator requires recharging" << endl;
		}

	}

	void addChoice(Choice* c) override {
		choices.insertNode(c);
	}
};

