#pragma once
#include "Util.h"
#include "Common.h"
#include "CamiBase.h"
#include "MapaBase.h"

class MapaSolucio : public MapaBase {
public:
	MapaSolucio() {};

	void getPdis(std::vector<PuntDeInteresBase*>& vector);
	void getCamins(std::vector<CamiBase*>&);
	void parsejaXmlElements(std::vector<XmlElement>& xmlElements);

	CamiBase* buscaCamiMesCurt(PuntDeInteresBase* desde, PuntDeInteresBase* a);

private:
	std::vector<PuntDeInteresBase*> m_PuntsDeInteres;
	std::vector<CamiBase*> m_CamiBase;
};