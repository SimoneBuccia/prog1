#include "Coda.H"

bool Coda::inserisci(const Utente & u) {
	if(full()) return false;
	C[coda] = u;
	coda=((coda+1)%N);
	nelem++;
	return true;
}

bool Coda::elimina(Utente & u) {
	if(empty()) return false;
	u = C[testa];
	testa = ((testa+1)%N);
	nelem--;
	return true;
}

bool Coda::empty() const {
	return (nelem==0);
}

bool Coda::full()  const {
	return (nelem==N);
}

int Coda::get_SIZE() const {
	return N;
}

