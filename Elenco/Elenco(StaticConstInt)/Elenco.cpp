#include "Elenco.h"

void Elenco::push(const T & e) throw(Duplicato) {
	if(!full()) {
		if(empty()) {
			V[nelem] = e;
			nelem++;
		} else {
			for(int i=0; i<nelem; i++) {
				if(e->getCod() == V[i]->getCod()) throw Duplicato("Duplicato.");
			}
			int i=0;
			
			while(i<nelem && e->getCod() > V[i]->getCod()) {
				i++;
			}
			
			for(int j=nelem; j>i; j--) {
				V[j] = V[j-1];
				
			}	
			V[i]=e;
			nelem++;
		}
	}	
}

bool Elenco::pop(const int c) {
	if(empty()) return false;
	for(int i=0; i<nelem; i++) {
		if(c == V[i]->getCod()) {
			for(int j=i; j<nelem; j++) {
				V[j]=V[j+1];
			}
			nelem--;
		}
	}
}

void Elenco::stampa() const {
	for(int i=0; i<nelem; i++) {
		V[i]->visualizzaDati();
		cout << '\n';
	}
}

void Elenco::memorizzaDati(ostream & ofs) const {
	for(int i=0; i<nelem; i++) {
		V[i]->memorizzaDati(ofs);
	}
}
