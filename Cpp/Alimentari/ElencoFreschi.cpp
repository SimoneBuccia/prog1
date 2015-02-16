#include "ElencoFreschi.h"

Elenco::~Elenco() {
	Record * temp;
	while(testa) {
		temp = testa;
		testa = testa->next;
		delete temp;
	}
}
		
void Elenco::inserisci(const T & e) throw(Duplicato) {
	Ptr pos;
	if(full() || ricerca(e.getCod(), pos)) {
		char temp[200];
		strcpy(temp, "Elemento con codice '");
		strcat(temp, e.getCod());
		strcat(temp, "' gia' presente.");
		throw Duplicato(temp);
	}
	Ptr temp;
	temp = new Record;
	temp->elem = e;
	temp->next = testa;
	testa = temp;
}

bool Elenco::elimina(const char * c, T & e) {
	Ptr pos;
	if(empty() || !ricerca(c, pos)) return false;
	bool tr = false;
	Ptr temp;
	temp = testa;
	e = pos->elem;
	while(temp&& !tr) {
		if(temp->next==pos) {
			tr = true;
		} else {
			temp = temp->next;
		}
	}
	temp->next=pos->next;
	delete pos;
}

bool Elenco::ricerca(const char * c, Ptr & pos) const {
	if(empty()) return false;
	bool trovato = false;
	Record * temp;
	temp=testa;
	while(temp && !trovato) {
		if(strcmp(temp->elem.getCod(), c)==0) {
			trovato = true;
			pos = temp;
		}
		temp = temp->next;
	}
	
	if(!trovato) {
		pos = 0;
	}
	
	return trovato;
}

void Elenco::stampaElenco() const {
	Ptr temp;
	temp=testa;
	while(temp) {
		temp->elem.stampaDati();
		cout<<"\n";
		temp = temp->next; 
	}
}

void Elenco::stampaFile(ofstream & ofs) const{
	Ptr temp;
	temp=testa;
	while(temp) {
		temp->elem.memorizzaDati(ofs);
		temp = temp->next; 
	}
}

bool Elenco::empty() const {
	return (testa==0);
}

bool Elenco::full() const {
	return false;
}
