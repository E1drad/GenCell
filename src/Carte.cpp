/**
 * @file Carte.cpp
 * @author Montalvo Araya, Charles-Eric Bégaudeau, Marie Delavergne, François Hallereau, Camille Le Luet, Sullivan Pineau, Charlène Servantie, Sébastien Vallée
 * @since 2016
 * @brief Définition de la classe Carte
 *  $Revision$
 *  $LastChangedDate$
 */

#include "../include/Carte.hpp"
std::random_device rd;
std::mt19937 rng(rd());


	/*
	 *\brief creer une Carte a partir d'un couple d'entier et repartie aleatoirement des entites.
	 *\details creer une Carte a partir d'une longueur et d'une largeurur donnee avant de repartir
	 *aleatoirement des entites dans des quantites donnees.
	 *\param [in] couple d'entier representant  <longueur, largeurur> de la carte
	 *\param [in] vector d'entites associe au nombre d'entites a place aleatoirement dans la carte.
	 *\pre le produit du couple d'entier tailleCarte est superieur a 1
	 *\pre pour toutes entites presente dans le vector l'entier associe est superieur a 1
	 *\pre la somme de tout les int du couple entitesEtRepartion est inferieur ou égale a la
	 * taille de la carte.
	 */
	Carte::Carte(std::pair <int, int> tailleCarte, std::vector< std::pair<Entite*, int> > entitesEtRepartion){
		this->tailleCarte = tailleCarte;
		this->generationAleatoireCellule(entitesEtRepartion);
		this->initialisationVoisinage();
	}

	/*
	 *\brief repartie aleatoirement des entites dans la carte.
	 *\details repartie aleatoirement des entites dans des quantites donnees dans la carte, si la
	 * sommes de tous les entiers associe au entites est inferieur au nombre de cellules alors des
	 * cellules dont les entites sont NULL sont creees pour complete la carte.
	 *\param [in] vector d'entites associe au nombre d'entites a place aleatoirement dans la carte.
	 *\pre pour toutes entites presente dans le vector l'entier associe est superieur a 1
	 *\pre la somme de tout les int du couple entitesEtRepartion est inferieur ou égale a la
	 * taille de la carte.
	 */
	void Carte::generationAleatoireCellule(std::vector< std::pair<Entite*, int> > entitesEtRepartion){
		int nbCelluleCarte;
		int nbEntiteTotal;
		nbEntiteTotal = 0;
		nbCelluleCarte = std::get<0>(this->tailleCarte) * std::get<1>(this->tailleCarte);
		for(unsigned int i = 0; i < entitesEtRepartion.size(); ++i){
			nbEntiteTotal = nbEntiteTotal + std::get<1>(entitesEtRepartion.at(i));
		}
		if(nbCelluleCarte > nbEntiteTotal){
			entitesEtRepartion.push_back(std::pair<Entite*, int>(NULL, nbCelluleCarte - nbEntiteTotal));
		}
		/*
		 * parcours le vector et decremente l'entier du couple a chaque tour, si l'entier
		 * associer a l'entite est egal a zero le couple est supprime du vector.
		 */
		while(!entitesEtRepartion.empty()){
			//std::cout << << std::endl;
			int i;
			i = (rng() % (entitesEtRepartion.size()));//pour aller de 0 à size()-1
			
			this->carte.push_back(  new Cellule( std::get<0>(entitesEtRepartion.at(i)) )   );
			std::get<1>(entitesEtRepartion.at(i)) = std::get<1>(entitesEtRepartion.at(i)) - 1;
			if(std::get<1>(entitesEtRepartion.at(i)) == 0){
				entitesEtRepartion.erase(entitesEtRepartion.begin() + i);
			}
		}
	}


	/*
	 *\brief effectue le veritable calcul du modulo.
	 *\details modulo sans utiliser la fonction de troncature de la partie decimale.
	 * avec cette fonction -1 mod 20 = 19
	 * avec l'operateur C++ -1 % 20 = -1
	 *\param [in] le numerateur
	 *\param [in] le denominatueur
	 *\return a modulo b.
	 */
	inline int mod(int a, int b) {
		if(b < 0) return mod(-a, -b);
		const int result = a % b;
		return result >= 0 ? result : result + b;
	}

	/*
	 *\brief genere le voisinage de toutes les cellules de la carte.
	 *\details parcours le vector de cellule et calcul les huit cellules adjacentes
	 * avant de lui transmettre les pointeurs vers ces cellules.
	 *\pre le vector de cellule contient deja toutes les cellules.
	 *\warning ne pas compiler avec les optimisations, les sept lignes de calcul du
	 * voisinage ne doivent pas être modifier.
	 *
	 */
	void Carte::initialisationVoisinage(){
		unsigned int largeur;
		unsigned int longueur;
		largeur = std::get<1>(this->tailleCarte);
		longueur = std::get<0>(this->tailleCarte);
		for(unsigned int i = 0; i < this->carte.size(); ++i){
			std::vector<Cellule*> vecAdj;//vector des cellules adjacentes a la cellule i.
			int modLar;
			int divLar;
			int multLar;
			int modPlusLar;
			int modMoinsLar;
			int modPlusLon;
			int modMoinsLon;

			modLar = mod(i, largeur);
			divLar = i/largeur;//TODO Verifier l'arrondi necessite peut-etre un floor.
			multLar = divLar * largeur;
			modPlusLar = mod(modLar+1, largeur);
			modMoinsLar = mod(modLar-1, largeur);
			modPlusLon = mod(divLar+1, longueur) * largeur;
			modMoinsLon = mod(divLar-1, longueur) * largeur;
			
			vecAdj.push_back(this->carte.at( modLar + modMoinsLon ));//Nord
			vecAdj.push_back(this->carte.at( modPlusLar + modMoinsLon ));//Nord Est
			vecAdj.push_back(this->carte.at( modPlusLar + multLar ));//Est
			vecAdj.push_back(this->carte.at( modPlusLar + modPlusLon ));//Sud Est
			vecAdj.push_back(this->carte.at( modLar + modPlusLon ));//Sud
			vecAdj.push_back(this->carte.at( modMoinsLar + modPlusLon ));//Sud Ouest
			vecAdj.push_back(this->carte.at( modMoinsLar + multLar ));//Ouest
			vecAdj.push_back(this->carte.at( modMoinsLar + modMoinsLon ));//Nord Ouest

			std::cout << "Cellule n°" << i << "; cellules adjacentes : N: " 
				<< vecAdj.at(0)->getApparence()->getApparence() 
				<< "; NE: " << vecAdj.at(1)->getApparence()->getApparence() 
				<< "; E: " << vecAdj.at(2)->getApparence()->getApparence() 
				<< "; SE: " << vecAdj.at(3)->getApparence()->getApparence() 
				<< "; S: " << vecAdj.at(4)->getApparence()->getApparence() 
				<< "; SO: " << vecAdj.at(5)->getApparence()->getApparence() 
				<< "; O: " << vecAdj.at(6)->getApparence()->getApparence() 
				<< "; NO: " << vecAdj.at(7)->getApparence()->getApparence() << std::endl;
		
		}
	}

	/*
	 *\brief genere une carte a partir des donnees d'une carte pré-existante.
	 *\param [in] vector des cellules de la carte.
	 *\pre la taille du vector carte doit etre egale au produit du couple d'entier tailleCarte.
	 */
	Carte::Carte(std::vector<Cellule*> vecCellule, std::pair <int, int> tailleCarte){
		for(unsigned int i = 0; i < vecCellule.size(); ++i){
			this->carte.push_back(new Cellule(vecCellule->at(i)->getEntite()));
		}
		this->initialisationVoisinage();
		this->tailleCarte = tailleCarte;
	}

	/*
	 *\brief genere une carte a partir des donnees d'une carte pré-existante.
	 *\param [in] vector des cellules de la carte.
	 *\pre la taille du vector carte doit etre egale au produit du couple d'entier tailleCarte.
	 */
	Carte::Carte(const Carte &other){
		this->carte = other.carte;
		this->tailleCarte = other.tailleCarte;
	}

	Carte::~Carte(){
		std::vector<Cellule*>::iterator it = this->carte.begin();
		for(it; it != this->carte.end(); ++it){
			delete(*it);
		}
		this->carte.clear();
	}

	/*
	 *\brief determine si la carte passee en parametre est egale a cette carte.
	 *\param [in] la carte que l'on veut comparer.
	 *\return un booleen qui est vrai si les deux cartes sont egales, sinon le booleen est faux.
	 */
	bool Carte::equals(Carte carte){
		bool test;
		//if(carte == NULL){
		//	test = false;
		//}else{
			if( std::get<0>(this->tailleCarte) != std::get<0>(carte.getTailleCarte()) ){
				test = false;
			}else{
				if( std::get<1>(this->tailleCarte) != std::get<1>(carte.getTailleCarte()) ){
					test = false;
				}else{
					unsigned int i = 0;
					test = true;
					while(test && i < this->carte.size()){
						test = this->carte.at(i)->equals(*carte.getCarte().at(i));
						++i;
					}
				}
			}
		//}
		return test;
	}

	/*
	 *\brief parcours la carte et calcul la nouvelle valeur de chaque cellule.
	 *\return le vector de pointeur de cellule iterees.
	 */
	std::vector<Entite*> Carte::iteration(){
		std::vector<Entite*> carteIteree;
		for(unsigned int i = 0; i < this->carte.size(); ++i){
			carteIteree.push_back(this->carte.at(i)->iteration());
		}
		return carteIteree;
	}

	int Carte::getLongueur(){
		return std::get<0>(this->tailleCarte);
	}

	int Carte::getlargeurur(){
		return std::get<1>(this->tailleCarte);
	}

	std::vector<Apparence*> Carte::getApparence(){
		std::vector<Apparence*> apparences;
		for(unsigned int i = 0; i < this->carte.size(); ++i){
			apparences.push_back(this->carte.at(i)->getApparence());
		}
		return apparences;
	}

	std::pair <int, int> Carte::getTailleCarte(){
		return this->tailleCarte;
	}

	std::vector<Cellule*> Carte::getCarte(){
		return this->carte;
	}
