/**
 * @file Systeme.cpp
 * @author Montalvo Araya, Charles-Eric Bégaudeau, Marie Delavergne, François Hallereau, Camille Le Luet, Sullivan Pineau, Charlène Servantie, Sébastien Vallée
 * @since 2016
 * @brief Définition de la classe Systeme
 *  $Revision$
 *  $LastChangedDate$
 */

#include "../include/Systeme.hpp"

	/*
	 *
	 */
	Systeme::Systeme(std::pair<int, int> tailleCarte, std::vector< std::pair<Entite*, int> > entitesEtRepartion){
		Carte* pair = new Carte(tailleCarte, entitesEtRepartion);
		Carte* impair = new Carte(*pair);
		this->cartes = std::pair<Carte*, Carte*>(pair, impair);
		this->nbIteration = 0;
	}

	/*
	 *
	 */
	Systeme::Systeme(std::pair<Carte*, Carte*> cartes, unsigned int nbIteration){
		this->cartes = cartes;
		this->nbIteration = nbIteration;
	}

	/*
	 *
	 */
	Systeme::~Systeme(){
		delete std::get<0>(this->cartes);
		delete std::get<1>(this->cartes);
	}

	/*
	 *
	 */
	void Systeme::iteration(){
		if( (this->nbIteration % 2) == 0){
			std::get<1>(this->cartes) = new Carte( std::get<0>(this->cartes)->iteration(), std::get<1>(this->cartes)->getTailleCarte() );
		}else{
			std::get<0>(this->cartes) = new Carte( std::get<1>(this->cartes)->iteration(), std::get<0>(this->cartes)->getTailleCarte() );
		}
	}

	/*
	 *
	 */
	void Systeme::iterationMultiple(unsigned int nbIteration){
		for(unsigned int i = 0; i < nbIteration; ++i){
			this->iteration();
		}
	}

	/*
	 *
	 */
	void Systeme::retourArriere(){

	}

	/*
	 *
	 */
	bool Systeme::cartesIdentiques(){
		return std::get<1>(this->cartes)->equals( *std::get<0>(this->cartes) );
	}

	/*
	 *
	 */
	unsigned int Systeme::getNbIteration(){
		return this->nbIteration;
	}

	/*
	 *
	 */
	std::vector<Apparence*> Systeme::getApparence(){
		std::vector<Apparence*> apparences;
		if( (this->nbIteration % 2) == 0){
			apparences = std::get<0>(this->cartes)->getApparence();
		}else{
			apparences = std::get<1>(this->cartes)->getApparence();
		}
		return apparences;
	}

	/*
	 *
	 */
	Carte* Systeme::getCartePair(){
		return std::get<0>(this->cartes);
	}

	/*
	 *
	 */
	Carte* Systeme::getCarteImpair(){
		return std::get<1>(this->cartes);
	}