#include "pch.h" //QUITAR CUANDO SUBAMOS AL CAORNTE
#include "BallTree.h"


void BallTree::construirArbre(const vector<Coordinate>& coordenades) {
    // TODO: Utilitza aquest metode per construir el teu BallTree
    // TODO: amb les coordenades que se us passen per parametre

    if (coordenades.size() == 1) {
        m_root = this;
    }
    else {

    }

    //INGLES
    /*function construct_balltree is
        input : D, an array of data points.
        output : B, the root of a constructed ball tree.

        if a single point remains then
            create a leaf B containing the single point in D
            return B
        else
            let c be the dimension of greatest spread
            let p be the central point selected considering c
            let L, R be the sets of points lying to the leftand right of the median along dimension c
            create B with two children :
    B.pivot : = p
        B.child1 : = construct_balltree(L),
        B.child2 : = construct_balltree(R),
        let B.radius be maximum distance from p among children
        return B
        end if
        end function*/

    //CASTELLANO
   /* la función construct_balltree es
        entrada : D, una matriz de puntos de datos.
        salida : B, la raíz de un árbol de bolas construido.

        si queda un solo punto,
        cree una hoja B que contenga el único punto en D,
        devuelva  B, de
        lo contrario
        , sea c la dimensión de mayor dispersión
        Sea p el punto central seleccionado considerando c
        sean L, R los conjuntos de puntos que se encuentran a la izquierda y a la derecha de la mediana a lo largo de la dimensión c
        cree B con dos hijos :
    B.pivot : = p
        B.child1 : = construct_balltree(L),
        B.child2 : = construct_balltree(R),
        sea ​​B.radius la distancia máxima desde p entre los niños
        devuelve  B
        end if
        end función*/
}

void BallTree::inOrdre(vector<list<Coordinate>>& out) {
    // TODO: TASCA 2
}
void BallTree::preOrdre(vector<list<Coordinate>>& out) {
    // TODO: TASCA 2
}

void BallTree::postOrdre(vector<list<Coordinate>>& out) {
    // TODO: TASCA 2
}

Coordinate BallTree::nodeMesProper(Coordinate targetQuery, Coordinate& Q, BallTree* ball) {
    // TODO: TASCA 3
    Coordinate coord;
    coord.lat = 0;
    coord.lon = 0;
    return coord;
}



