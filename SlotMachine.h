#pragma once
#include "Choice.h"
#include "LinkedList.hpp"

class SlotMachine
{
public:
	LinkedList<Choice*> choices;

	virtual void play(int) = 0;
	virtual void addChoice(Choice* c) = 0;
};

