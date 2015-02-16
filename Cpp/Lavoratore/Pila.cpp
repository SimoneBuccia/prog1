#include "Pila.h"

Pila::~Pila() {
	Record * temp;
	while(testa) {
		temp = testa;
		testa = temp->next;
		delete temp;
	}
}
		
bool Pila::push(const T & e) {
	if(full()) return false;
	Record * temp;
	temp = new Record;
	temp->elem = e;
	temp->next = testa;
	testa = temp;
	return true;
}

void Pila::pop(T & e) throw(Errore) {
	if(empty()) throw Errore("Errore: Pila vuota.");
	Record * temp;
	temp = testa;
	e = testa->elem;
	testa = testa->next;
	delete temp;
}

bool Pila::top(T &e) const  {
	if(empty()) return false;
	e = testa->elem;
	return true;
}

ostream & operator<<(ostream& os, const Pila & P) {
	Record * temp;
	temp = P.testa;
	while(temp) {
		os << temp->elem << endl;
		temp = temp->next;
	}
	return os;
}
