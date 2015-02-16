#include "BranoMusicale.h"

Brano::Brano(const char * u, int k, const char * f, const char * b, const char * i, int d) : File(u, k, f) {
	Br = new char[strlen(b)+1];
	strcpy(Br, b);
	In = new char[strlen(i)+1];
	strcpy(In, i);
	Du = d;
}

Brano::Brano(const Brano & b) : File(b) {
	Br = new char[strlen(b.Br)+1];
	strcpy(Br, b.Br);
	In = new char[strlen(b.In)+1];
	strcpy(In, b.In);
	Du = b.Du;
}

Brano::~Brano() {
	delete [] Br;
	delete [] In;
}

const Brano & Brano::operator=(const Brano & b) {
	if(this!=&b) {
		File::operator=(b);
		if(Br) delete [] Br;
		Br = new char[strlen(b.Br)+1];
		strcpy(Br, b.Br);
		if(In) delete [] In;
		In = new char[strlen(b.In)+1];
		strcpy(In, b.In);
		Du = b.Du;
	}
	return *this;
}

const char * Brano::getBr() const {
	return Br;
}

void Brano::setBr(const char * b) {
	if(Br) delete [] Br;
	Br = new char[strlen(b)+1];
	strcpy(Br, b);
}

const char * Brano::getIn() const {
	return In;
}

void Brano::setIn(const char * i) {
	if(In) delete [] In;
	In = new char[strlen(i)+1];
	strcpy(In, i);
}

const int Brano::getDu() const {
	return Du;
}

void Brano::setDu(const int d) {
	Du = d;
}

ostream & operator<<(ostream & out, const Brano & b) {
	out << (File&)b <<b.getBr() << ' ' << b.getIn() << ' ' << b.getDu() << ' ';
	return out;
}

istream & operator>>(istream & in, Brano & b) {
	char tempB[100], tempI[100];
	in >> (File&)b >> tempB >> tempI >> b.Du;
	b.setBr(tempB);
	b.setIn(tempI);
	return in;
}

void Brano::stampa() const {
	cout<<*this;
}

void Brano::memorizza(ostream & ofs) const {
	ofs << *this;
}
