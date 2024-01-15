#pragma once

#include <string>
#include "Common.h"
#include "PuntDeInteresBase.h"
#include <iostream>
using namespace std;

class PuntDeInteresBotigaSolucio : public PuntDeInteresBase
{
public:
	PuntDeInteresBotigaSolucio() {}
	PuntDeInteresBotigaSolucio(Coordinate coord, string name, string shop, string openintHours, string wheelchair);
	Coordinate getCoord();
	string getName();
	unsigned int getColor();
private:
	string t_shop;
	string t_openingHours;
	string t_wheelchair;
};