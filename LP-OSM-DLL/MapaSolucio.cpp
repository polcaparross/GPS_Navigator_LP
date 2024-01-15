#include "pch.h"
#include "Common.h"
#include "Util.h"
#include "MapaSolucio.h"
#include "PuntDeInteresBase.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include <vector>
#include <string>


//IMPLEMENTACIO CLASSE DERIVADA MAPASOLUCIO

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& vector) {
	vector.clear();
	for (auto it = m_PuntsDeInteres.begin(); it != m_PuntsDeInteres.end(); it++) {
		vector.push_back((*it));
	}
}

void MapaSolucio::getCamins(std::vector<CamiBase*>& vector) {
	vector.clear();
	for (auto it = m_CamiBase.begin(); it != m_CamiBase.end(); it++) {
		vector.push_back((*it));
	}

}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements) {
	/* m_CamiBase.clear();
	m_PuntsDeInteres.clear();

	string highway, access, publicTransport, entrance, cuisine, amenity, shop, nom, adaptat;
	double lat, lon;

	for (int i=0; i < xmlElements.size(); i++) {

		highway = "", access = "", publicTransport = "", entrance = "", cuisine = "", amenity = "", shop = "", nom = "";
		lat = 0; lon = 0;
		Coordinate c;

		if (xmlElements[i].id_element == "node")
		{
			for (int j = 0; j < xmlElements[i].atributs.size(); j++)
			{
				if (xmlElements[i].atributs[j].first == "lat")
					lat = stod(xmlElements[i].atributs[j].second);
				else if (xmlElements[i].atributs[j].first == "lon")
					lon = stod(xmlElements[i].atributs[j].second);
			}

			c.lat = lat;
			c.lon = lon;

			for (int j = 0; j < xmlElements[i].fills.size(); j++) {
				if (xmlElements[i].fills[j].first == "tag") {
					pair<string, string> valorTag = Util::kvDeTag(xmlElements[i].fills[j].second);
					if (valorTag.first == "highway") {
						highway = valorTag.second;
					}
					else if (valorTag.first == "access") {
						access = valorTag.second;
					}
					else if (valorTag.first == "entrance") {
						entrance = valorTag.second;
					}
					else if (valorTag.first == "public_transport") {
						publicTransport = valorTag.second;
					}
					else if (valorTag.first == "shop")
					{
						shop = valorTag.second;
					}
					else if (valorTag.first == "name")
					{
						nom = valorTag.second;
					}
					else if (valorTag.first == "amenity") {
						amenity = valorTag.second;
					}
					else if ((valorTag.first == "wheelchair") && (valorTag.second == "yes")) {
						if (valorTag.first == "cuisine") {
							cuisine = valorTag.second;
						}
						else if (valorTag.first == "wheelchair" && valorTag.second == "yes") {
							adaptat = "yes";
						}
					}
				}
			}
			PuntDeInteresBase* p;
			if ((amenity == "restaurant") && (nom != "") && (highway == "") && (publicTransport == "") && (entrance == "") && (access == "")) {
				p = new PuntDeInteresRestaurantSolucio(c, nom, cuisine, adaptat);
				m_PuntsDeInteres.push_back(p);
			}
			else if ((nom != "") && (shop != "") && (publicTransport == "") && (entrance == "") && (highway == "") && (access == "") && ((amenity != "cafe") || (amenity != "restaurant"))) {
				p = new PuntDeInteresBotigaSolucio(c, nom, shop, entrance, adaptat);
				m_PuntsDeInteres.push_back(p);
			}
		}
		else if (xmlElements[i].id_element == "way")  {

			CamiSolucio* cami = new CamiSolucio;
			Coordinate c2;

			for (int j = 0; j < xmlElements[i].fills.size(); j++) {

				if (xmlElements[i].fills[j].first == "tag") {

					pair<string, string> valorTag = Util::kvDeTag(xmlElements[i].fills[j].second);

					if (valorTag.first == "highway") {
						highway = valorTag.second;
					}
					if (valorTag.first == "name") {
						nom = valorTag.second;
					}
				}
			}
			if (highway != "") {

				for (int j = 0; j < xmlElements[i].fills.size(); j++) {

					if (xmlElements[i].fills[j].first == "nd") {

						string id2 = xmlElements[i].fills[j].second[0].second;

						int k = 0;
						bool trobat = false;
						while ((k < xmlElements.size()) && (!trobat)) {
							for (int l = 0; l < xmlElements[k].atributs.size(); l++) {
								if ((xmlElements[k].atributs[l].first == "id") && (xmlElements[k].atributs[l].second == id2)) {
									trobat = true;
								}


								else if (trobat) {
									if (xmlElements[k].atributs[l].first == "lat") {
										lat = stod(xmlElements[k].atributs[l].second);
									}

									else if (xmlElements[k].atributs[l].first == "lon")
									{
										lon = stod(xmlElements[k].atributs[l].second);
									}

								}
							}
							k++;
						}
						c2.lat = lat;
						c2.lon = lon;
						cami->setCamiCoords(c2);
					}
				}
				m_CamiBase.push_back(cami);
			}
		}
	}
	*/

	m_CamiBase.clear();
	m_PuntsDeInteres.clear();

	std::string highway, access, publicTransport, entrance, cuisine, amenity, shop, nom, adaptat, openingHours;
	double lat, lon;

	for (auto it = xmlElements.begin(); it != xmlElements.end(); it++) {

		highway = "", access = "", publicTransport = "", entrance = "", cuisine = "", amenity = "", shop = "", nom = "", adaptat = "", openingHours = "";
		lat = 0; lon = 0;
		Coordinate c;

		if (it->id_element == "node") {
			for (int i = 0; i < it->atributs.size(); i++) {
				if (it->atributs[i].first == "lat")
					lat = stod(it->atributs[i].second);
				else if (it->atributs[i].first == "lon")
					lon = stod(it->atributs[i].second);
			}

			c.lat = lat;
			c.lon = lon;

			for (int i = 0; i < it->fills.size(); i++) {
				if (it->fills[i].first == "tag") {
					std::pair<std::string, std::string> valorTag = Util::kvDeTag(it->fills[i].second);
					if (valorTag.first == "highway") {
						highway = valorTag.second;
					}
					else if (valorTag.first == "access") {
						access = valorTag.second;
					}
					else if (valorTag.first == "entrance") {
						entrance = valorTag.second;
					}
					else if (valorTag.first == "public_transport") {
						publicTransport = valorTag.second;
					}
					else if (valorTag.first == "shop") {
						shop = valorTag.second;
					}
					else if (valorTag.first == "opening_hours") {
						openingHours = valorTag.second;
					}
					else if (valorTag.first == "name") {
						nom = valorTag.second;
					}
					else if (valorTag.first == "amenity") {
						amenity = valorTag.second;
					}
					else if (valorTag.first == "cuisine") {
						cuisine = valorTag.second;
					}
					else if (valorTag.first == "wheelchair" && valorTag.second == "yes") {
						adaptat = "yes";
					}
				}
			}
			PuntDeInteresBase* p;
			if ((amenity == "restaurant") && (nom != "") && (highway == "") && (publicTransport == "") && (entrance == "") && (access == "")) {
				p = new PuntDeInteresRestaurantSolucio(c, nom, cuisine, adaptat);
				m_PuntsDeInteres.push_back(p);
			}
			else if ((nom != "") && (shop != "") && (publicTransport == "") && (entrance == "") && (highway == "") && (access == "") && ((amenity != "cafe") || (amenity != "restaurant"))) {
				p = new PuntDeInteresBotigaSolucio(c, nom, shop, openingHours, adaptat);
				m_PuntsDeInteres.push_back(p);
			}
			else if ((nom != "") && (publicTransport == "") && (entrance == "") && (highway == "") && (access == "")) {
				p = new PuntDeInteresBase(c, nom);
				m_PuntsDeInteres.push_back(p);
			}

		}
		else if (it->id_element == "way") {

			CamiSolucio* cami = new CamiSolucio;
			Coordinate c2;

			for (int i = 0; i < it->fills.size(); i++) {

				if (it->fills[i].first == "tag") {

					std::pair<std::string, std::string> valorTag = Util::kvDeTag(it->fills[i].second);

					if (valorTag.first == "highway") {
						highway = valorTag.second;
					}
					if (valorTag.first == "name") {
						nom = valorTag.second;
					}
				}
			}
			if (highway != "") {

				for (int i = 0; i < it->fills.size(); i++) {

					if (it->fills[i].first == "nd") {

						std::string id2 = it->fills[i].second[0].second;

						auto it2 = xmlElements.begin();
						bool trobat = false;
						while ((it2 < xmlElements.end()) && (!trobat)) {
							for (int j = 0; j < it2->atributs.size(); j++) {
								if ((it2->atributs[j].first == "id") && (it2->atributs[j].second == id2)) {
									trobat = true;
								}
								else if (trobat) {
									if (it2->atributs[j].first == "lat") {
										lat = stod(it2->atributs[j].second);
									}
									else if (it2->atributs[j].first == "lon")
									{
										lon = stod(it2->atributs[j].second);
									}

								}
							}
							it2++;
						}
						c2.lat = lat;
						c2.lon = lon;
						cami->setCamiCoords(c2);
					}
				}
				m_CamiBase.push_back(cami);
			}
		}
	}

}

CamiBase* MapaSolucio::buscaCamiMesCurt(PuntDeInteresBase* desde, PuntDeInteresBase* a) {
	//FER
	return 0;
}