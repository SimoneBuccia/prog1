#include "Rivista.h"

ostream & operator<<(ostream & out, const Rivista & r) {
	return r.stampaDati(out);
}

ofstream & operator<<(ofstream & out, const Rivista & r) {
	return r.memorizzaDati(out);
}

istream & operator>>(istream & in, Rivista & r) {
	char tempE[100], tempP[100];
	in >> tempE >> tempP;
	r.setEditore(tempE);
	r.setPeriodo(tempP);
	return in;
}

Rivista::Rivista(const float c, const char * t, const bool p, const char * ed, const char * pe) : Giornale(c,t,p) {
	editore = new char[strlen(ed)+1];
	strcpy(editore, ed);
	periodo = new char[strlen(pe)+1];
	strcpy(periodo, pe);
}

Rivista::Rivista(const Rivista & r) : Giornale(r) {
	editore = new char[strlen(r.editore)+1];
	strcpy(editore, r.editore);
	periodo = new char[strlen(r.periodo)+1];
	strcpy(periodo, r.periodo);
}

const Rivista & Rivista::operator=(const Rivista & r) {
	if(this!=&r) {
		Giornale::operator=(r);
		if(editore) delete [] editore;
		editore = new char[strlen(r.editore)+1];
		strcpy(editore, r.editore);
		if(periodo) delete [] periodo;
		periodo = new char[strlen(r.periodo)+1];
		strcpy(periodo, r.periodo);
	}
	return *this;
}

Rivista::~Rivista() {
	delete [] editore;
	delete [] periodo;
}

const char * Rivista::getEditore() const {
	return editore;
}

void Rivista::setEditore(const char * ed) {
	if(editore) delete [] editore;
	editore = new char[strlen(ed)+1];
	strcpy(editore, ed);
}

const char * Rivista::getPeriodo() const {
	return periodo;
}

void Rivista::setPeriodo(const char * pe) {
	if(periodo) delete [] periodo;
	periodo = new char[strlen(pe)+1];
	strcpy(periodo, pe);
}

ostream & Rivista::stampaDati(ostream & out) const {
	Giornale::stampaDati(out);
	out << "\nEditore -> " << getEditore() << "\nPeriodo -> " << getPeriodo();
	return out;
}

ofstream & Rivista::memorizzaDati(ofstream & out) const {
	Giornale::memorizzaDati(out);
	out << ' ' << getEditore() << ' ' << getPeriodo();
	return out;
}
