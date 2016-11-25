/*
 *  Systeme.hpp
 *
 *  Created on: 24 nov. 2016
 *  Author: Charles BEGAUDEAU
 *  $Revision$
 *  $LastChangedDate$
 */

#ifndef SYSTEME_HPP_
#define SYSTEME_HPP_

#include <string>
#include <utility> 
#include "Carte.hpp"

class Systeme {
private :
	std::pair <Carte*, Carte*> cartes;
	int iteration;

public :
	Systeme(std::pair <int, int> tailleCarte);
	Systeme(std::pair <Carte*, Carte*> cartes, int iteration);
	~Systeme();
	
	void iteration();
	void iterationMultiple(int nbIteration);
	void retourArriere();
	bool cartesIdentiques();
	std::vector<Apparence*> getApparence();

};


#endif /* SYSTEME_HPP_ */
