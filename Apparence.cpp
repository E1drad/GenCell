/**
 * @file Apparence.cpp
 * @author Montalvo Araya, Charles-Eric B�gaudeau, Marie Delavergne, Fran�ois Hallereau, Camille Le Luet, Sullivan Pineau, Charl�ne Servantie, S�bastien Vall�e
 * @since 2016
 * @brief D�finition de la classe Apparence
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
