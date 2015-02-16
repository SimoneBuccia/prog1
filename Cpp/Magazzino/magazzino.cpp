#include "magazzino.h"

void inserisciDati(Prodotto & P) { 
	char temp[100];
	cout << "Inserisci Quantita': ";
	cin >> P.Qta;
	cin.ignore();
	cout << "Inserisci Codice: ";
	cin.getline(temp, 100);
	P.Codice = new char[strlen(temp)+1];
	strcpy(P.Codice, temp);
	strcpy(temp, "");
	cout << "Inserisci Descrizione: ";
	cin.getline(temp, 100);
	P.Descrizione = new char[strlen(temp)+1];
	strcpy(P.Descrizione, temp);
}

void modificaCodice(Prodotto & P) {
	if(P.Codice) delete [] P.Codice;
	char temp[100];

	cout << "Inserisci Codice: ";
	cin.getline(temp, 100);
	P.Codice = new char[strlen(temp)+1];
	strcpy(P.Codice, temp);
}

const char * fornisciCodice(const Prodotto & P) {
	return P.Codice;
}

void visualizzaDati(const Prodotto & P) {
	cout<<P.Codice<<" - "<<P.Descrizione<<" - "<<P.Qta;
}
