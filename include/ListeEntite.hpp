/**
 * @file ListeEntite.hpp
 * @author Montalvo Araya, Charles-Eric Bégaudeau, Marie Delavergne, François Hallereau, Camille Le Luet, Sullivan Pineau, Charlène Servantie, Sébastien Vallée
 * @since 2016
 * @brief Définition de la classe ListeEntite
 *  $Revision$
 *  $LastChangedDate$
 */

 
#ifndef LISTEENTITE_HPP_
#define LISTEENTITE_HPP_

#include <string>
#include <vector>

class Entite;//forward declaration necessaire a cause de la dependance circulaire entre ListeEntite et Entite

class ListeEntite {
	private :
	protected :

	public :
		ListeEntite(){}
		virtual ~ListeEntite(){}
		virtual Entite* getEntiteParDefault() = 0;
		virtual int getNombreEntite(){
			return 0;
		}
		virtual std::vector<Entite*> getList() = 0;
		virtual void setListeEntites(){}

		virtual Entite* getEntite(std::string name) = 0;
};

typedef ListeEntite* create_t();
typedef void destroy_t(ListeEntite*);

#endif /* LISTEENTITE_HPP_ */
