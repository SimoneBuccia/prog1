#include "ElencoFreschi.h"

int main(int argc, char** argv) {
	Prodotto P1("aaa", "aaaa", 1, 100.0, "aaaaa"),
	P2("bbb", "bbbb", 5, 100.0, "bbbbb"),
	P3("ccc", "cccc", 12, 100.0, "ccccc"),
	P4=P3;
	
	P1.stampaDati();
	cout<<"\n";
	P2.stampaDati();
	cout<<"\n";
	P3.stampaDati();
	cout<<"\n";
	P4.stampaDati();
	cout<<"\n";
	cout << "\n\n\n";
	
	
	Elenco E1;
	E1.inserisci(P1);
	E1.inserisci(P2);
	E1.inserisci(P3);
	E1.stampaElenco();
	
	ofstream file;
	file.open("./test.txt", ios::out);
	
	if(!file) {
		cout << "Errore file.";
	} else {
		E1.stampaFile(file);
	}
	
	cout << "\n\n\n";
	Prodotto PT;
	E1.elimina(P1.getCod(), PT);
	E1.stampaElenco();
	
	cout << "\n\n\n";
	PT.stampaDati();
	cout << "\n\n\n";
	
	try {
		E1.inserisci(P2);
	} catch (Duplicato d) {
		cout << d.what();
	}
	return 0;
}
