/*
 * 	Entite.hpp
 *
 *  Created on: 24 nov. 2016
 *  Author: Charles BEGAUDEAU
 *  $Revision$
 *  $LastChangedDate$
 */
 
#ifndef ENTITE_HPP_
#define ENTITE_HPP_

#include <string>
#include "Apparence.hpp"

class Entite {
private :
	
protected :
	Apparence* apparence;

public :
	Entite();
	virtual ~Entite();
	virtual void iteration(std::vector<Entite*>  entitesAdjacentes);
	bool equals(Entite* entite);
	
	Apparence* getApparence();
};


#endif /* ENTITE_HPP_ */
