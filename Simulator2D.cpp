/**
 * Codé par NASTUZZI Samy
 *
 * Définition des fonctions règles
 */

#include <iostream>
#include <vector>
#include "Simulator1D.h"
#include "Simulator2D.h"
#include "State.h"
#include "Rule.h"

#define uint unsigned int

Cell* Simulator2D::getCell(uint x, uint y) const {
    return Simulator1D::getCell((x * _cellsSize) + y);
}

State** Simulator2D::getNeightborsState(State** states, uint position) {
    State** neighbors(new State*[getNeightborNbr()]);

    // On ajoute les précédents et les suivants:
    neighbors[0] = states[(position - _cellsSize - 1) % _cellsNbr];
    neighbors[1] = states[(position - _cellsSize) % _cellsNbr];
    neighbors[2] = states[(position - _cellsSize + 1) % _cellsNbr];
    neighbors[3] = states[(position - 1) % _cellsNbr];
    neighbors[4] = states[(position + 1) % _cellsNbr];
    neighbors[5] = states[(position + _cellsSize - 1) % _cellsNbr];
    neighbors[6] = states[(position + _cellsSize) % _cellsNbr];
    neighbors[7] = states[(position + _cellsSize + 1) % _cellsNbr];

    return neighbors;
}