#include "Alimentari.h"

Alimentari::Alimentari(const char * c, const char * d, int m, float p) {
	Cod = new char[strlen(c)+1];
	strcpy(Cod, c);
	Des = new char[strlen(d)+1];
	strcpy(Des, d);
	Mes = m;
	Pre = p;
}

Alimentari::Alimentari(const Alimentari & a) {
	Cod = new char[strlen(a.Cod)+1];
	strcpy(Cod, a.Cod);
	Des = new char[strlen(a.Des)+1];
	strcpy(Des, a.Des);
	Mes = a.Mes;
	Pre = a.Pre;
}

const Alimentari & Alimentari::operator=(const Alimentari & a) {
	if(this!=&a) {
		if(Cod) delete [] Cod;
		Cod = new char[strlen(a.Cod)+1];
		strcpy(Cod, a.Cod);
		if(Des) delete [] Des;
		Des = new char[strlen(a.Des)+1];
		strcpy(Des, a.Des);
		Mes = a.Mes;
		Pre = a.Pre;
	}
	return *this;
}

const char * Alimentari::getCod() const {
	return Cod;
}

void Alimentari::setCod(const char * c) {
	if(Cod) delete [] Cod;
	Cod = new char[strlen(c)+1];
	strcpy(Cod, c);
}

const char * Alimentari::getDes() const {
	return Des;
}

void Alimentari::setDes(const char * d) {
	if(Des) delete [] Des;	
	Des = new char[strlen(d)+1];
	strcpy(Des, d);
}

const int Alimentari::getMes() const {
	return Mes;
}

void Alimentari::setMes(const int m) {
	Mes = m;
}

const float Alimentari::getPre() const {
	return Pre;
}

void Alimentari::setPre(const float p) {
	Pre = p;
}

ostream & operator<<(ostream & out, const Alimentari & a) {
	out << a.getCod() << ' ' << a.getDes() << ' ' << a.getMes() << ' ' << a.getPre() << ' ';
	return out;
}
 
void Alimentari::stampaDati() const {
	cout << *this;
}

void Alimentari::memorizzaDati(ostream & out) const {
	out << *this;
}
