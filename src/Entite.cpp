/**
 * @file Entite.cpp
 * @author Montalvo Araya, Charles-Eric Bégaudeau, Marie Delavergne, François Hallereau, Camille Le Luet, Sullivan Pineau, Charlène Servantie, Sébastien Vallée
 * @since 2016
 * @brief Définition de la classe Entite
 *  $Revision$
 *  $LastChangedDate$
 */

#include "../include/Entite.hpp"

	/**
     *
	 */
	Entite::Entite(Apparence* apparence){
		this->apparence = apparence;
		this->id="";
	}

	/*
	 *
	 */
	Entite::Entite(Apparence* apparence, std::string id){
		this->apparence = apparence;
		this->id="";
	}


	/*
	 *
	 */
	Apparence* Entite::getApparence(){
		return this->apparence;
	}
