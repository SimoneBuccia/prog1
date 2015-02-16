#include "Coda.h"

bool Coda::append(const T & e) {
	if(full()) return false;
	V[coda] = e;
	coda = ((coda+1)%max);
	nelem++;
	return true;
}

bool Coda::pop(File & e) {
	if(empty()) return false;
	e = *V[testa];
	testa = ((testa+1)%max);
	nelem--;
	return true;
}

bool Coda::stampaCoda() const {
	if(empty()) return false;
	for(int i = 0; i < nelem; i++) {
		V[i]->stampa();
		cout << '\n';
	}
	return true;
}

void Coda::memorizzaDati(ofstream & ofs) const {
	for(int i = 0; i < nelem; i++) {
		V[i]->memorizza(ofs);
	}
}
