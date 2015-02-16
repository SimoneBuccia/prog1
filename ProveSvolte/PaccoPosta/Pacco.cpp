#include "Pacco.h"

Pacco::Pacco(const int c, const float p, const char * i) {
	Codice = c;
	Peso = p;
	Indirizzo = new char[strlen(i)+1];
	strcpy(Indirizzo, i);
}

Pacco::Pacco(const Pacco & p) {
	Codice = p.Codice;
	Peso = p.Peso;
	Indirizzo = new char[strlen(p.Indirizzo)+1];
	strcpy(Indirizzo, p.Indirizzo);
}

const Pacco & Pacco::operator=(const Pacco & p) {
	if(this!=&p) {
		Codice = p.Codice;
		Peso = p.Peso;
		if(Indirizzo) delete Indirizzo;
		Indirizzo = new char[strlen(p.Indirizzo)+1];
		strcpy(Indirizzo, p.Indirizzo);
	}
	return *this;
}

Pacco::~Pacco() {
	delete [] Indirizzo;
}

const int Pacco::getCodice() const {
	return Codice;
}

void Pacco::setCodice(const int c) {
	Codice = c;
}

const float Pacco::getPeso() const {
	return Peso;
}

void Pacco::setPeso(const float p){
	Peso = p;
}

const char * Pacco::getIndirizzo() const {
	return Indirizzo;
}

void Pacco::setIndirizzo(const char * i) {
	if(Indirizzo) delete Indirizzo;
	Indirizzo = new char[strlen(i)+1];
	strcpy(Indirizzo, i);
}

ostream & operator<<(ostream & out, const Pacco & p) {
	out << p.getCodice() << ' ' << p.getPeso() << ' ' << p.getIndirizzo();
	return out;
}

istream & operator>>(istream & in, Pacco & p) {
	char temp[100];
	in>>p.Codice>>p.Peso;
	in.getline(temp, 100);
	p.setIndirizzo(temp);
	return in;
}

ofstream & operator<<(ofstream & ofs, const Pacco & p) {
	int size = strlen(p.getIndirizzo());
	int codice = p.getCodice();
	float peso = p.getPeso();
	ofs.write((const char *)(&codice), sizeof(int));
	ofs.write((const char *)(&peso), sizeof(float));
	ofs.write((const char *)(&size), sizeof(int));
	ofs.write(p.getIndirizzo(), size*sizeof(char));
	return ofs;
}

ifstream & operator>>(ifstream & ifs, Pacco & p) {
	int codice;
	float peso;
	int size;
	char bufferI[100];
	ifs.read((char *)(&codice), sizeof(int));
	ifs.read((char *)(&peso), sizeof(int));
	ifs.read((char *)(&size), sizeof(int));
	ifs.read(bufferI, size*sizeof(char));
	bufferI[size] = '\0';
	p.setCodice(codice);
	p.setPeso(peso);
	p.setIndirizzo(bufferI);
	return ifs;
}
