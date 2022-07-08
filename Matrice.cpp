#include "Matrice.h"

#include <exception>
#include "IteratorMatrice.h"

using namespace std;


Matrice::Matrice(int m, int n) {
	if (m <= 0 || n<=0 )
	{
		throw std::exception("Maricea nu este valida ");
	}
	this->cp = 10;
	e = new Triplet[cp];
	urm = new int[cp];
	prec = new int[cp];
	linii = m;
	coloane = n;
	prim = -1;
	ultim = 0;
	primLiber = 0;
	for(int i=0; i<cp-1; ++i){
        urm[i]=i+1;
    }
    urm[cp-1]=0;
}



int Matrice::aloca() {
	//se sterge primul element din lista spatiului liber
	int i = primLiber;
	primLiber = urm[primLiber];
	return i;
}

//void Matrice::redim() {
//	cp *= 2;
//	TElem* temp1 = new TElem[cp];
//	int* temp2 = new int[cp];
//	for (int i = 1; i <= cp; ++i) {
//		temp1[i] = e[i];
//		temp2[i] = urm[i];
//	}
//	primLiber = cp / 2;
//	for (int i = cp / 2; i < cp; ++i) {
//		temp2[i] = i + 1;
//	}
//	urm[cp - 1] = 0;
//	delete[] e;
//	delete[] urm;
//	e = temp1;
//	urm = temp2;
//}




void Matrice::dealoca(int i) {
	//pozitia i se muta in lista spatiului liber
	urm[i] = primLiber;
	primLiber = i;
	//dimensiune--;
}


int Matrice::creeazaNod(Triplet elem) 
{
	if (primLiber == 0)
	{
		//redim();

	}
	int i = aloca();
	this->e[i] = elem;
	urm[i] = -1;
	prec[i] = -1;
	return i;
}

int Matrice::nrLinii() const {
	return linii;
}


int Matrice::nrColoane() const {
	return coloane;
}

int Matrice::numarElementeNenule(int col) const {
	int k = 0;
	if (col<0 || col>coloane)
	{
		throw std::exception("Nu e coloana valida");
	}
	int current = prim;
	while (current >= 0 && current<=ultim )
	{
		int idx_j = e[current].j;
		if (idx_j == col && e[current].val!=0)
		{
			k = k + 1;
		}
		current = urm[current];
	}
	return k;

}


TElem Matrice::element(int i, int j) const {
	if (i<0 || i>linii || j<0 || j>coloane) {
		throw std::exception("Nu e element valid");
	}
	int current = prim;
	while (current != -1 && current<=ultim)
	{
		//int idx_i = current->util.i, idx_j = current->util.j;
		if (e[current].i == i && e[current].j == j) {
			return e[current].val;
		}
		current=urm[current];
	}
	return NULL_TELEMENT;
}



TElem Matrice::modifica(int i, int j, TElem b) {
	if (i<0 || i>linii || j<0 || j>coloane) {
		throw std::exception("Nu e element valid");
	}

	int current = prim;
	int prec = -1;

	while (current >=0  && current<=ultim) {

		if (e[current].i == i && e[current].j == j) {
			TElem vechi = e[current].val;
			e[current].val = b;
			return vechi;
		}
		if (e[current].i >= i && e[current].j > j || e[current].i > i) {
			
			e[urm[current]].i = i;
			e[urm[current]].j = j;
			e[urm[current]].val = b;
			 ultim=urm[current];
			return NULL_TELEMENT;
		}
		prec = current;
		current = urm[current];

	}
	if (prec != -1) {
		//PNod ptr = new Nod(e, i, j, nullptr,nullptr);
		e[current].i = i;
		e[current].j = j;
		e[current].val = b;
		ultim = current;
		return NULL_TELEMENT;
	}
	else {
		//PNod ptr = new Nod(e, i, j, nullptr,nullptr);
		prim = 0;
		e[prim].i = i;
		e[prim].j = j;
		e[prim].val = b;
		ultim = prim;
		return NULL_TELEMENT;
	}

}


IteratorMatrice Matrice::iteratormatrice() const {
	return IteratorMatrice(*this);
}




