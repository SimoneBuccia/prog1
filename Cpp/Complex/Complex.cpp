#include "Complex.h"

Complex operator+(const Complex & c1, const Complex & c2) {
	Complex sum;
	sum.Re = c1.Re+c2.Re;
	sum.Imm = c1.Imm+c2.Imm;
	return sum;
}

Complex operator*(const Complex & c1, const Complex & c2){
	Complex prod;
	prod.Re = (c1.Re*c2.Re)-(c1.Imm*c2.Imm);
	prod.Imm = (c1.Re*c2.Imm)-(c1.Imm*c2.Re);
	return prod;
}

ostream& operator<<(ostream& os, const Complex & c){
	os<<c.Re<<" "<<" "<<c.Imm<<"j";
	return os;
}

istream& operator>>(istream& in, Complex & c){
	cout << "Inserisci il coefficiente reale:\n";
	in >> c.Re;
	cout << "Inserisci il coefficiente immaginario:\n";
	in >> c.Imm;
	return in;
}

double Complex::modComplex() {
	return sqrt(pow(this->Re,2)+pow(this->Imm,2));
}
