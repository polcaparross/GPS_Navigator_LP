#pragma once

#include "Common.h"
#include <vector>

class CamiBase {
public:
	virtual std::vector<Coordinate> getCamiCoords() = 0;
	virtual void setCamiCoords(const Coordinate c) = 0;
protected:
	std::vector<Coordinate> m_vector;
};

class CamiSolucio : public CamiBase {
public:
	void setCamiCoords(const Coordinate c);
	std::vector<Coordinate> getCamiCoords();
};