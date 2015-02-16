#include "Gettone.h"

ostream & operator<<(ostream & out, const Gettone & g) {
	out << g.getMat() << ' ' << g.getVal() << ' ';
	return out;	
}

istream & operator>>(istream & in, Gettone & g) {
	char temp[100];
	cout << "Materiale -> ";
	in.getline(temp, 100);
	g.setMat(temp);
	cout << "Valore -> ";
	in >> g.Val;
	in.ignore();
	return in;
}
	
Gettone::Gettone(const char * m, const int v) {
	Mat = new char[strlen(m)+1];
	strcpy(Mat, m);
	Val = v;
}

Gettone::Gettone(const Gettone & g) {
	Mat = new char[strlen(g.Mat)+1];
	strcpy(Mat, g.Mat);
	Val = g.Val;
}

const Gettone & Gettone::operator=(const Gettone & g) {
	if(this!=&g) {
		if(Mat) delete Mat;
		Mat = new char[strlen(g.Mat)+1];
		strcpy(Mat, g.Mat);
		Val = g.Val;
	}
	return *this;
}

Gettone::~Gettone() {
	if(Mat) delete Mat;
}
		
const char * Gettone::getMat() const {
	return Mat;
}

void Gettone::setMat(const char * m) {
	if(Mat) delete Mat;
	Mat = new char[strlen(m)+1];
	strcpy(Mat, m);
}

const int Gettone::getVal() const {
	return Val;
}

void Gettone::setVal(const int v) {
	Val = v;
}

void Gettone::print() const {
	cout << *this;
}
