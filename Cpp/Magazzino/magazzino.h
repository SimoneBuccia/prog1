#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct {
	
	int Qta;
	char * Codice;
	char * Descrizione;
	
} Prodotto ;

void inserisciDati(Prodotto &);
void modificaCodice(Prodotto &);
const char * fornisciCodice(const Prodotto &);
void visualizzaDati(const Prodotto &);


