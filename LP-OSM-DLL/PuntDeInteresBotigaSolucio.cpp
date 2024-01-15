#include "pch.h"
#include "PuntDeInteresBase.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "Util.h"

//CLASSE DERIVADA BOTIGA
PuntDeInteresBotigaSolucio::PuntDeInteresBotigaSolucio(Coordinate coord, string name, string shop, string openingHours, string wheelchair) : PuntDeInteresBase(coord, name)
{
	t_shop = shop;
	t_openingHours = openingHours;
	t_wheelchair = wheelchair;
}

Coordinate PuntDeInteresBotigaSolucio::getCoord() {
	return (PuntDeInteresBase::getCoord());
}

string PuntDeInteresBotigaSolucio::getName() {
	return (PuntDeInteresBase::getName());
}

unsigned int PuntDeInteresBotigaSolucio::getColor() {
	size_t substring_length;
	substring_length = t_openingHours.find("06:00-22:00");
	if (t_shop == "supermarket")
		return 0xA5BE00;
	else if (t_shop == "tobacco")
		return 0xFFAD69;
	else if ((t_shop == "bakery") && (substring_length != string::npos) && (t_wheelchair == "yes"))
		return 0x4CB944;
	else if (t_shop == "bakery")
		return 0xE85D75;
	else
		return 0xEFD6AC;
}