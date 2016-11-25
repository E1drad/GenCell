/*
 * 	Carte.cpp
 *
 *  Created on: 24 nov. 2016
 *  Author: Charles BEGAUDEAU
 *  $Revision$
 *  $LastChangedDate$
 */

#include "Carte.hpp"
std::random_device rd;
std::mt19937 rng(rd());

	void Carte::generationCellule(std::vector< std::pair<Entite*, int> > entitesEtRepartion){
		rng();

	}

	Carte::Carte(std::pair <int, int> tailleCarte, std::vector< std::pair<Entite*, int> > entitesEtRepartion){

	}

	Carte::Carte(std::vector<Cellule*> carte){

	}

	Carte::~Carte(){

	}

	bool Carte::equals(Carte carte){
		bool test;
		if(std::get<0>(this->tailleCarte) != std::get<0>(carte.getTailleCarte()){
			test = false;		
		}else{
			if(std::get<1>(this->tailleCarte) != std::get<1>(carte.getTailleCarte()){
				test = false;
			}else{
				unsigned int i = 0; 
				test = true
				while(test && i < this->carte.size()){
					test = this->carte.at(i).equals(carte.getCarte.at(i));
					++i;
				}
			}
		}
		return test;
	}

	std::vector<Cellule*> Carte::iteration(){
		std::vector<Cellule*> carteIteree;
		for(unsigned int i = 0; i < this->carte.size(); ++i){
			carteIteree.push_back(this->carte.at(i).iteration());
		}
		return carteIteree;
	}

	int Carte::getLongueur(){
		return std::get<0>(this->tailleCarte);
	}

	int Carte::getLargeur(){
		return std::get<1>(this->tailleCarte);
	}

	std::pair <int, int> Carte::getTailleCarte(){
		return this->tailleCarte;
	}

	std::vector<Cellule*> Carte::getCarte(){
		return this->carte;
	}

