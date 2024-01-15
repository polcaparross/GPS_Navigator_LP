#include "pch.h"
#include "GrafSolucio.h"
#include "iomanip"
using namespace std;

GrafPonderat::GrafPonderat() {
	m_numNodes = 0;
	m_numArestes = 0;
	m_nodes.resize(0);
	m_matriuAdj.resize(0);
}

GrafPonderat::GrafPonderat(const vector<Coordinate>& nodes, const vector<vector<int>>& parelles_nodes, int numNodes, const vector<double>& pesos)
{
	m_nodes = nodes;
	m_numNodes = m_nodes.size();
	m_numArestes = parelles_nodes.size();
	crearMatriu(parelles_nodes, pesos);
}

GrafPonderat::~GrafPonderat() {
}

void GrafPonderat::afegirAresta(int origen, int desti) {
	double distancia = Util::DistanciaHaversine(m_nodes[origen], m_nodes[desti]);

	//if ((posNode1 < m_numNodes) && (posNode2 < m_numNodes) && (posNode1 >= 0) && (posNode2 >= 0)) {
	m_matriuAdj[origen][desti] = distancia;	
	m_matriuAdj[desti][origen] = distancia;
	m_numArestes++;
	//}
}

void GrafPonderat::afegirNode(Coordinate& node) {
	m_nodes.push_back(node); //añadimos el nodo al vector de nodos
	m_matriuAdj.push_back(vector<int>(m_numNodes)); //añadimos su fila en la matriz de adyacencia
	m_numNodes++;

	for (int i = 0; i < m_numNodes; i++) 
		m_matriuAdj[i].push_back(0); //rellenamos la fila con 0.
}

void GrafPonderat::crearMatriu(const vector<vector<int>>& parelles, const vector<double>& pesos)
{
	m_matriuAdj.resize(m_numNodes); //creamos las columnas que necesitamos
	for (int i = 0; i < m_numNodes; i++) {
		m_matriuAdj[i].resize(m_numNodes, 0); //creamos las filas que necesitamos todo a 0. 
	}
	for (int i = 0; i < parelles.size(); i++) {
		m_matriuAdj[parelles[i][0]][parelles[i][1]] = pesos[i]; //el vector parelles contiene los nodos que están conectados. (0,1) el 0 y el 1 tienen una arista por lo que habrá que acceder a esas posiciones.
		m_matriuAdj[parelles[i][1]][parelles[i][0]] = pesos[i]; //como nuetro grafo es imetrico tambien será al reves.
	}
}

//no se cómo relacionar los nodos de MapaSolucio con la matriz y la distancia haversine y como meterlo en la matriz.