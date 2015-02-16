#include "Pila.h"

int main(int argc, char** argv) {
	Pacco P1(0, 1.1, "aaa"),
		P2(1,1.1,"bbb"),
		P3(2, 1.1, "ccc"),
		P4=P1,
		P5=P1;
	
	P5=P2;
	
	cout << P1 << '\n' << P2 << '\n' << P3 << '\n' << P4 << '\n' << P5 << "\n\n\n";
	
	Pila Pila1, Pila2;
	Pila1.push(P1);
	Pila1.push(P2);
	Pila1.push(P3);
	Pila1.push(P4);
	Pila1.push(P5);
	
	Pila1.stampa();
	cout << "\n\n\n";
	
	
	ofstream file;
	file.open("./test.bin", ios::binary|ios::out);
	
	if(!file) {
		cout << "Errore apertura.";
	} else {
		Pila1.salvaFile(file);
	}
	file.close();
	
	ifstream file2;
	file2.open("./test.bin", ios::binary|ios::in);
	
	if(!file2) {
		cout << "Errore apertura.";
	} else {
		
		Pila2.leggiFile(file2);
	}
	file2.close();
	
	Pila2.stampa();
	
	Pila Pila3;
	cout << "\n\n\n";
	
	try {
		ifstream file3;
		file3.open("./test2.bin", ios::binary|ios::in);
		
		Pila3.leggiFile(file3);
		
		file3.close();
	} catch(Ecc e) {
		cout << e.what();
	}
	
	return 0;
}
