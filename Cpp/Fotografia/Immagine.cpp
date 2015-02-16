#include "Immagine.h"

Immagine::Immagine(const char * p, const char * f) {
	Proprietario = new char[strlen(p)+1];
	strcpy(Proprietario, p);
	Formato = new char[strlen(f)+1];
	strcpy(Formato, f);
}

Immagine::Immagine(const Immagine & i) {
	if(Proprietario) delete [] Proprietario;
	Proprietario = new char[strlen(i.Proprietario)+1];
	strcpy(Proprietario, i.Proprietario);
	if(Formato) delete [] Formato;
	Formato = new char[strlen(i.Formato)+1];
	strcpy(Formato, i.Formato);
}

const Immagine & Immagine::operator=(const Immagine & i) {
	if(this!=&i) {
		if(Proprietario) delete [] Proprietario;
		Proprietario = new char[strlen(i.Proprietario)+1];
		strcpy(Proprietario, i.Proprietario);
		if(Formato) delete [] Formato;
		Formato = new char[strlen(i.Formato)+1];
		strcpy(Formato, i.Formato);
	}
	return *this;
}


const char * Immagine::getProprietario() const {
	return Proprietario;
}

void Immagine::setProprietario(const char * p) {
	if(Proprietario) delete [] Proprietario;
	Proprietario = new char[strlen(p)+1];
	strcpy(Proprietario, p);
}

const char * Immagine::getFormato() const {
	return Formato;
}

void Immagine::setFormato(const char * f) {
	if(Formato) delete [] Formato;
	Formato = new char[strlen(f)+1];
	strcpy(Formato, f);
}
		
void Immagine::print() const {
	cout << "Proprietario: " << Proprietario << " - Formato: "<<Formato;
}	

ostream & operator<<(ostream & out, const Immagine & i) {
	out <<  i.getProprietario() << ' ' << i.getFormato();
	return out;
}

istream & operator>>(istream & in, Immagine & i) {
	char tempP[100], tempF[100];
	in>>tempP>>tempF;
	i.setProprietario(tempP);
	i.setFormato(tempF);
	return in;
}
		
