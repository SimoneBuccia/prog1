#include "Operaio.h"


ostream & operator<<(ostream & os, const Operaio & O) {
	os << (Lavoratore&)O << " " << O.getSettore() << " " << O.getOreMese();
	return os;
}

istream & operator>>(istream & in, Operaio & O) {
	in >> (Lavoratore&)O;
	char temp[100];
	in.ignore();
	cout << "Inserisci Settore: ";
	in.getline(temp, 100);
	O.setSettore(temp);
	cout << "Inserisci Ore Mese: ";
	in >> O.OreMese;
	return in;
}

Operaio::Operaio(const char * Ma, const char * Az, const int An, const float Sb, const char * Se, const int Or) : Lavoratore(Ma, Az, An, Sb) {
	Settore = new char[strlen(Se)+1];
	strcpy(Settore, Se);
	OreMese = Or;
}

Operaio::Operaio(const Operaio & O) : Lavoratore(O) {
	if(Settore) delete [] Settore;
	Settore = new char[strlen(O.Settore)+1];
	strcpy(Settore, O.Settore);
	OreMese = O.OreMese;
}

const Operaio & Operaio::operator=(const Operaio & O) {
	if(this!=&O) {
		Lavoratore::operator=(O);
		if(Settore) delete [] Settore;
		Settore = new char[strlen(O.Settore)+1];
		strcpy(Settore, O.Settore);
		OreMese = O.OreMese;
	}
	return *this;
}

const char * Operaio::getSettore() const {
	return Settore;
}

void Operaio::setSettore(const char * Se) {
	if(Settore) delete [] Settore;
	Settore = new char[strlen(Se)+1];
	strcpy(Settore, Se);
}

int Operaio::getOreMese() const {
	return OreMese;
}

void Operaio::setOreMese(const int Or) {
	OreMese = Or;
}

float Operaio::calcolaStipendio() const {
	return Lavoratore::calcolaStipendio() * OreMese;
}
