/*
 * 	Carte.hpp
 *
 *  Created on: 24 nov. 2016
 *  Author: Charles BEGAUDEAU
 *  $Revision$
 *  $LastChangedDate$
 */

#ifndef CARTE_HPP_
#define CARTE_HPP_

#include <string>
#include <utility> 
#include "Cellule.hpp"
#include <random>
 
class Carte {
private :
	std::vector<Cellule*> carte;
	std::pair <int, int> tailleCarte;
	void generationCellule(std::vector< std::pair<Entite*, int> > entitesEtRepartion);

public :
	Carte(std::pair <int, int> tailleCarte, std::vector< std::pair<Entite*, int> > entitesEtRepartion);
	Carte(std::vector<Cellule*> carte);
	~Carte();
	bool equals(Carte carte);
	std::vector<Cellule*> iteration();

	int getLargeur();
	int getLongueur();
	std::pair <int, int> getTailleCarte();
	std::vector<Cellule*> getCarte();

};


#endif /* CARTE_HPP_ */
