#pragma once

#include <string>
#include "Common.h"
#include <iostream>
using namespace std;

class PuntDeInteresBase
{
public:
	PuntDeInteresBase();
	PuntDeInteresBase(Coordinate coord, string name);

	virtual string getName();
	virtual Coordinate getCoord();
	virtual unsigned int getColor();
protected:
	Coordinate m_coord;
	string m_name;
};


