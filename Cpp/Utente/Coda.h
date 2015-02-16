#ifndef _CODA_
#define _CODA_

#include "Utente.h"

typedef Utente T;

class Coda {
	private :
		static const int N = 3;
		T C[N];
		int testa;
		int coda;
		int nelem;
	public:
		Coda() {
			testa = coda = nelem = 0;
		}
		bool inserisci(const Utente &);
		bool elimina(Utente &);
		bool empty() const;
		bool full()  const;
		int get_SIZE() const;

};


#endif

