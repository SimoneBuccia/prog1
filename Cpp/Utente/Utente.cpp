#include "Utente.h"

Utente::Utente(const char * n, const char * c) {
	Nome = new char[strlen(n)+1];
	strcpy(Nome, n);
	Cognome = new char[strlen(c)+1];
	strcpy(Cognome, c);
}

Utente::Utente(const Utente & u) {
	if(Nome) delete [] Nome;
	if(Cognome) delete [] Cognome;
	
	Nome = new char[strlen(u.Nome)+1];
	strcpy(Nome,u.Nome);
	Cognome = new char[strlen(u.Cognome)+1];
	strcpy(Cognome, u.Cognome);
}

Utente::~Utente() {
	delete [] Nome;
	delete [] Cognome;
}

const char * Utente::getNome() const {
	return Nome;
}

const char * Utente::getCognome() const {
	return Cognome;
}

void Utente::setNome(const char * n) {
	if(Nome) delete [] Nome;
	
	Nome = new char[strlen(n)+1];
	strcpy(Nome,n);
}

void Utente::setCognome(const char * c) {
	if(Cognome) delete [] Cognome;
	Cognome = new char[strlen(c)+1];
	strcpy(Cognome, c);
}

