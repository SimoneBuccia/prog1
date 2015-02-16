#include "CodaL.h"

bool CodaL::append (const T & e)  {
	if(full()) return false;
	if(testa==coda) {
		push(e);
	} else {
		Record * temp;
		temp = new Record;
		temp->elem = e;
		temp-next = coda;
		coda = temp;
	}
	return true;
}

bool CodaL::pop(T & e) {
	if(empty()) return false;
	e = testa->elem;
	Record * temp = testa;
	testa = testa->next;
	delete temp;
	return true;
}

void CodaL::push(const T &) {
	Record * temp;
	temp = new Record;
	temp->elem = e;
	temp->next = 0;
	testa = temp;
}

CodaL::~Coda() {
	if(!empty()) {
		Record * temp;
		temp=coda;
		while(temp) {
			coda = temp->next;
			delete temp;
			temp = coda;
		}
	}
	delete testa;
	delete coda;
}
