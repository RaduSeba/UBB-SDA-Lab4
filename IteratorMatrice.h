#pragma once
#include "Matrice.h"

class IteratorMatrice {

private:

	friend class Matrice;
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorMatrice(Matrice& matrice);


	//contine o referinta catre containerul pe care il itereaza
	Matrice& matrice;


	/* aici e reprezentarea  specifica a iteratorului */
	int act;

public:

	/*pargurge matricea si returneaza elementele nenule

		Caz favorabil = Theta(1)
		Caz defavorabil = Theta(n)
		Caz mediu = Theta(n)
		Complexitate generala : O(n)
		Subalgoritm iterator()
		pre: it - iterator,matrice-matricea , tripet-triplet(linie,coloana,element)
		 post : returneaza elementele nenule
		 int head<-matrice.prim;
	
	cat timp head>=0 && head<=ultim executa
		daca matrice.e[head].val != NULL_TELEMENT
		*	returneaza matrice.e[head];
		*SfDaca
			head <- matrice.urm[head];
		* Sf cat timp
		* SfSubAlgoritm
		* */
	Triplet iterator() const;
};