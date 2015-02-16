#include "Libro.h"


	Libro::Libro(const char* I, const char* T,const char* A, const char* t,const int a): Oggetto(I,T){
	Autori=new char[strlen(A)+1];
	strcpy(Autori,A);
	Titolo=new char[strlen(T)+1];
	strcpy(Titolo,t);
	Anno=a;
	}
	Libro::Libro(const Libro& L):Oggetto(L){
	Autori=new char[strlen(L.Autori)+1];
	strcpy(Autori,L.Autori);
	Titolo=new char[strlen(L.Titolo)+1];
	strcpy(Titolo,L.Titolo);
	Anno=L.Anno;
	}
	Libro & Libro::operator=(const Libro& L){
	if(this!=&L){
	Oggetto::operator=(L);
	if(Autori) delete[]Autori;
	Autori=new char[strlen(L.Autori)+1];
	strcpy(Autori,L.Autori);
	if(Titolo) delete[]Titolo;
	Titolo=new char[strlen(L.Titolo)+1];
	strcpy(Titolo,L.Titolo);
	Anno=L.Anno;
	}
	return *this;
	}
	
	const char* Libro::get_Autori() const{
	return Autori;}
	const char* Libro::get_Titolo() const{
	return Titolo;}
	int Libro::get_Anno() const{
	return Anno;}
	
	void Libro::set_Autori(const char*A){
	if(Autori) delete[] Autori;
	Autori=new char[strlen(A)+1];
	strcpy(Autori,A);}
	
	void Libro::set_Titolo(const char*T){
	if(Titolo) delete[]Titolo;
	Titolo=new char[strlen(T)+1];
	strcpy(Titolo,T);
	}
	void Libro::set_Anno(const int A) {
	Anno=A;
	}
	
	ostream & operator<<(ostream & os, const Libro&L){
	os<<(Oggetto&)L<<" "<<L.Autori<<" "<<L.Titolo<<" "<<L.Anno;
	return os;
	}
	istream & operator>>(istream & is, Libro& L){
	char tmp[100];
	cout<<"Autori: ";
	is.getline(tmp,100);
	L.set_Autori(tmp);
	is.ignore();
	cout<<"Titolo: ";
	is.getline(tmp,100);
	L.set_Titolo(tmp);
	is>>L.Anno;
	return is;}
