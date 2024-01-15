#pragma once
#include "pch.h"
#include "Common.h"
#include "MapaSolucio.h"

class GrafPonderat
{
public:
	GrafPonderat();
	GrafPonderat(const vector<Coordinate>& nodes, const vector<vector<int>>& matriu_adj, int numNodes, const vector<double>& pesos);
	~GrafPonderat();
	int getNumNodes() { return m_numNodes; }
	void afegirAresta(int posNode1, int posNode2);
	void afegirNode(Coordinate& c);
	
private:
	vector<Coordinate> m_nodes; //els nodes seran els nodes de cami que heu llegit i desat a CamiSolucio (en CamiBase tenemos el vector de Coordenadas de lso puntos del camino)
	vector<vector<int>> m_matriuAdj; //Hi haura un 1 a la matriu si hi ha una aresta entre dos nodes. Hi ha aresta si hi ha connexio entre aquests nodes. A MapaSolucio teniu el conjunt de camins (a MapaSolucio hi ha un vector de camins base). Si a un cami hi han els dos nodes, vol dir que hi ha cami entre ells.
	int m_numNodes;
	int m_numArestes;
	void crearMatriu(const vector<vector<int>>& parelles, const vector<double>& pesos);

};