#ifndef _CODA_H_
#define _CODA_H_

#include "Fotografia.h"
#include "Errore.h"

typedef Fotografia T;

class Coda {
	private:
		static const int max = 10;
		T V[max];
		int testa;
		int coda;
		int nelem;
	public:
		Coda() {
			testa=coda=nelem=0;
		}
		Coda(const char *);
		void append(const T &) throw(Errore);
		void pop(T &) throw(Errore); 
		bool empty() const {
			return nelem==0;
		}
		bool full() const {
			return nelem==max;
		}
		bool stampa() const;
};

#endif
