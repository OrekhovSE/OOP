#pragma once
#include "Cultist.h"
#include "LinkedList.hpp"

class Shalter
{
public:
	LinkedList<Cultist*> cultists;

	virtual void sacrificing(int) = 0;
	virtual void addCultist(Cultist* c) = 0;
};

