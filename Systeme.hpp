/**
 * @file Systeme.cpp
 * @author Montalvo Araya, Charles-Eric B�gaudeau, Marie Delavergne, Fran�ois Hallereau, Camille Le Luet, Sullivan Pineau, Charl�ne Servantie, S�bastien Vall�e
 * @since 2016
 * @brief D�finition de la classe Systeme
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
	unsigned int nbIteration;

public :
	Systeme(std::pair<int, int> tailleCarte, std::vector< std::pair<Entite*, int> > entitesEtRepartion);
	Systeme(std::pair<Carte*, Carte*> cartes, unsigned int nbIteration);
	~Systeme();

	void iteration();
	void iterationMultiple(unsigned int nbIteration);
	void retourArriere();
	bool cartesIdentiques();
	std::vector<Apparence*> getApparence();
	unsigned int getNbIteration();
	Carte* getCartePair();
	Carte* getCarteImpair();
};


#endif /* SYSTEME_HPP_ */
