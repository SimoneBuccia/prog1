#include "Coda.h"

int Coda::Incasso=0;

Coda::~Coda() {
	Ptr temp;
	while(testa) {
		temp = testa;
		testa = testa->next;
		delete temp;
	}
}
	
bool Coda::push(const T & e) {
	if(full()) return false;
	Ptr temp;
	temp = new Record;
	temp->next = testa;
	temp->elem = e;
	testa = temp;
}
	
bool Coda::append(const T & e) {
	if(full()) return false;
	if(empty()) {
		push(e);
		coda=testa;	
	} else {
		Ptr temp; 
		temp = new Record;
		temp->next = 0;
		temp->elem = e;
		coda->next=temp;
		coda = temp;
	}
	nelem++;
}

void Coda::pop(T & e, const int t) throw(BadStatus) {
	if(empty()) throw BadStatus("Coda vuota.");
	Ptr temp;
	temp = testa;
	e = testa->elem;
	Incasso += e->calcolaPedaggio(t);
	cout<<e->calcolaPedaggio(t);
	testa = testa->next;
	delete temp;
	nelem--;
	
}

bool Coda::empty() {
	return (nelem == 0);
}

bool Coda::full() {
	return false;
}

ostream & operator<<(ostream & o, const Coda & c) {
	Ptr temp;
	temp=c.testa;
	while(temp) {
		temp->elem->stampaDati();
		cout<<"\n";
		temp=temp->next;
	}
}



