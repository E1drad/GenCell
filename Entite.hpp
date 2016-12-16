/**
 * @file Entite.hpp
 * @author Montalvo Araya, Charles-Eric Bégaudeau, Marie Delavergne, François Hallereau, Camille Le Luet, Sullivan Pineau, Charlène Servantie, Sébastien Vallée
 * @since 2016
 * @brief Définition de la classe Entite
 *  $Revision$
 *  $LastChangedDate$
 */

#ifndef ENTITE_HPP_
#define ENTITE_HPP_

#include <string>
#include <vector>
#include "Apparence.hpp"

class ListeEntite;//forward declaration necessaire a cause de la dependance circulaire entre Entite et ListeEntite
#include <iostream> 
class Entite {
private :

protected :
	Apparence* apparence;
	std::string id;
	ListeEntite* listeEntite;

public :
	Entite(){}
	Entite(Apparence* apparence);
	Entite(Apparence* apparence, std::string id);
	virtual ~Entite(){}
	virtual Entite* iteration(std::vector<Entite*> entitesAdjacentes) = 0;

	bool equals(Entite* entite){
		return !entite->id.compare(this->id);
	}

	Apparence* getApparence();
	
	virtual void setListeEntite( ListeEntite* listEntite){
		this->listeEntite=listEntite;
	}

	std::string getid(){
		return this->id;
	}

	ListeEntite* getListeEntite(){
		return listeEntite;
	}
};


#endif /* ENTITE_HPP_ */
