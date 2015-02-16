#include "Fotografia.h"
	
	

	Fotografia::Fotografia(const char*I,const char* T,const char*A, const char*t,const int a,const char* S,const char* F) : Libro(I,T,A,t,a){
	Soggetto=new char[strlen(S)+1];
	strcpy(Soggetto,S);
	Formato=new char[strlen(F)+1];
	strcpy(Formato,F);
	}
	Fotografia::Fotografia(const Fotografia& F):Libro(F){
	Soggetto=new char[strlen(F.Soggetto)+1];
	strcpy(Soggetto,F.Soggetto);
	Formato=new char[strlen(F.Formato)+1];
	strcpy(Formato,F.Formato);

	}
	Fotografia & Fotografia::operator=(const Fotografia& F){
	if(this!=&F){
	Libro::operator=(F);
	if(Soggetto) delete[]Soggetto;
	Soggetto=new char[strlen(F.Soggetto)+1];
	strcpy(Soggetto,F.Soggetto);
	if(Formato) delete[]Formato;
	Formato=new char[strlen(F.Formato)+1];
	strcpy(Formato,F.Formato);
	}
	return *this;
	}
	
	const char* Fotografia::get_Soggetto() const{
	return Soggetto;}
	const char* Fotografia::get_Formato() const{
	return Formato;}

	
	void Fotografia::set_Soggetto(const char*S){
	if(Soggetto) delete[] Soggetto;
	Soggetto=new char[strlen(S)+1];
	strcpy(Soggetto,S);}
	void Fotografia::set_Formato(const char*F){
	if(Formato) delete[]Formato;
	Formato=new char[strlen(F)+1];
	strcpy(Formato,F);
	}
	
	
	ostream & operator<<(ostream & os, const Fotografia&F){
	os<<(Libro&)F<<" "<<F.get_Soggetto()<<" "<<F.get_Formato();
	return os;
	}
	istream & operator>>(istream & is, Fotografia& F){
	char tmp[100];
	cout<<"Soggetto: ";
	is.getline(tmp,100);
	F.set_Soggetto(tmp);
	is.ignore();
	cout<<"Formato: ";
	is.getline(tmp,100);
	F.set_Formato(tmp);
	return is;
	}
