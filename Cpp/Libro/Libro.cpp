#include "Libro.h"

Libro::Libro(const char * i, const char * ti, const char * au, const char * t, const int an) : Oggetto(i,ti) {
	autore = new char[strlen(au)+1];
	strcpy(autore, au);
	titolo = new char[strlen(t)+1];
	strcpy(titolo, t);
	anno = an;
}

Libro::Libro(const Libro & l) : Oggetto(l) {
	autore = new char[strlen(l.autore)+1];
	strcpy(autore, l.autore);
	titolo = new char[strlen(l.titolo)+1];
	strcpy(titolo, l.titolo);
	anno = l.anno;
}

const Libro & Libro::operator=(const Libro & l) {
	if(this!=&l) {
		Oggetto::operator=(l);
		if(autore) delete [] autore;
		autore = new char[strlen(l.autore)+1];
		strcpy(autore, l.autore);
		if(titolo) delete [] titolo;
		titolo = new char[strlen(l.titolo)+1];
		strcpy(titolo, l.titolo);
		anno = l.anno;
	}
	return *this;
}

const char * Libro::getAutore() const {
	return autore;
}

void Libro::setAutore(const char * a) {
	if(autore) delete [] autore;
	autore = new char[strlen(a)+1];
	strcpy(autore, a);
}
	
const char * Libro::getTitolo() const {
	return titolo;
}

void Libro::setTitolo(const char * t) {
	if(titolo) delete [] titolo;
	titolo = new char[strlen(t)+1];
	strcpy(titolo, t);
}

const int Libro::getAnno() const {
	return anno;
}

void Libro::setAnno(const int a) {
	anno = a;
}

ostream & operator<<(ostream & out, const Libro & l) {
	out << (Oggetto&)l << ' '<<l.getAutore() <<' '<< l.getTitolo()<< ' ' <<l.getAnno();
	return out;
}

istream & operator>>(istream & in, Libro & l) {
	in>>(Oggetto&)l;
	char temp[100];
	cout<<"Autore -> ";
	in.getline(temp,100);
	l.setAutore(temp);
	cout<<"Titolo -> ";
	in.getline(temp,100);
	l.setTitolo(temp);
	cout<<"Anno -> ";
	in >> l.anno;
	in.ignore();
	return in;
}
