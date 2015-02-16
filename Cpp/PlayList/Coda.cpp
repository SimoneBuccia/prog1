#include "Coda.h"

Coda::Coda(const int dim) {
	C = new T[dim];
	maxdim = dim;	
	testa = coda = nelem = 0;
}

Coda::Coda(const Coda & Co) {
	maxdim = Co.maxdim;
	C = new T[maxdim];
	testa = Co.testa;
	coda = Co.coda;
	nelem = Co.nelem;
	for(int i=0; i<maxdim; i++) {
		C[i]=Co.C[i];
	}
}

const Coda & Coda::operator=(const Coda & Co) {
	if(this != &Co) {
		if(C) delete [] C;
		maxdim = Co.maxdim;
		C = new T[maxdim];
		testa = Co.testa;
		coda = Co.coda;
		nelem = Co.nelem;
		for(int i=0; i<maxdim; i++) {
			C[i]=Co.C[i];
		}
	}
	
	return *this;
}
		
bool Coda::append(const T & e) {
	if(full()) return false;
	C[coda] = e;
	coda = ((coda+1)%maxdim);
	nelem++;
	return true;
}


bool Coda::pop(T & e) {
	if(empty()) return false;
	e = C[testa];
	testa = ((testa+1)%maxdim);
	nelem--;
	return true;
}

bool Coda::empty() const {
	return (nelem == 0);
}

bool Coda::full() const {
	return (nelem == maxdim);
}

int Coda::getMaxdim() const {
	return maxdim;
}
		
void Coda::print() const {
	for(int i=0; i<nelem; i++) {
		cout << C[i] << " ";
	}
}
		
