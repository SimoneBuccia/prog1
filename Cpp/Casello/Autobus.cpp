#include "Autobus.h"

Autobus::Autobus(const char * t, const char * a, const char * des, const int mas) : Autoveicolo(t,a) {
	Dest = new char[strlen(des)+1];
	strcpy(Dest, des);
	Massa = mas;
}

Autobus::Autobus(const Autobus & a) : Autoveicolo(a) {
	Dest = new char[strlen(a.Dest)+1];
	strcpy(Dest, a.Dest);
	Massa = a.Massa;
}

const Autobus & Autobus::operator=(const Autobus & a) {
	if(this!=&a) {
		Autoveicolo::operator=(a);
		if(Dest) delete [] Dest;
		Dest = new char[strlen(a.Dest)+1];
		strcpy(Dest, a.Dest);
		Massa = a.Massa;
	}
	return *this;
}

Autobus::~Autobus() {
	delete [] Dest;
}
	
const char * Autobus::getDest() const {
	return Dest;
}

void Autobus::setDest(const char * des) {
	if(Dest) delete [] Dest;
	Dest = new char[strlen(des)+1];
	strcpy(Dest, des);
}

const int Autobus::getMassa() const {
	return Massa;
}

void Autobus::setMassa(const int mas) {
	Massa = mas;
}

ostream & operator<<(ostream & out, const Autobus & a) {
	out << (Autoveicolo&)a << a.getDest() << ' ' << a.getMassa() << ' ';
	return out;
}

istream & operator>>(istream & in, Autobus & a) {
	in>>(Autoveicolo&)a;
	char temp[100];
	cout << "Destinazione (suv, monovolume, berlina) -> ";
	in.getline(temp, 100);
	a.setDest(temp);
	cout << "Massa -> ";
	in>>a.Massa;
	in.ignore();
	return in;
}

void Autobus::stampaDati() const {
	cout << *this;
}

const float Autobus::calcolaPedaggio(const int base) const {
	if(getMassa() < 100) {
		return (base + 2);
	} else if(getMassa()  < 200) {
		return (base + 4);
	} else if(getMassa()  < 400) {
		return (base + 8);
	} else {
		return base;
	}
}
