#include "Pila.h"


int main(int argc, char** argv) {
	Gettone G1("legno", 20);
	Gettone G2("ferro", 20);
	Fiches F1("ferro", 100, "cerchio", "rosso");
	Fiches F2("plastica", 100, "quadrato", "blu");
	
	
	Gettone * V[4];
	V[0] = &G1;
	V[1] = &G2;
	V[2] = &F1;
	V[3] = &F2;
	for(int i=0; i<4; i++) {
		V[i]->print();
		cout<<"\n";
	}
	
	
	return 0;
}
