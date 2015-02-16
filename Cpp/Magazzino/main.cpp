#include "magazzino.h"


int main(int argc, char** argv) {
	Prodotto p;
	inserisciDati(p);
	modificaCodice(p);
	visualizzaDati(p);
	cout<<endl<<fornisciCodice(p);
	return 0;
}
