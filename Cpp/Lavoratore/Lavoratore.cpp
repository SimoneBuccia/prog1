#include "Lavoratore.h"

Lavoratore::Lavoratore(const char * Ma, const char * Az, const int An, const float St) {
	Matricola = new char[strlen(Ma)+1];
	strcpy(Matricola, Ma);
	Azienda = new char[strlen(Az)+1];
	strcpy(Azienda, Az);
	Anzianita = An;
	StipendioBase = St;
}

Lavoratore::Lavoratore(const Lavoratore & L) {
	if(Matricola) delete [] Matricola;
	if(Azienda) delete [] Azienda;
	Matricola = new char[strlen(L.Matricola)+1];
	strcpy(Matricola, L.Matricola);
	Azienda = new char[strlen(L.Azienda)+1];
	strcpy(Azienda,L.Azienda);
	Anzianita = L.Anzianita;
	StipendioBase = L.StipendioBase;
}

const char * Lavoratore::getMatricola() const {
	return Matricola;
}

void Lavoratore::setMatricola(const char * m) {
	if(Matricola) delete [] Matricola;
	Matricola = new char[strlen(m)+1];
	strcpy(Matricola, m);
}

const char * Lavoratore::getAzienda() const {
	return Azienda;
}

void Lavoratore::setAzienda(const char * a) {
	if(Azienda) delete [] Azienda;
	Azienda = new char[strlen(a)+1];
	strcpy(Azienda, a);
}

int Lavoratore::getAnzianita() const {
	return Anzianita;
}

void Lavoratore::setAnzianita(const int a) {
	Anzianita = a;
}

float Lavoratore::getStipendioBase() const {
	return StipendioBase;
}

void Lavoratore::setStipendioBase(const float s) {
	StipendioBase = s;
}

float Lavoratore::calcolaStipendio() const {
	return StipendioBase*Anzianita;
}

const Lavoratore & Lavoratore::operator=(const Lavoratore & L) {
	if(this!=&L) {
		if(Matricola) delete [] Matricola;
		if(Azienda) delete [] Azienda;
		Matricola = new char[strlen(L.Matricola)+1];
		strcpy(Matricola, L.Matricola);
		Azienda = new char[strlen(L.Azienda)+1];
		strcpy(Azienda,L.Azienda);
		Anzianita = Anzianita;
		StipendioBase = StipendioBase;
	}
	return *this;
}


ostream & operator<<(ostream & os, const Lavoratore & L) {
	os << L.getMatricola() << " " << L.getAzienda();
	return os;
}

istream & operator>>(istream & in, Lavoratore & L) {
	char temp[100];
	in.ignore();
	cout << "Inserisci Matricola: ";
	in.getline(temp, 100);
	L.setMatricola(temp);
	cout << "Inserisci Azienda: ";
	in.getline(temp,100);
	L.setAzienda(temp);
	cout << "Inserisci Anzianita: ";
	in >> L.Anzianita;
	cout << "Inserisci StipendioBase: ";
	in >> L.StipendioBase;
	
	return in;
}
	
