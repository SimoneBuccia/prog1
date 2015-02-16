#include "Fiches.h"

ostream & operator<<(ostream & out, const Fiches & f) {
	out << (Gettone&)f << f.getFor() << ' ' << f.getCol() << ' ';
	return out;	
}

istream & operator>>(istream & in, Fiches & f) {
	char temp[100];
	cout << "Forma -> ";
	in.getline(temp, 100);
	f.setFor(temp);
	cout << "Colore -> ";
	in.getline(temp, 100);
	f.setCol(temp);
	return in;
}
	
Fiches::Fiches(const char * m, const int v, const char * f, const char * c) : Gettone(m,v) {
	For = new char[strlen(f)+1];
	strcpy(For, f);
	Col = new char[strlen(c)+1];
	strcpy(Col, c);
}

Fiches::Fiches(const Fiches & f) : Gettone(f) {
	For = new char[strlen(f.For)+1];
	strcpy(For, f.For);
	Col = new char[strlen(f.Col)+1];
	strcpy(Col, f.Col);
}

const Fiches & Fiches::operator=(const Fiches & f) {
	if(this!=&f) {
		Gettone::operator=(f);
		For = new char[strlen(f.For)+1];
		strcpy(For, f.For);
		Col = new char[strlen(f.Col)+1];
		strcpy(Col, f.Col);
	}
	return *this;
}

Fiches::~Fiches() {
	if(For) delete For;
	if(Col) delete Col;
}
		
const char * Fiches::getFor() const {
	return For;
}

void Fiches::setFor(const char * f) {
	if(For) delete For;
	For = new char[strlen(f)+1];
	strcpy(For, f);
}

const char * Fiches::getCol() const {
	return Col;
}

void Fiches::setCol(const char * c) {
	if(Col) delete Col;
	Col = new char[strlen(c)+1];
	strcpy(Col, c);
}

void Fiches::print() const {
	cout << *this;
}


