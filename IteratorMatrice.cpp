#include "IteratorMatrice.h"
#include "Matrice.h";

using namespace std;


IteratorMatrice::IteratorMatrice(Matrice& m) :matrice(m) {
	act = matrice.prim;
}



Triplet IteratorMatrice::iterator() const {

	int head = matrice.prim;
	
	while (head >= 0 && head<=matrice.ultim)
	{
		if (matrice.e[head].val != NULL_TELEMENT)
		{
			return matrice.e[head];
		}
		head = matrice.urm[head];
	} 
}
