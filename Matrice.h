#pragma once
//#include "Nod.h"

typedef int TElem;




#define NULL_TELEMENT 0


struct Triplet {
	int i, j;
	TElem val;
};

class Matrice {

private:

	friend class IteratorMatrice;
	/* aici e reprezentarea */
	int cp;
	int linii, coloane;
	Triplet* e;
	int* urm;
	int* prec;
	int prim;
	int ultim;
	int primLiber;



	//functie pentru alocarea unui spatiu liber
	//se returneaza pozitia spatiului liber din lista
	int aloca();

	//functie pentru dealocarea spatiului de pe indicele i
	void dealoca(int i);

	//functie ce creeaza un nod in lista inlantuita
	int creeazaNod(Triplet elem);

	//functie ce redimensioneaza lista inlantuita
	void redim();

public:

	//constructor
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	Matrice(int nrLinii, int nrColoane);


	//destructor
	/*
	Caz favorabil = Caz defavorabil = Caz mediu = Theta(1)
	Complexitate generala: Theta(1)
	*/
	~Matrice() {};

	/*returnare element de pe o linie si o coloana
	se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	indicii se considera incepand de la 0
	
	Caz favorabil = Theta(1)
	Caz defavorabil = Theta(n*m)
	Caz mediu = Theta(n*m)
	Complexitate generala: O(n*m)
	*/
	TElem element(int i, int j) const;


	// returnare numar linii
	/*
	Caz favorabil = Caz defavorabil = Caz mediu = Theta(1)
	Complexitate generala: Theta(1)
	*/
	int nrLinii() const;

	// returnare numar coloane
	/*
	Caz favorabil = Caz defavorabil = Caz mediu = Theta(1)
	Complexitate generala: Theta(1)
	*/
	int nrColoane() const;


	/*
	* returneaza numarul de elemente de pe o coloana data
	* arunca exceptie in cazul in care coloana nu este valida
	Caz favorabil = Theta(1)
	Caz defavorabil = Theta(n)
	Caz mediu = Theta(n)
	Complexitate generala: O(n)
	Subalgoritm numarElementeNenule(col)
	pre:ldi:Ldi,act:NodLdi,col:int
	* post:returneaza numarul de elemente nenule de pe coloana data
	* int k=0;
	* daca col <= 0 sau col>m.nrcoloane
	*	@arunca exceptie
	* Sfdaca
	* NodLdi current= m.prim;
	* cat timp current!=null executa
	* int idx_j = [current].util.j;
	*	daca idx_j == col si [current].util.val!=0
	*		
	*	SfDaca
	*	[current]<-[current].urmator
	* Sf cat timp
	* returneaza k
	* SfSubAlgoritm
	*/
	int numarElementeNenule(int col) const;

	// modificare element de pe o linie si o coloana si returnarea vechii valori
	// se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	/*
	Caz favorabil = Theta(1)
	Caz defavorabil = Theta(n)
	Caz mediu = Theta(n)
	Complexitate generala: O(n)
	n=nr de elemente nenule
	*/
	TElem modifica(int i, int j, TElem);

	IteratorMatrice iteratormatrice() const;

};







