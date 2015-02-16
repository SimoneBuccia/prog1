#include "Autoveicolo.h"

Autoveicolo::Autoveicolo(const char * t, const char * a) {
	Targa = new char[strlen(t)+1];
	strcpy(Targa, t);
	Alim = new char[strlen(a)+1];
	strcpy(Alim, a);
}

Autoveicolo::Autoveicolo(const Autoveicolo & a) {
	Targa = new char[strlen(a.Targa)+1];
	strcpy(Targa, a.Targa);
	Alim = new char[strlen(a.Alim)+1];
	strcpy(Alim, a.Alim);
}

const Autoveicolo & Autoveicolo::operator=(const Autoveicolo & a) {
	if(this!=&a) {
		if(Targa) delete [] Targa;
		Targa = new char[strlen(a.Targa)+1];
		strcpy(Targa, a.Targa);
		if(Alim) delete [] Alim;
		Alim = new char[strlen(a.Alim)+1];
		strcpy(Alim, a.Alim);
	}
	return *this;
}

Autoveicolo::~Autoveicolo() {
	delete [] Targa;
	delete [] Alim;
}
	
const char * Autoveicolo::getTarga() const {
	return Targa;
}

void Autoveicolo::setTarga(const char * t) {
	if(Targa) delete [] Targa;
	Targa = new char[strlen(t)+1];
	strcpy(Targa, t);
}

const char * Autoveicolo::getAlim() const {
	return Alim;
}

void Autoveicolo::setAlim(const char * a) {
	if(Alim) delete [] Alim;
	Alim = new char[strlen(a)+1];
	strcpy(Alim, a);
}

ostream & operator<<(ostream & out, const Autoveicolo & a) {
	out << a.getTarga() << ' ' << a.getAlim() << ' ';
	return out;
}

istream & operator>>(istream & in, Autoveicolo & a) {
	char temp[100];
	cout << "Targa -> ";
	in.getline(temp, 100);
	a.setTarga(temp);
	cout << "Alimentazione -> ";
	in.getline(temp, 100);
	a.setAlim(temp);
	return in;
}
	
