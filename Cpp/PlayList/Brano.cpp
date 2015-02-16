#include "Brano.h"

Brano::Brano(const string T, const string A, const int I, const float D) {
	Titolo = T;
	Autore = A;
	Id = I;
	Durata = D;
}

string Brano::getTitolo() const {
	return Titolo;
}

void Brano::setTitolo(const string T) {
	Titolo = T;
}

string Brano::getAutore() const {
	return Autore;
}

void Brano::setAutore(const string A) {
	Autore = A;
}

int Brano::getId() const {
	return Id;
}

void Brano::setId(const int I) {
	Id = I;
}

float Brano::getDurata() const {
	return Durata;
}

void Brano::setDurata(const float D) {
	Durata = D;
}

ostream & operator<<(ostream & os, const Brano & B) {
	os << B.getTitolo() << " - " << B.getAutore() << " ["<<B.getId()<<"] " << B.getDurata();
	return os;
}

istream & operator>>(istream & in, Brano & B) {
	char temp[100];
	in.ignore(); 
	cout<<"\nTitolo ->  ";
	in.getline(temp,100);
	B.setTitolo(temp);
	cout<<"\nAutore ->  ";
	in.getline(temp,100);
	B.setAutore(temp);
	cout<<"\nId ->  ";
	in>>B.Id;
	cout<<"\nDurata ->  ";
	in>>B.Durata;
	return in;
}
