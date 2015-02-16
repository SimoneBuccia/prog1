#include "Autovettura.h"

Autovettura::Autovettura(const char * t, const char * a, const char * ti, const int po) : Autoveicolo(t,a) {
	Tipo = new char[strlen(ti)+1];
	strcpy(Tipo, ti);
	Posti = po;
}

Autovettura::Autovettura(const Autovettura & a) : Autoveicolo(a) {
	Tipo = new char[strlen(a.Tipo)+1];
	strcpy(Tipo, a.Tipo);
	Posti = a.Posti;
}

const Autovettura & Autovettura::operator=(const Autovettura & a) {
	if(this!=&a) {
		Autoveicolo::operator=(a);
		if(Tipo) delete [] Tipo;
		Tipo = new char[strlen(a.Tipo)+1];
		strcpy(Tipo, a.Tipo);
		Posti = a.Posti;
	}
	return *this;
}

Autovettura::~Autovettura() {
	delete [] Tipo;
}
	
const char * Autovettura::getTipo() const {
	return Tipo;
}

void Autovettura::setTipo(const char * ti) {
	if(Tipo) delete [] Tipo;
	Tipo = new char[strlen(ti)+1];
	strcpy(Tipo, ti);
}

const int Autovettura::getPosti() const {
	return Posti;
}

void Autovettura::setPosti(const int po) {
	Posti = po;
}

ostream & operator<<(ostream & out, const Autovettura & a) {
	out << (Autoveicolo&)a << a.getTipo() << ' ' << a.getPosti() << ' ';
	return out;
}

istream & operator>>(istream & in, Autovettura & a) {
	in>>(Autoveicolo&)a;
	char temp[100];
	cout << "Tipo (suv, monovolume, berlina) -> ";
	in.getline(temp, 100);
	a.setTipo(temp);
	cout << "Posti -> ";
	in>>a.Posti;
	in.ignore();
	return in;
}

void Autovettura::stampaDati() const {
	cout << *this;
}

const float Autovettura::calcolaPedaggio(const int base) const {
	if(strcasecmp(Tipo, "suv")==0) {
		return base+4;
	} else if(strcasecmp(Tipo, "monovolume")==0) {
		return base+2;
	} else if(strcasecmp(Tipo, "berlina")==0) {
		return base+1;
	} else {
		return base;
	}
}
