#include "Pila.h"

ostream & operator<<(ostream & out, const Pila & p) {
	return p.stampaPila(out);
}

ofstream & operator<<(ofstream & out, const Pila & p) {
	return p.memorizzaPila(out);
}
	
void Pila::push(const Q & e) throw(SpaceOverflow) {
	if(full()) throw SpaceOverflow("Pila piena.");
	V[testa++] = e;
	nelem++;
}

bool Pila::pop(Q & e) {
	if(empty()) return false;
	e = V[testa--];
	nelem--;
	return true;
}

bool Pila::top(Q & e) const {
	e = V[testa-1];
}

bool Pila::empty() const {
	return(testa == 0);
}
bool Pila::full() const {
	return (nelem==max);
}

ostream & Pila::stampaPila(ostream & out) const {
	for(int i=0; i<nelem; i++) {
		out<<*V[i]<< "\n\n";
	}
	return out;
}

ofstream & Pila::memorizzaPila(ofstream & out) const {
	for(int i=0; i<nelem; i++) {
		out<<*V[i]<< " ";
	}
	return out;
}

