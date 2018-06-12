/**
 * Codé par NASTUZZI Samy
 *
 * Cette classe permet de gérer chaque simulation
 */

#ifndef __SIMULATOR_H_DEFINE__
#define __SIMULATOR_H_DEFINE__

#include <iostream>
#include <cmath>
#include "Cell.h"
#include "State.h"

using uint = unsigned int;

class Simulator {
protected:
	// Liste des états et cellules composant la simulation
	State** _states;
	uint _stateNbr;
	Cell** _cells;
	uint _cellsSize;
	uint _generation;
	const uint _dimension;

	// Getters
	uint getDimension() const { return _dimension; }
	State** getCellsState() const;
	uint getNeighbourNbr() const { return pow(3, getDimension()) - 1; }
	virtual State** getNeighboursState(State** states, uint position) = 0;
	void createCells();

public:
	// Constructeurs
	Simulator(State** states, uint stateNbr, uint cellsSize, uint dimension): _states(states), _stateNbr(stateNbr), _cellsSize(cellsSize), _generation(0), _dimension(dimension) {
		createCells();
	}
//	virtual ~Simulator();

	// Getters
	State** getInitStates() const { return _states; }
	uint getCellsSize() const { return _cellsSize; }
	uint getCellsNbr() const { return pow(_cellsSize, getDimension()); }
	Cell* getCell(uint position) const;

	virtual void printCells() = 0;
	void incrementState(uint position);

	// Renvoi vrai si la grille a changé
	virtual bool mutate();
};

#endif
