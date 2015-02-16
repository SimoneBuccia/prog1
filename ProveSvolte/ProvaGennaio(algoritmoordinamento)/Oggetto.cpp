#include "Oggetto.h"


	Oggetto::Oggetto(){
	strcpy(ID,"");
	strcpy(Tipo,"");
	}	
	Oggetto::Oggetto(const char*I, const char*T){
	ID=new char[strlen(I)+1];
	strcpy(ID,I);
	Tipo=new char[strlen(T)+1];
	strcpy(Tipo,T);
	}
	Oggetto::Oggetto(const Oggetto&O){
	ID=new char[strlen(O.ID)+1];
	strcpy(ID,O.ID);
	Tipo=new char[strlen(O.Tipo)+1];
	strcpy(Tipo,O.Tipo);
	}
	
	const char* Oggetto::get_ID() const{
	return ID;}
	const char* Oggetto::get_Tipo() const{
	return Tipo;}
	
	void Oggetto::set_ID(const char*I){
	if(ID) delete[] ID;
	ID=new char[strlen(I)+1];
	strcpy(ID,I);
	 }
	void Oggetto::set_Tipo(const char*T){
	if(Tipo) delete[] Tipo;
	Tipo=new char[strlen(T)+1];
	strcpy(Tipo,T);
	}
	
	Oggetto & Oggetto::operator=(const Oggetto&O){
	if(this!=&O) {
	if (ID) delete [] ID;
	ID=new char[strlen(O.ID)+1];
	strcpy(ID,O.ID);
	if(Tipo) delete[] Tipo;
	Tipo=new char[strlen(O.Tipo)+1];
	strcpy(Tipo,O.Tipo);
	}
	return *this;
	}
	
	ostream & operator<<(ostream & os, const Oggetto&O){
	os<<O.ID<<" "<<O.Tipo;
	return os;
	}
	istream & operator>>(istream & is, Oggetto&O){
	char tmp[100];
	cout<<"ID: ";
	is.getline(tmp,100);
	O.set_ID(tmp);
	is.ignore();
	cout<<"Tipo: ";
	is.getline(tmp,100);
	O.set_Tipo(tmp);
	return is;
	}
