#include "pch.h"
#include "PuntDeInteresBase.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "Util.h"

//CLASSE DERIVADA RESTAURANT
PuntDeInteresRestaurantSolucio::PuntDeInteresRestaurantSolucio()
{
	t_cuisine = "INDEFINIT";
	t_wheelchair = "INDEFINIT";
}

PuntDeInteresRestaurantSolucio::PuntDeInteresRestaurantSolucio(Coordinate coord, string name, string cuisine, string wheelchair) : PuntDeInteresBase(coord, name)
{
	t_cuisine = cuisine;
	t_wheelchair = wheelchair;
}

Coordinate PuntDeInteresRestaurantSolucio::getCoord()
{
	//return m_coord;
	return (PuntDeInteresBase::getCoord());
}

string PuntDeInteresRestaurantSolucio::getName()
{
	return (PuntDeInteresBase::getName());
}

unsigned int PuntDeInteresRestaurantSolucio::getColor()
{
	if (t_cuisine == "pizza" && t_wheelchair == "yes")
		return 0x03FCBA;
	else if (t_cuisine == "chinese")
		return 0xA6D9F7;
	else if (t_wheelchair == "yes")
		return 0x251351;
	else
		return PuntDeInteresBase::getColor();
}