#include "pch.h"
#include "Common.h"
#include "CamiBase.h"
#include <vector>

//IMPLEMENTACIO CLASSE BASE CAMIBASE
void CamiSolucio::setCamiCoords(const Coordinate c)
{
	m_vector.push_back(c);
}

//IMPLEMENTACIO CLASSE DERIVADA CAMISOLUCIO
std::vector<Coordinate> CamiSolucio::getCamiCoords() { //Aqui estaba con m_vector
	return m_vector;
}