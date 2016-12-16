/**
 * @file Carte.cpp
 * @author Montalvo Araya, Charles-Eric B�gaudeau, Marie Delavergne, Fran�ois Hallereau, Camille Le Luet, Sullivan Pineau, Charl�ne Servantie, S�bastien Vall�e
 * @since 2016
 * @brief D�finition de la classe Carte
 *  $Revision$
 *  $LastChangedDate$
 */

#ifndef CARTE_HPP_
#define CARTE_HPP_

#include <string>
#include <utility>
#include "Cellule.hpp"
#include <random>
#include <iostream>

class Carte {
private :
	std::vector<Cellule*> carte;
	std::pair <int, int> tailleCarte;
	void generationAleatoireCellule(std::vector< std::pair<Entite*, int> > entitesEtRepartion);
	void initialisationVoisinage();

public :

	Carte(std::pair <int, int> tailleCarte, std::vector< std::pair<Entite*, int> > entitesEtRepartion);
	Carte(std::vector<Cellule*> carte, std::pair <int, int> tailleCarte);
	Carte(const Carte &carte);
	~Carte();
	bool equals(Carte carte);
	std::vector<Cellule*> iteration();

	int getLargeur();
	int getLongueur();
	std::vector<Apparence*> getApparence();
	std::pair <int, int> getTailleCarte();
	std::vector<Cellule*> getCarte();

};


#endif /* CARTE_HPP_ */
