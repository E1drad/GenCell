/**
 * @file Apparence.cpp
 * @author Montalvo Araya, Charles-Eric Bégaudeau, Marie Delavergne, François Hallereau, Camille Le Luet, Sullivan Pineau, Charlène Servantie, Sébastien Vallée
 * @since 2016
 * @brief Définition de la classe Apparence
 *  $Revision$
 *  $LastChangedDate$
 */
#include "../include/Apparence.hpp"

	/*
	 *
	 */
	Apparence::Apparence(char visuel){
		this->apparence = visuel;
	}

	/*
	 *
	 */
	Apparence::~Apparence(){

	}

	/*
	 *
	 */
	char Apparence::getApparence(){
		return this->apparence;
	}
