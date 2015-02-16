#include "Giornale.h"

	ostream & operator<<(ostream &os, const Giornale&G){
	return G.stampa_Dati(os);
	}
	ofstream & operator<<(ofstream &os, const Giornale&G){
	return G.memorizza_Dati(os);
	}
	istream & operator>>(istream &is,Giornale&G){
	char tmpT[100],tmpP[100];
	cout<<"Costo -> ";
	is>>G.Costo;
	cout<<"Titolo -> ";
	is>>tmpT;
	G.set_Titolo(tmpT);
	cout<<"Periodico -> ";
	is>>tmpP;
	if(strcasecmp(tmpP,"True")==0){ 
	G.set_Periodico(true);
	}
	else{
	 G.set_Periodico(false);
	 }
	 
	
	return is;
	
	}

	Giornale::Giornale(const float C,const char*T, const bool P){
	Costo=C;
	Titolo=new char[strlen(T)+1];
	strcpy(Titolo,T);
	Periodico=P;
	}
	Giornale::Giornale(const Giornale&G){
	Costo=G.Costo;
	Titolo=new char[strlen(G.Titolo)+1];
	strcpy(Titolo,G.Titolo);
	Periodico=G.Periodico;
	}
	Giornale & Giornale::operator=(const Giornale&G){
	if(this!=&G){
	Costo=G.Costo;
	Titolo=new char[strlen(G.Titolo)+1];
	strcpy(Titolo,G.Titolo);
	Periodico=G.Periodico;}
	return *this;
	}

	const float Giornale::get_Costo()const{
	return Costo;
	}
	const char* Giornale::get_Titolo()const{
	return Titolo;
	}
	const bool Giornale::get_Periodico()const{
	return Periodico;
	}

	void Giornale::set_Costo(const float C){
	Costo=C;
	}
	void Giornale::set_Titolo(const char* T){
	if(Titolo) delete[]Titolo;
	Titolo=new char[strlen(T)+1];
	strcpy(Titolo,T);
	}
	void Giornale::set_Periodico(const bool P){
	Periodico=P;
	}

	ostream & Giornale::stampa_Dati(ostream &out)const{
    out << "\n Titolo: " << Titolo;
    out << "\n Prezzo: " << Costo;
    if(get_Periodico()) out << "\n Periodico";
    else out << "\n Non Periodico";
    return out;
	}
	ofstream & Giornale::memorizza_Dati(ofstream &os)const{
	os<<get_Titolo()<<" "<<get_Costo()<<" "<<get_Periodico();
	return os;
	}
