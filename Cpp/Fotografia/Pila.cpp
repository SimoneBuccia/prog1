#include "Pila.h"

bool Pila::pop(T & e) {
	if(empty()) return false;
	testa--;
	e = V[testa];
	return true;
}

bool Pila::top(T & e) const {
	if(empty()) return false;
	e = V[testa-1];
	return true;
}

bool Pila::push(const T & e) {
	if(full()) return false;
	V[testa] = e;
	testa++;
	return true;
}

bool Pila::empty() const {
	return (testa==0);
}

bool Pila::full() const {
	return (testa==dim);
}

bool Pila::sposta_in_testa(const int id) {
	bool trovato = false;
	int pos = 0;
	while(pos<testa-1&&!trovato) {
		if(V[pos].getChiave() == id) {
			T temp;
			temp = V[testa-1];
			V[testa-1] = V[pos];
			V[pos] = temp;
			return true;
		}
	}
	return false;
}

ostream & operator<<(ostream & out, const Pila & p) {
	for(int i = (p.testa-1); i>=0; i--) {
		out << p.V[i] << "\n";
	}
	return out;
}

istream & operator>>(istream & in, Pila & e) {
	T F;
	while(in>>F) e.push(F);
	return in;
}
