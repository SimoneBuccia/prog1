#include "ProdottoFresco.h"

Prodotto::Prodotto(const char * c, const char * d, int m, float p, const char * da) : Alimentari(c,d,m,p) {
	Dat = new char[strlen(da)+1];
	strcpy(Dat, da);
}

Prodotto::Prodotto(const Prodotto & p) : Alimentari(p) {
	Dat = new char[strlen(p.Dat)+1];
	strcpy(Dat, p.Dat);
}

const Prodotto & Prodotto::operator=(const Prodotto & p) {
	if(this!=&p) {
		Alimentari::operator=(p);
		if(Dat) delete [] Dat;
		Dat = new char[strlen(p.Dat)+1];
		strcpy(Dat, p.Dat);
	}
	return *this;
}

const char * Prodotto::getDat() const {
	return Dat; 
}

void Prodotto::setDat(const char * da) {
	if(Dat) delete [] Dat;
	Dat = new char[strlen(da)+1];
	strcpy(Dat, da);
}


ostream & operator<<(ostream & out, const Prodotto & a) {
	out << (Alimentari&)a << a.getDat() << ' ';
}
 
 
void Prodotto::stampaDati() const {
	cout << *this;
}

void Prodotto::memorizzaDati(ostream & out) const {
	out << *this;
}

float Prodotto::Offerta(const int n) {
	if(Mes == 12) {
		return (Pre - (n/100)*Pre);
	} else {
		return 0;
	}
}
