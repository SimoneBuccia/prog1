#include "Manoscritto.h"

Manoscritto::Manoscritto(int c, const char * a, const char * f, const int n) {
	Cod = c;
	Aut = new char[strlen(a)+1];
	strcpy(Aut, a);
	For = new char[strlen(f)+1];
	strcpy(For,f);
	Num=n;
}

Manoscritto::Manoscritto(const Manoscritto & m) {
	Cod = m.Cod;
	Aut = new char[strlen(m.Aut)+1];
	strcpy(Aut, m.Aut);
	For = new char[strlen(m.For)+1];
	strcpy(For,m.For);
	Num=m.Num;
}

const Manoscritto & Manoscritto::operator=(const Manoscritto & m) {
	if(this!=&m) {
		Cod = m.Cod;
		if(Aut) delete [] Aut;
		Aut = new char[strlen(m.Aut)+1];
		strcpy(Aut, m.Aut);
		if(For) delete [] For;
		For = new char[strlen(m.For)+1];
		strcpy(For,m.For);
		Num=m.Num;
	}
	return *this;
}

Manoscritto::~Manoscritto() {
	delete [] Aut;
	delete [] For;
}

const int Manoscritto::getCod() const {
	return Cod;
}

const char * Manoscritto::getAut() const {
	return Aut;
}

const char * Manoscritto::getFor() const {
	return For;
}

const int Manoscritto::getNum() const {
	return Num;
}
	
void Manoscritto::setCod(const int c) {
	Cod = c;
}

void Manoscritto::setAut(const char * a) {
	if(Aut) delete [] Aut;
	Aut = new char[strlen(a)+1];
	strcpy(Aut, a);
}

void Manoscritto::setFor(const char * f) {
	if(For) delete [] For;
	For = new char[strlen(f)+1];
	strcpy(For,f);
}

void Manoscritto::setNum(const int n) {
	Num = n;
}

ostream & operator<<(ostream & out, const Manoscritto & m) {
	out << m.getCod() << ' ' << m.getAut() << ' ' << m.getFor() << ' ' << m.getNum();
	return out;
}

istream & operator>>(istream & in, Manoscritto & m) {
	char tempA[100], tempF[100];
	in >>m.Cod >> tempA >> tempF >> m.Num;
	m.setAut(tempA);
	m.setFor(tempF);
	return in;
}
	
	
void Manoscritto::visualizzaDati() const {
	cout << *this;
}

void Manoscritto::memorizzaDati(ostream & ofs) const {
	ofs << *this << ' ';
}
