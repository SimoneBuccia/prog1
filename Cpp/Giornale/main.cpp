#include "Pila.h"

int main(int argc, char** argv) {
	Giornale G1(12.50, "Titolo1", false);
	Giornale G2(1.50, "Titolo2", true);
	Giornale G3(2.00, "Titolo3", false);
	Rivista R4(22.70, "Titolo4", false, "Editore4", "Periodo4");
	Rivista R5(11.50, "Titolo5", true, "Editore5", "Periodo5");
	Rivista R6(6.00, "Titolo6", false,  "Editore6", "Periodo6");
	Quotidiano Q7(6.35, "Titolo7", false, "Direttore7", true);
	Quotidiano Q8(9.99, "Titolo8", true, "Direttore8", false);
	Quotidiano Q9(5, "Titolo9", false, "Direttore9", true);
	
	cout<<"Polimorfismo:\n";
	Giornale * vett[9];
	vett[0] = &G1;
	vett[1] = &G2;
	vett[2] = &G3;
	vett[3] = &R4;
	vett[4] = &R5;
	vett[5] = &R6;
	vett[6] = &Q7;
	vett[7] = &Q8;
	vett[8] = &Q9;
	
	for(int i=0; i<9; i++) {
		cout << *vett[i] << "\n\n";
	}
	
	cout<<"\n\nPila:\n";
	Pila P;
	for(int i=0; i<9; i++) {
		P.push(vett[i]);
	}
	cout<<P;
	
	ofstream file;
	file.open("./test.txt", ios::out);
	if(!file) {
		cout<<"Errore apertura file.";
	} else {
		file << P;
	}
	file.close();
	
	Rivista R10(1.00, "Titolo10", false,  "Editore10", "Periodo10");
	Quotidiano Q11(1.35, "Titolo11", false, "Direttore11", true);
	
	P.push(&R10);
	
	cout<<"\n\nEccezione:\n";
	try {
		P.push(&Q11);
	} catch(SpaceOverflow e) {
		cout<<e.errorLog();
	}
	return 0;
}
