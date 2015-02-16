#include "Coda.h"

Coda::Coda(const char * filename) {
	testa = coda = nelem = 0;
	ifstream in(filename, ios::binary|ios::in);
	for(int i=0; i<2; i++) {
		in>>V[i];
		coda=((coda+1)%max);
		nelem++;
	}
}

void Coda::append(const T & e) throw(Errore) {
	if(full()) throw Errore("Coda piena.");
	V[coda] = e;
	coda = ((coda+1)%max);
	nelem++;
}

void Coda::pop(T & e) throw(Errore){
	if(empty()) throw Errore("Coda vuota.");
	e = V[testa];
	testa = ((testa+1)%max);
	nelem--;
}

bool Coda::stampa() const {
	for(int i=0; i<nelem; i++) {
		cout << V[i] << '\n';
	}
}
		
		
