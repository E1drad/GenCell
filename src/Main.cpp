/**
 * @file Main.cpp
 * @author Montalvo Araya, Charles-Eric Bégaudeau, Marie Delavergne, François Hallereau, Camille Le Luet, Sullivan Pineau, Charlène Servantie, Sébastien Vallée
 * @since 2016
 * @brief Définition de la classe principale de l'application
 *  $Revision$
 *  $LastChangedDate$
 */

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "Apparence.hpp"
#include "Carte.hpp"
#include "Cellule.hpp"
#include "Entite.hpp"
#include "Systeme.hpp"
#include <iostream>
#include <chrono>
#include <cstring>
#include <thread>
#include <utility>


/**************************************************PROTOTYPE**************************************************/
void sleep(int ms);
void show(int w, int h, Carte* carte);

/**************************************************PROTOTYPE**************************************************/



//la jolie fonction pour afficher les voisins
void show(int w, int h, Carte* carte){
	char grid[w*h];
	memset(grid, ' ', w*h);
	int i = 0;
	for(int y = 0; y < h; y++){
		std::cout << '|';
		for(int x = 0; x < w; x++){
			char a = carte->getCarte().at(i)->getApparence()->getApparence();
			std::cout << a << '|';
			i = i+1;
		}
		std::cout << std::endl;
	}

}

//fonction pour faire une pause en millisecond
void sleep(int ms){
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int main(void){
	/* ATTENTION DOUBLE FREE OU SEG FAULT probleme dans les destructeurs je pense
	 -- Charles
	std::pair<int, int> tailleCarte (10, 10);

	Apparence apparence1('#');
	Apparence apparence2('*');
	Apparence apparence3('-');
	Apparence apparence4('+');

	Entite ent1(&apparence1, "ent1");
	Entite ent2(&apparence2, "ent2");
	Entite ent3(&apparence3, "ent3");
	Entite ent4(&apparence4, "ent4");

	std::vector< std::pair<Entite*, int> > entitesEtRepartion;
	entitesEtRepartion.push_back(std::pair<Entite*, int> (&ent1, 25));
	entitesEtRepartion.push_back(std::pair<Entite*, int> (&ent2, 25));
	entitesEtRepartion.push_back(std::pair<Entite*, int> (&ent3, 25));
	entitesEtRepartion.push_back(std::pair<Entite*, int> (&ent4, 25));

	int nbEntiteTotal;
	nbEntiteTotal = 0;
	for(unsigned int i = 0; i < entitesEtRepartion.size(); ++i){
		nbEntiteTotal = nbEntiteTotal + std::get<1>(entitesEtRepartion.at(i));
	}

	Systeme systeme(tailleCarte, entitesEtRepartion);

	int w = std::get<1>(tailleCarte);
	int h = std::get<0>(tailleCarte);
	int ms = 200;
	for(int iteration = 0; iteration < 1; ++iteration){
		//system("clear");
		std::cout << "iteration : " << iteration << std::endl;
		if (iteration % 2 == 0) {
			std::cout << "impair" << std::endl;
			show(w, h, systeme.getCarteImpair());
		}else{
			std::cout << "pair" << std::endl;
			show(w, h, systeme.getCartePair());
		}
		sleep(ms);
	}
	*/

  int X = 1280, Y = 1024;
  std::string name = "GenCell";
  sf::RenderWindow window(sf::VideoMode(X,Y), name);

  while (window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }

	return 0;
}
