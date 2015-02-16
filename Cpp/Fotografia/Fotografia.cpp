#include "Fotografia.h"

Fotografia::Fotografia(const char * p, const char * f, const int c, const char * s) : Immagine(p,f) {
	Chiave = c;
	Soggetto = new char[strlen(s)+1];
	strcpy(Soggetto, s);
}

Fotografia::Fotografia(const Fotografia & f) : Immagine(f) {
	Chiave = f.Chiave;
	if(Soggetto) delete [] Soggetto;
	Soggetto = new char[strlen(f.Soggetto)+1];
	strcpy(Soggetto, f.Soggetto);
}

int Fotografia::getChiave() const {
	return Chiave;
}

void Fotografia::setChiave(const int c) {
	Chiave = c;
}

const char * Fotografia::getSoggetto() const {
	return Soggetto;
}

void Fotografia::setSoggetto(const char * s) {
	if(Soggetto) delete [] Soggetto;
	Soggetto = new char[strlen(s)+1];
	strcpy(Soggetto, s);
}

const Fotografia & Fotografia::operator=(const Fotografia & f) {
	if(this != & f) {
		Immagine::operator=(f);	
		if(Soggetto) delete [] Soggetto;
		Soggetto = new char[strlen(f.Soggetto)+1];
		strcpy(Soggetto, f.Soggetto);
		Chiave = f.Chiave;
	}
	return *this;
}

void Fotografia::print() const {
	Immagine::print();
	cout << " - Chiave: " << Chiave << " - Soggetto: " << Soggetto;
}

ostream & operator<<(ostream & out, const Fotografia & f) {
	out << (Immagine &)f << ' ' << f.getChiave() << ' ' << f.getSoggetto();
}

istream & operator>>(istream & in, Fotografia & f) {
	char tempS[100];
	in >> (Immagine &)f >> f.Chiave >> tempS;
	f.setSoggetto(tempS);
	return in;
}
	
