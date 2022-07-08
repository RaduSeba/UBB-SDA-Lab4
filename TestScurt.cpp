#include "TestScurt.h"
#include <assert.h>
#include "Matrice.h"
#include "IteratorMatrice.h"
#include <iostream>

using namespace std;

void testAll() { //apelam fiecare functie sa vedem daca exista
	Matrice m(4, 4);
	assert(m.nrLinii() == 4);
	assert(m.nrColoane() == 4);
	//adaug niste elemente
	m.modifica(1, 1, 5);
	assert(m.element(1, 1) == 5);
	m.modifica(1, 1, 6);
	m.modifica(2, 1, 5);
	m.modifica(3, 1, 4);
	assert(m.numarElementeNenule(1) == 3);
	try {
		m.numarElementeNenule(6);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	assert(m.element(1, 2) == NULL_TELEMENT);



	IteratorMatrice im= m.iteratormatrice();
	Triplet e = im.iterator();
	assert(e.val == 6);
}
