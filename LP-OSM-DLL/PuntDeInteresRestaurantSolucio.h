#pragma once

#include <string>
#include "Common.h"
#include "PuntDeInteresBase.h"
#include <iostream>
using namespace std;

class PuntDeInteresRestaurantSolucio : public PuntDeInteresBase
{
public:
	PuntDeInteresRestaurantSolucio();
	PuntDeInteresRestaurantSolucio(Coordinate coord, string name, string cuisine, string wheelchair);
	Coordinate getCoord();
	string getName();
	unsigned int getColor();
private:
	string t_cuisine;
	string t_wheelchair;
};