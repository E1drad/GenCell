/**
 * @file Cellule.cpp
 * @author Montalvo Araya, Charles-Eric Bégaudeau, Marie Delavergne, François Hallereau, Camille Le Luet, Sullivan Pineau, Charlène Servantie, Sébastien Vallée
 * @since 2016
 * @brief Définition de la classe Cellule
 *  $Revision$
 *  $LastChangedDate$
 */

 #include "../include/Cellule.hpp"

 	/*
	 *\brief retourne un vecteur des entités voisines.
	 *\details Permet de récupérer un vecteur de pointeur sur Entite contenant les 8 entités des 8 cellules voisines de la cellule courante
	 * comprenant les entités situées au NORD, NORD-EST, EST, SUD-EST, SUD, SUD-OUEST, OUEST et NORD-OUEST
	 *\return vecteur de pointeur sur des objets Entite
	 */
	std::vector<Entite*> Cellule::getEntitesAdjacentes(){
		std::vector<Entite*> entitesAdjacentes;
		for(unsigned int i = 0; i < this->celluleAdjacentes.size(); ++i){
			entitesAdjacentes.push_back(this->celluleAdjacentes.at(i)->getEntite());
		}
		return entitesAdjacentes;
	}

	/*
	 *
	 */
	Cellule::Cellule(Entite* entite, std::vector<Cellule*> celluleAdjacentes){
		this->entite = entite;
		this->celluleAdjacentesOntEteInit = false;
		this->initialiserCelluleAdjacentes(celluleAdjacentes);
	}

	/*
	 *
	 */
	Cellule::Cellule(Entite* entite){
		this->entite = entite;
		this->celluleAdjacentesOntEteInit = false;
	}

	/*
	 *
	 */
	Cellule::~Cellule(){
		std::vector<Cellule*>::iterator it = this->celluleAdjacentes.begin();
		for(it ; it != this->celluleAdjacentes.end(); ++it){
			delete(*it);
		}
		this->celluleAdjacentes.clear();
		delete this->entite;
	}

	/*
	 *\brief permet d'initialiser les voisines de la cellule courante
	 *\details Cette fonction permet d'initialiser les voisines de la cellule courante par un nouveau vecteur.
	 * la modification ne sera effectué que si celluleAdjacentesOntEteInit est à faux.
	 *\param [in] celluleAdjacentes, un vecteur de de pointeur sur Cellule
	 */
	void Cellule::initialiserCelluleAdjacentes(std::vector<Cellule*> celluleAdjacentes){
		if( ! this->celluleAdjacentesOntEteInit){
			this->celluleAdjacentes = celluleAdjacentes;
			this->celluleAdjacentesOntEteInit = true;
		}
	}

	/*
	 *\brief fonction necessaire lors du parcours effectué par la classe Carte.
	 *\return la liste de toutes les entités des cellules voisines de la cellule courante.
	 */
	Entite* Cellule::iteration(){
		return this->entite->iteration(this->getEntitesAdjacentes());
	}

	/*
	 *\brief savoir si deux cellules ont les mêmes caractéristiques
	 *\details Deux cellules sont considéré comme différentes si elles possèdent au moins une Entités différentes. Ces entités correspondent, pour chaque cellule,  à son entité
	 * et à l'ensemble des entités de toutes les cellules voisines. Pour les voisines, la comparaison est effectué pour le même emplacement par rapport à la cellule courante(NORD,SUD,...)
	 *\param [in] la cellule qui sera comparé avec la cellule courante
	 *\return test, un booléen qui sera à 1 si les deux cellules  ont les mêmes caractéristiques,0 sinon.
	 */
	bool Cellule::equals(Cellule cellule){
		bool test;
		if( ! this->entite->equals(cellule.getEntite())){
			test = false;
		}else{
			if( this->celluleAdjacentes.size() != cellule.celluleAdjacentes.size() ){
				test = false;
			}else{
				unsigned int i = 0;
				test = true;
				while(test && i < this->celluleAdjacentes.size()){
					test = this->celluleAdjacentes.at(i)->equals(*cellule.celluleAdjacentes.at(i));
					++i;
				}
			}
		}
		return test;
	}

	/*
	 *\brief récupérer un vecteur des cellules adjacentes.
	 *\details Permet de récupérer un vecteur de pointeur sur Cellule contenant les 8 cellules voisines de la cellule courante
	 * comprenant les cellules situées au NORD, NORD-EST, EST, SUD-EST, SUD, SUD-OUEST, OUEST et NORD-OUEST
	 *\return un vecteur de pointeurs sur des objets Cellule.
	 */
	std::vector<Cellule*> Cellule::getCellulesAdjacentes(){
		return this->celluleAdjacentes;
	}

	/*
	 *\brief récupérer l'entité de la cellule courante
	 *\return pointeur sur un objet Entite.
	 */
	Entite* Cellule::getEntite(){
		return this->entite;
	}

	/*
	 *\brief récupérer l'apparence de l'entité de la cellule courante
	 *\return pointeur sur un objet Apparence.
	 */
	Apparence* Cellule::getApparence(){
		return this->entite->getApparence();
	}

	/*
	 *\brief modifier l'entite de la cellule courante
	 */
	void Cellule::setEntite(Entite* entite){
		this->entite = entite;
	}
