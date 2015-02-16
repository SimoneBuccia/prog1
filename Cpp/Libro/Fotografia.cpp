#include "Fotografia.h"

Fotografia::Fotografia(const char * i, const char * ti, const char * au, const char * t, const int an, const char * s, const char * f) : Libro(i,ti,au,t,an) {
	soggetto = new char[strlen(s)+1];
	strcpy(soggetto, s);
	formato = new char[strlen(f)+1];
	strcpy(formato, f);
}

Fotografia::Fotografia(const Fotografia & f) : Libro(f) {
	soggetto = new char[strlen(f.soggetto)+1];
	strcpy(soggetto, f.soggetto);
	formato = new char[strlen(f.formato)+1];
	strcpy(formato, f.formato);
}

const Fotografia & Fotografia::operator=(const Fotografia & f) {
	if(this!=&f) {
		Libro::operator=(f);
		if(soggetto) delete [] soggetto;
		soggetto = new char[strlen(f.soggetto)+1];
		strcpy(soggetto, f.soggetto);
		if(formato) delete [] formato;
		formato = new char[strlen(f.formato)+1];
		strcpy(formato, f.formato);
	}
	return *this;
}
	
const char * Fotografia::getSoggetto() const {
	return soggetto;
}

void Fotografia::setSoggetto(const char * s) {
	if(soggetto) delete [] soggetto;
	soggetto = new char[strlen(s)+1];
	strcpy(soggetto, s);
}

const char * Fotografia::getFormato() const {
	return formato;
}
void Fotografia::setFormato(const char * f) {
	if(formato) delete [] formato;
	formato = new char[strlen(f)+1];
	strcpy(formato, f);
}

ostream & operator<<(ostream & out, const Fotografia & f) {
	out << (Libro&)f << ' ' << f.getSoggetto() <<' '<< f.getFormato();
	return out;
}

istream & operator>>(istream & in, Fotografia &f) {
	in >> (Libro&)f;
	char temp[100];
	cout<<"Soggetto -> ";
	in.getline(temp,100);
	f.setSoggetto(temp);
	cout<<"Formato -> ";
	in.getline(temp,100);
	f.setFormato(temp);
	return in;
}
