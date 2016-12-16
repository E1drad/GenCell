/**
 * @file Cellule.cpp
 * @author Montalvo Araya, Charles-Eric B�gaudeau, Marie Delavergne, Fran�ois Hallereau, Camille Le Luet, Sullivan Pineau, Charl�ne Servantie, S�bastien Vall�e
 * @since 2016
 * @brief D�finition de la classe Cellule
 *  $Revision$
 *  $LastChangedDate$
 */

 #include "../include/Cellule.hpp"

 	/*
	 *\brief retourne un vecteur des entit�s voisines.
	 *\details Permet de r�cup�rer un vecteur de pointeur sur Entite contenant les 8 entit�s des 8 cellules voisines de la cellule courante
	 * comprenant les entit�s situ�es au NORD, NORD-EST, EST, SUD-EST, SUD, SUD-OUEST, OUEST et NORD-OUEST
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
	 * la modification ne sera effectu� que si celluleAdjacentesOntEteInit est � faux.
	 *\param [in] celluleAdjacentes, un vecteur de de pointeur sur Cellule
	 */
	void Cellule::initialiserCelluleAdjacentes(std::vector<Cellule*> celluleAdjacentes){
		if( ! this->celluleAdjacentesOntEteInit){
			this->celluleAdjacentes = celluleAdjacentes;
			this->celluleAdjacentesOntEteInit = true;
		}
	}

	/*
	 *\brief fonction necessaire lors du parcours effectu� par la classe Carte.
	 *\return la liste de toutes les entit�s des cellules voisines de la cellule courante.
	 */
	Entite* Cellule::iteration(){
		return this->entite->iteration(this->getEntitesAdjacentes());
	}

	/*
	 *\brief savoir si deux cellules ont les m�mes caract�ristiques
	 *\details Deux cellules sont consid�r� comme diff�rentes si elles poss�dent au moins une Entit�s diff�rentes. Ces entit�s correspondent, pour chaque cellule,  � son entit�
	 * et � l'ensemble des entit�s de toutes les cellules voisines. Pour les voisines, la comparaison est effectu� pour le m�me emplacement par rapport � la cellule courante(NORD,SUD,...)
	 *\param [in] la cellule qui sera compar� avec la cellule courante
	 *\return test, un bool�en qui sera � 1 si les deux cellules  ont les m�mes caract�ristiques,0 sinon.
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
	 *\brief r�cup�rer un vecteur des cellules adjacentes.
	 *\details Permet de r�cup�rer un vecteur de pointeur sur Cellule contenant les 8 cellules voisines de la cellule courante
	 * comprenant les cellules situ�es au NORD, NORD-EST, EST, SUD-EST, SUD, SUD-OUEST, OUEST et NORD-OUEST
	 *\return un vecteur de pointeurs sur des objets Cellule.
	 */
	std::vector<Cellule*> Cellule::getCellulesAdjacentes(){
		return this->celluleAdjacentes;
	}

	/*
	 *\brief r�cup�rer l'entit� de la cellule courante
	 *\return pointeur sur un objet Entite.
	 */
	Entite* Cellule::getEntite(){
		return this->entite;
	}

	/*
	 *\brief r�cup�rer l'apparence de l'entit� de la cellule courante
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
