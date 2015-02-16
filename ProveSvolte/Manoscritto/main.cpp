#include "Lettera.h"
#include "Elenco.h"


int main(int argc, char** argv) {
	Manoscritto M1(0, "aaa", "aaa", 10),
				M2(1, "bbb", "bbb", 10),
				M3(3, "bbb", "bbb", 10);
	Lettera L1(4, "aaa", "aaa", 10, "aaa", "aaa"),
			L2(5, "bbb", "bbb", 10, "bbb", "bbb"),
			L3=L1;
			
			
	cout <<"Stampa normale:\n";		
	cout << M1 <<'\n'<< M2 <<'\n' << M3 <<"\n\n";
	cout << L1 <<'\n'<< L2 <<'\n' << L3 ;
		
		
	cout <<"\n\nStampa polimorfismo:\n";
	Manoscritto * v[2];
	v[0] = &M1;
	v[1] = &L2;
	
	for(int i=0; i<2; i++) {
		v[i] -> visualizzaDati();
		cout<<'\n';
	}
	
	cout <<"\n\nElenco:\n";
	Elenco E1, E2;
	
	E1.push(&M1);
	E1.push(&M2);
	E1.push(&L1);
	E1.push(&L2);
	E1.push(&M3);
	E1.pop(0); 
	E1.stampa();
	
	ofstream file;
	file.open("./test.txt", ios::out);
	if(!file) {
		cout << "Errore file";
	} else {
		E1.memorizzaDati(file);
	}
	file.close();
	
	cout <<"\n\nEccezione:\n";
	try {
		E2.push(&M1);
		E2.push(&M1);
	} catch (Duplicato e) {
		cout << e.what() << endl;
	}
	
	
	
	
}
