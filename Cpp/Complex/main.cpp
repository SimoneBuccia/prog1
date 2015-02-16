#include "Complex.h"



int main(int argc, char** argv) {
	Complex c;
    Complex c1(3,4);
    Complex c3=c1;
    Complex c4;
    Complex c5;
    
    cin >> c;
    cout << "Stampo c: " << endl << c;
    cout << "\n";
    cout << "Stampo c1: " << endl << c1;
    cout << "\n";
    cout << "Stampo c3: " << endl << c3;
    c4=c1+c;
    cout << "\n";
    cout << "Stampo la somma c1+c: " << endl << c4;
    c5=c3*c;
    cout << "\n";
    cout << "Stampo il prodotto c3*c: " << endl << c5;
}
