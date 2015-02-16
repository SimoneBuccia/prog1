#include "Video.h"

Video::Video(const char * u, int k, const char * f, const char * a, const char * s, const char * d) : File(u, k, f) {
	Au = new char[strlen(a)+1];
	strcpy(Au, a);
	So = new char[strlen(s)+1];
	strcpy(So, s);
	Da = new char[strlen(d)+1];
	strcpy(Da, d);
}

Video::Video(const Video & v) : File(v) {
	Au = new char[strlen(v.Au)+1];
	strcpy(Au, v.Au);
	So = new char[strlen(v.So)+1];
	strcpy(So, v.So);
	Da = new char[strlen(v.Da)+1];
	strcpy(Da, v.Da);
}

Video::~Video() {
	delete [] Au;
	delete [] So;
	delete [] Da;
}

const Video & Video::operator=(const Video & v) {
	if(this!=&v) {
		File::operator=(v);
		if(Au) delete [] Au;
		Au = new char[strlen(v.Au)+1];
		strcpy(Au, v.Au);
		if(So) delete [] So;
		So = new char[strlen(v.So)+1];
		strcpy(So, v.So);
		if(Da) delete [] Da;
		Da = new char[strlen(v.Da)+1];
		strcpy(Da, v.Da);
	}
	return *this;
}

const char * Video::getAu() const {
	return Au;
}

void Video::setAu(const char * a) {
	if(Au) delete [] Au;
	Au = new char[strlen(a)+1];
	strcpy(Au, a);
}

const char * Video::getSo() const {
	return So;
}

void Video::setSo(const char * s) {
	if(So) delete [] So;
	So = new char[strlen(s)+1];
	strcpy(So, s);
}

const char * Video::getDa() const {
	return Da;
}

void Video::setDa(const char * d) {
	if(Da) delete [] Da;
	Da = new char[strlen(d)+1];
	strcpy(Da, d);
}
 
ostream & operator<<(ostream & out, const Video & v) {
	out << (File&)v << v.getAu() << ' ' << v.getSo() << ' ' << v.getDa() << ' ';
	return out;
}

istream & operator>>(istream & in, Video & v) {
	char tempA[100], tempS[100], tempD[100];
	in >> (File&)v >> tempA >> tempS >> tempD;
	v.setAu(tempA);
	v.setSo(tempS);
	v.setDa(tempD);
	return in;
}

void Video::stampa() const {
	cout<<*this;
}

void Video::memorizza(ostream & ofs) const {
	ofs << *this;
}
