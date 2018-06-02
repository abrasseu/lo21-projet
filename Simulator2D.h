/**
 * Codé par NASTUZZI Samy
 *
 * Cette classe permet de gérer chaque simulation
 */

#ifndef __SIMULATOR_2D_H_DEFINE__
#define __SIMULATOR_2D_H_DEFINE__

#include <iostream>
#include "Simulator1D.h"
#include "Cell.h"
#include "State.h"

#define uint unsigned int

class Simulator2D : public Simulator1D {
protected:
    // Liste des états et cellules composant la simulation
    using Simulator1D::_cellsSize;
    using Simulator1D::getNeightborNbr;

public:
    // Constructeurs
    Simulator2D(State** states, uint stateNbr, uint cellsNbr): Simulator1D::Simulator1D(states, stateNbr, cellsNbr, 2) {};

    // Getters
    using Simulator1D::getCell;
    Cell* getCell(uint x, uint y) const;
    State** getNeightborsState(State** states, uint position);
};

#endif
