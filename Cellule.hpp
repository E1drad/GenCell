/**
 * @file Cellule.cpp
 * @author Montalvo Araya, Charles-Eric Bégaudeau, Marie Delavergne, François Hallereau, Camille Le Luet, Sullivan Pineau, Charlène Servantie, Sébastien Vallée
 * @since 2016
 * @brief Définition de la classe Cellule
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
	Cellule(Entite* entite, std::vector<Cellule*> celluleAdjacentes);
	Cellule(Entite* entite);
	~Cellule();

	void initialiserCelluleAdjacentes(std::vector<Cellule*> celluleAdjacentes);
	Cellule* iteration();
	bool equals(Cellule cellule);
	std::vector<Cellule*> getCellulesAdjacentes();
	Entite* getEntite();
	Apparence* getApparence();
	void setEntite(Entite* entite);

};


#endif /* CELLULE_HPP_ */
