#include "Pila.h"

ostream & operator<<(ostream & out, const Pila & p) {
	Ptr temp;
	temp=p.testa;
	while(temp) {
		cout<<temp->elem;
		temp=temp->next;
	}
	return out;
}

Pila::~Pila() {
	Ptr temp;
	while(testa) {
		temp=testa;
		testa=testa->next;
		delete temp;
	}
}

bool Pila::push(const T & e) {
	if(full()) return false;
	Ptr temp;
	temp = new Record;
	temp->elem=e;
	temp->next=testa;
	testa=temp;
	return true;
}

bool Pila::pop(T & e) {
	if(empty()) return false;
	Ptr temp;
	temp=testa;
	e = temp->elem;
	testa = temp->next;
	delete temp;
	return true;
}

bool Pila::top(T & e) const {
	if(empty()) return false;
	e = testa->elem;
	return true;
}

bool Pila::empty() const {
	return (testa==0);
}

bool Pila::full() const {
	return false;
}
