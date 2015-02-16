#include "Squadra.h"

const char * Squadra::getNome() const {
	return Nome;
}

int Squadra::getPunti() const {
	return Punti;
}

void Squadra::setPunti (const int P) {
	Punti = P;
}

void Squadra::setNome (const char * N) {
	if(Nome) delete [] Nome;
	Nome = new char[strlen(N)+1];
	strcpy(Nome, N);
}

void Squadra::modificaPunti(const int Pt) {
	Punti += Pt; 
}

ostream & operator<<(ostream & os, const Squadra & S) {
	os<<"La squadra "<<S.Nome<<" ha "<<S.Punti<<" punti.";
	return os;
}

istream & operator>>(istream & in, Squadra & S) {
	char temp[100];
	cout<<"Inserisci il nome della squadra: ";
	in.ignore();
	in.getline(temp, 100);
	cout<<"\nInserisci i punt della squadra: ";
	in>>S.Punti;
	S.setNome(temp);
	return in;
}

const Squadra & Squadra::operator=(const Squadra & S) {
	if(this!=&S) {
		this->setNome(S.Nome);
		this->setPunti(S.Punti);
	}
	return *this;
}

bool Squadra::operator==(const Squadra & S) const {
	return (strcmp(Nome, S.Nome)==0 && Punti == S.Punti);
}

bool Squadra::operator!=(const Squadra & S) const {
	return !(*this==S);
}

bool Squadra::operator>(const Squadra & S) const {
 	return (this->Punti > S.Punti);
}

bool Squadra::operator<(const Squadra & S) const {
 	return (this->Punti < S.Punti);
}

bool Squadra::operator>=(const Squadra & S) const {
	return !(*this<S);
}

bool Squadra::operator<=(const Squadra & S) const {
	return !(*this>S);
}

	
