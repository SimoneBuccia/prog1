#include "Quotidiano.h"

ostream & operator<<(ostream & out, const Quotidiano & q) {
	return q.stampaDati(out);
}

ofstream & operator<<(ofstream & out, const Quotidiano & q) {
	return q.memorizzaDati(out);
}

istream & operator>>(istream & in, Quotidiano & q) {
	char tempD[100], tempI[100];
	in >> tempD >> tempI;
	
	q.setDirettore(tempD);
	if(strcasecmp(tempI, "true")==0) {
		q.setInserto(true);
	} else {
		q.setInserto(false);
	}
	return in;
}

Quotidiano::Quotidiano(const float c, const char * t, const bool p, const char * di, const bool in) : Giornale(c,t,p) {
	direttore = new char[strlen(di)+1];
	strcpy(direttore, di);
	inserto = in;
}

Quotidiano::Quotidiano(const Quotidiano & q) : Giornale(q) {
	direttore = new char[strlen(q.direttore)+1];
	strcpy(direttore, q.direttore);
	inserto = q.inserto;
}

const Quotidiano & Quotidiano::operator=(const Quotidiano & q) {
	if(this!=&q) {
		Giornale::operator=(q);
		if(direttore) delete [] direttore;
		direttore = new char[strlen(q.direttore)+1];
		strcpy(direttore, q.direttore);
		inserto = q.inserto;
	}
	return *this;
}

Quotidiano::~Quotidiano() {
	delete [] direttore;
}

const char * Quotidiano::getDirettore() const {
	return direttore;
}

void Quotidiano::setDirettore(const char * di) {
	if(direttore) delete [] direttore;
	direttore = new char[strlen(di)+1];
	strcpy(direttore, di);
}

const bool Quotidiano::getInserto() const {
	return inserto;
}

void Quotidiano::setInserto(const bool in) {
	inserto = in;
}

ostream & Quotidiano::stampaDati(ostream & out) const {
	Giornale::stampaDati(out);
	out << "\nDirettore -> " << getDirettore() << "\nInserto -> ";
	if(getInserto()) {
		out << "Si";
	} else {
		out << "No";
	}
	return out;
}

ofstream & Quotidiano::memorizzaDati(ofstream & out) const {
	Giornale::memorizzaDati(out);
	out << ' ' << getDirettore() << ' ' << getInserto();
	return out;
}
