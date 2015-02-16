#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Complex {
	friend Complex operator+(const Complex &, const Complex &);
	friend Complex operator*(const Complex &, const Complex &);
	friend ostream& operator<<(ostream&, const Complex &);
	friend istream& operator>>(istream&, Complex &);
	
	private:
		double Re;
		double Imm;
	public:
		Complex(const double r=0, const double i=0);
		Complex(const Complex & c) {
			this->Re = c.Re;
			this->Imm = c.Imm;
		}
		double modComplex();
};
