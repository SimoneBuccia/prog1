#include "Vettore.h"


Vettore::Vettore(const int n) {
	int size = (n<0) ? 10 : n;
	Pacco pv;
	V = new Pacco[size];
	nelem=size;
	for(int i=0; i<size; i++) {
		V[i] = pv;
	}
}

Vettore::Vettore(const Vettore & v) {
	int size = v.nelem;
	V = new Pacco[size];
	
	for(int i=0; i<size; i++) {
		V[i]=v[i];
	}
}

Vettore::~Vettore() {
	delete [] V;
}

const Vettore & Vettore::operator=(const Vettore & v) {
	if(this!=&v) {
		int size = v.nelem;
		delete [] V;
		V = new Pacco[size];
		
		for(int i=0; i<size; i++) {
			V[i]=v[i];
		}
	}
	return *this;
}

Pacco & Vettore::operator[](int index) {
	if(index<0||index>nelem) {
		exit(1);
	}
	return V[index];
}

const Pacco & Vettore::operator[](int index) const {
	if(index<0||index>nelem) {
		exit(1);
	}
	return V[index];
}

Pacco & Vettore::Access(int index) throw(Errore) {
	if(index<0||index>nelem) {
		throw Errore("Out of range.");
	}
	return V[index];
}

const Pacco & Vettore::Access(int index) const throw(Errore) {
	if(index<0||index>nelem) {
		throw Errore("Out of range.");
	}
	return V[index];
}

void Vettore::Elimina() {
	for(int i =0; i < nelem; i++) {
		if(V[i].getPeso() > 500) {
			for(int j=i; j<nelem; j++) {
				V[j]=V[j+1];
				nelem--;
			}
		}
	}
}
