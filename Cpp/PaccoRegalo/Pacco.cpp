#include "Pacco.h"
Pacco::Pacco(const char * d, float p, const char * f) {
	Destinatario = new char[strlen(d)+1];
	strcpy(Destinatario, d);
	Peso = p;
	Forma = new char[strlen(f)+1];
	strcpy(Forma, f);
}

Pacco::Pacco(const Pacco & p) {
	Destinatario = new char[strlen(p.Destinatario)+1];
	strcpy(Destinatario, p.Destinatario);
	Peso = p.Peso;
	Forma = new char[strlen(p.Forma)+1];
	strcpy(Forma, p.Forma);
}

Pacco::~Pacco() {
	delete [] Destinatario;
	delete [] Forma;
}

const Pacco & Pacco::operator=(const Pacco & p) {
	if(this!=&p) {
		if(Destinatario) delete [] Destinatario;
		Destinatario = new char[strlen(p.Destinatario)+1];
		strcpy(Destinatario, p.Destinatario);
		Peso = p.Peso;
		if(Forma) delete [] Forma;
		Forma = new char[strlen(p.Forma)+1];
		strcpy(Forma, p.Forma);
	}
	return *this;
}
		
const char * Pacco::getDestinatario() const {
	return Destinatario;
}

void Pacco::setDestinatario(const char * d) {
	if(Destinatario) delete [] Destinatario;
	Destinatario = new char[strlen(d)+1];
	strcpy(Destinatario, d);
}

float Pacco::getPeso() const {
	return Peso;
}

void Pacco::setPeso(const float p) {
	Peso = p;
}

const char * Pacco::getForma() const {
	return Forma;
}

void Pacco::setForma(const char * f) {
	if(Forma) delete [] Forma;
	Forma = new char[strlen(f)+1];
	strcpy(Forma, f);
}

ostream & operator<<(ostream & out, const Pacco & p) {
	out << p.Destinatario << ' ' << p.Peso << ' ' << p.Forma;
	return out;
}

istream & operator>>(istream & in, Pacco & p) {
	char tempD[100], tempF[100];
	in >> tempD >> p.Peso >> tempF;
	p.setDestinatario(tempD);
	p.setForma(tempF);
	return in;
}
			
