#include "Pila.h"

Pila::~Pila() {
	Record * temp;
	while(testa) {
		temp = testa;
		testa = testa->next;
		delete temp;
	}
}

bool Pila::push(const T & e) {
	if(full()) return false;
	Record * temp = new Record;
	temp->elem = e;
	temp->next = testa;
	testa = temp;
	nelem++;
	return true;
}

bool Pila::pop(T & e) {
	if(empty()) return false;
	Record * temp;
	temp = testa;
	e = temp->elem;
	testa = temp->next;
	delete temp;
	nelem--;
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

void Pila::salvaFile(ofstream & ofs) const {
	
	ofs.write((const char *)(&nelem), sizeof(int));
	Record * temp;
	temp = testa;
	while(temp) {
		ofs << temp->elem;
		temp = temp->next;
	}
}

void Pila::leggiFile(ifstream & ifs) throw(Ecc) {
	if(!ifs) throw Ecc("Errore apertura file (eccezione).");
	int size;
	ifs.read((char *)(&size), sizeof(int));
	cout << size;
	Pacco p;
	for(int i=0; i<size; i++) {
		ifs >> p;
		push(p);
	}
}

void Pila::stampa() const {
	Record * temp;
	temp = testa;
	while(temp) {
		cout << temp->elem << '\n';
		temp=temp->next;
	}
}
