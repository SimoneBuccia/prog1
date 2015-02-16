#include "Lista.h"

int main(int argc, char** argv) {
	Fotografia F1("bbb", "tipo1", "autore1", "titolo1", 2015, "soggetto1", "formato1");
	Fotografia F2("aaa", "tipo2", "autore2", "titolo2", 2015, "soggetto2", "formato2");
	Fotografia F3("ccc", "tipo3", "autore3", "titolo3", 2015, "soggetto3", "formato3");
	Fotografia F4("ddd", "tipo4", "autore4", "titolo4", 2015, "soggetto4", "formato4");
	Fotografia F5;
	
	
	cout << "Inserimento elemento:\n";
	cin >> F5;
	
	cout << "\n\n\nStampa Elementi:\n";
	cout << F1 << endl << F2 << endl << F3 << endl << F4<< endl<<F5<< endl;
	
	
	cout << "\n\n\nF6=F4:\n";
	Fotografia F6 = F4;
	cout<<F6<< endl;
	
	cout << "\n\n\nCopia:\n";
	F6 = F1;
	cout << F6<< endl;
	
	cout << "\n\n\nLista:\n";
	Lista l;
	try {
		l.inserisci(F1);
		l.inserisci(F2);
		l.inserisci(F3);
		l.inserisci(F4);
		l.inserisci(F5);
	} catch (MyError e) {
		cout << e.what();
	}
	
	l.stampa();
	
	cout << "\n\n\nEccezione:\n";
	try {
		l.inserisci(F1);
	} catch (MyError e) {
		cout << e.what();
	}
	
}
