/*
 *  Cellule.hpp
 *
 *  Created on: 24 nov. 2016
 *  Author: Charles BEGAUDEAU
 *  $Revision$
 *  $LastChangedDate$
 */

#ifndef CELLULE_HPP_
#define CELLULE_HPP_

#include <string>
#include <vector>
#include "Entite.hpp"

class Cellule {
private :
	Entite* entite;
	std::vector<Cellule*> celluleAdjacentes;
	bool celluleAdjacentesOntEteInit;

	std::vector<Entite*> getEntitesAdjacentes();

public :
	Cellule();
	~Cellule();
	
	void initialiserCelluleAdjacentes(std::vector<Cellule*> celluleAdjacentes);
	Cellule* iteration();

	std::vector<Cellule*> getCellulesAdjacentes();
	Entite* getEntite();
	Apparence* getApparence();
	void setEntite(Entite entite);

};


#endif /* CELLULE_HPP_ */
