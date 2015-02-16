	#include "Rivista.h"
	
	ostream & operator<<(ostream &os, const Rivista&R){
	return R.stampa_Dati(os);
	}
	ofstream & operator<<(ofstream &ofs, const Rivista&R){
	return R.memorizza_Dati(ofs);
	}
	istream & operator>>(istream &is,Rivista&R){
	char tmpE[100],tmpP[100];
	cout<<"Periodo -> ";
	is>>tmpP;
	R.set_Periodo(tmpP);
	cout<<"Editore -> ";
	is>>tmpE;
	R.set_Editore(tmpE);
	return is;
	}
	
	Rivista::Rivista(const float C,const char*T, const bool P,const char*E,const char*PE):Giornale(C,T,P){
	Editore=new char[strlen(E)+1];
	strcpy(Editore,E);
	Periodo=new char[strlen(PE)+1];
	strcpy(Periodo,PE);
	}
	Rivista::Rivista(const Rivista&R):Giornale(R){
	Editore=new char[strlen(R.Editore)+1];
	strcpy(Editore,R.Editore);
	Periodo=new char[strlen(R.Periodo)+1];
	strcpy(Periodo,R.Periodo);}
	Rivista & Rivista::operator=(const Rivista&R){
	if(this!=&R){
	Giornale::operator=(R);
	Editore=new char[strlen(R.Editore)+1];
	strcpy(Editore,R.Editore);
	Periodo=new char[strlen(R.Periodo)+1];
	strcpy(Periodo,R.Periodo);}
	return *this;
	}
	
	
	const char* Rivista::get_Periodo()const{
	return Periodo;
	}
	const char* Rivista::get_Editore()const{
	return Editore;
	}
	
	void Rivista::set_Periodo(const char*P){
	Periodo=new char[strlen(P)+1];
	strcpy(Periodo,P);
	
	}
	void Rivista::set_Editore(const char*E){
	Editore=new char[strlen(E)+1];
	strcpy(Editore,E);
	}
	
	ostream & Rivista::stampa_Dati(ostream &os)const{
	os << "\n Periodo: " << Periodo;
	os<< "\n Editore: " << Editore;
	}
	 ofstream & Rivista::memorizza_Dati(ofstream &os)const{
	 Giornale::memorizza_Dati(os);
	os<<get_Periodo()<<" "<<get_Editore();
	return os;}
