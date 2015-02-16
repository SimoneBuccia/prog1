#include "Pratica.h"

Pratica::Pratica(const char * codice, const char * tipo) {
	Codice = new char[strlen(codice)+1];
	strcpy(Codice, codice);
	Tipo = new char[strlen(tipo)+1];
	strcpy(Tipo, tipo);
}

Pratica::Pratica(const Pratica & p) {
	if(strcmp(Codice, p.Codice)!=0) {
		delete [] Codice;
		Codice = new char[strlen(p.Codice)+1];
		strcpy(Codice, p.Codice);
	}
	if(strcmp(Tipo, p.Tipo)!=0) {
		delete [] Tipo;
		Tipo = new char[strlen(p.Tipo)+1];
		strcpy(Tipo, p.Tipo);
	}
}
		
void Pratica::setCodice(const char * codice) {
	Codice = new char[strlen(codice)+1];
	strcpy(Codice, codice);
};

void Pratica::setTipo(const char * tipo) {
	Tipo = new char[strlen(tipo)+1];
	strcpy(Tipo, tipo);
}

bool Pratica::operator==(const Pratica & p) const {
	return (strcmp(Codice, p.Codice)==0 && strcmp(Tipo, p.Tipo)==0 );
}

/* FRIEND */
ostream & operator<<(ostream & os, const Pratica & p) {
	os<<"\nCodice: "<<p.getCodice()<<endl;
	os<<"Tipo: "<<p.getTipo()<<endl;
	return os;
}

istream & operator>>(istream & in, Pratica & p) {
	char temp[100];
	cout << "\nInserisci il codice: ";
	in.ignore();
	in.getline(temp, 100);
	p.setCodice(temp);
	strcpy(temp, "");
	cout << "\nInserisci il tipo: ";
	in.getline(temp, 100);
	p.setTipo(temp);
	
}
