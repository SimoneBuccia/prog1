#include "Lettera.h"

Lettera::Lettera(const int c,const char * a,const char * f,const int n, const char * m, const char * d) : Manoscritto(c,a,f,n) {
	Mit = new char[strlen(m)+1];
	strcpy(Mit,m);
	Des = new char[strlen(d)+1];
	strcpy(Des, d);
}

Lettera::Lettera(const Lettera & l) : Manoscritto(l) {
	Mit = new char[strlen(l.Mit)+1];
	strcpy(Mit,l.Mit);
	Des = new char[strlen(l.Des)+1];
	strcpy(Des, l.Des);
}

const Lettera & Lettera::operator=(const Lettera & l) {
	if(this!=&l) {
		Manoscritto::operator=(l);
		if(Mit) delete [] Mit;
		Mit = new char[strlen(l.Mit)+1];
		strcpy(Mit,l.Mit);
		if(Des) delete [] Des;
		Des = new char[strlen(l.Des)+1];
		strcpy(Des, l.Des);
	}
	return *this;
}

Lettera::~Lettera() {
	delete [] Mit;
	delete [] Des;
}

const char * Lettera::getMit() const {
	return Mit;
}

const char * Lettera::getDes() const {
	return Des;
}

	
void Lettera::setMit(const char * m) {
	if(Mit) delete [] Mit;
	Mit = new char[strlen(m)+1];
	strcpy(Mit, m);
}

void Lettera::setDes(const char * d) {
	if(Des) delete [] Des;
	Des = new char[strlen(d)+1];
	strcpy(Des, d);
}

ostream & operator<<(ostream & out, const Lettera & l) {
	return l.visualizzaDati(out);
}

istream & operator>>(istream & in, Lettera & l) {
	char tempM[100], tempD[100];
	in >> (Manoscritto&)l >> tempM >> tempD;
	l.setMit(tempM);
	l.setDes(tempD);
	return in;
}

void Lettera::memorizzaDati(ostream & ofs) const {
	ofs << *this << ' ';
}

ostream & Lettera::visualizzaDati(ostream & out) const {
	Manoscritto::visualizzaDati(out);
	out << ' ' << this->getMit() << ' ' << this->getDes();
	return out;
}
