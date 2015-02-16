#include "Giornale.h"

ostream & operator<<(ostream & out, const Giornale & g) {
	return g.stampaDati(out);
}

ofstream & operator<<(ofstream & out, const Giornale & g) {
	return g.memorizzaDati(out);
}

istream & operator>>(istream & in, Giornale & g) {
	char tempT[100], tempP[100];
	in >> g.costo >> tempT >> tempP;
	if(strcasecmp(tempP, "true")==0) {
		g.setPeriodico(true);
	} else {
		g.setPeriodico(false);
	}
	g.setTitolo(tempT);
	
	return in;
}

Giornale::Giornale(const float c, const char * t, const bool p) {
	costo = c;
	titolo = new char[strlen(t)+1];
	strcpy(titolo, t);
	periodico = p;
}

Giornale::Giornale(const Giornale & g) {
	costo = g.costo;
	titolo = new char[strlen(g.titolo)+1];
	strcpy(titolo, g.titolo);
	periodico = g.periodico;
}

const Giornale & Giornale::operator=(const Giornale & g) {
	if(this!=&g) {
		costo = g.costo;
		if(titolo) delete [] titolo;
		titolo = new char[strlen(g.titolo)+1];
		strcpy(titolo, g.titolo);
		periodico = g.periodico;
	}
	return *this;
}

Giornale::~Giornale() {
	delete [] titolo;
}

const float Giornale::getCosto() const {
	return costo;
}

void Giornale::setCosto(const float c) {
	costo = c;
}

const char * Giornale::getTitolo() const {
	return titolo;
}

void Giornale::setTitolo(const char * t) {
	if(titolo) delete [] titolo;
	titolo = new char[strlen(t)+1];
	strcpy(titolo, t);
}

const bool Giornale::getPeriodico() const {
	return periodico;
}

void Giornale::setPeriodico(const bool p) {
	periodico = p;
}

ostream & Giornale::stampaDati(ostream & out) const {	
	out << "Costo -> " << getCosto() << "\nTitolo -> " << getTitolo() << "\nPeriodico -> ";
	if(getPeriodico()) {
		out << "Si";
	} else {
		out << "No";
	}
	return out;
}

ofstream & Giornale::memorizzaDati(ofstream & out) const {
	out << getCosto() << ' ' << getTitolo() << ' ' << getPeriodico();
	return out;
}
