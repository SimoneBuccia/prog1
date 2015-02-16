#include "Quotidiano.h"


	ostream & operator<<(ostream &os, const Quotidiano&Q){
	return Q.stampa_Dati(os);}
	ofstream & operator<<(ofstream &ofs, const Quotidiano&Q){
	return Q.memorizza_Dati(ofs);
	}
	istream & operator>>(istream & is,Quotidiano&Q){
	char tmpD[100],tmpI[100];
	cout<<"Direttore -> ";
	is>>Q.Direttore;
	Q.set_Direttore(tmpD);
	cout<<"Inserto -> ";
	is>>tmpI;
	if(strcasecmp(tmpI,"True")==0){ 
	Q.set_Inserto(true);
	}
	else{
	 Q.set_Inserto(false);
	 }
	return is;}
	
	Quotidiano::Quotidiano(const float C,const char*T, const bool P,const char* D,const bool I):Giornale(C,T,P){
	Direttore=new char[strlen(D)+1];
	strcpy(Direttore,D);
	Inserto=I;
	}
	Quotidiano::Quotidiano(const Quotidiano&Q){
	Direttore=new char[strlen(Q.Direttore)+1];
	strcpy(Direttore,Q.Direttore);
	Inserto=Q.Inserto;}
	Quotidiano & Quotidiano::operator=(const Quotidiano&Q){
	if(this!=&Q){
	Giornale::operator=(Q);
	Direttore=new char[strlen(Q.Direttore)+1];
	strcpy(Direttore,Q.Direttore);
	Inserto=Q.Inserto;}
	return *this;
	}
	
	const char* Quotidiano::get_Direttore()const{
	return Direttore;
	}
	const bool Quotidiano::get_Inserto()const{
	return Inserto;
	}
	
	void Quotidiano::set_Direttore(const char*D){
	if(Direttore) delete[]Direttore;
	Direttore=new char[strlen(D)+1];
	strcpy(Direttore,D);
	}
	void Quotidiano::set_Inserto(const bool I){
	Inserto=I;
	}
	
	ostream & Quotidiano::stampa_Dati(ostream &os)const{
	os << "\n Direttore: " << Direttore;
	if(get_Inserto()) os << "\n Inserto";
    else os << "\n No Inserto";
    return os;
	}
	ofstream & Quotidiano::memorizza_Dati(ofstream &ofs)const{
	 Giornale::memorizza_Dati(ofs);
	ofs<<get_Direttore()<<" "<<get_Inserto();
	return ofs;
	}

