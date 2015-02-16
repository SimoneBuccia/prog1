#ifndef _ELENCO_H_
#define _ELENCO_H_

#include "Lettera.h"
#include "Duplicato.h"

typedef Manoscritto * T;

class Elenco {
	private:
		static const int max = 10;
		T V[max];
		int nelem;
	public:
		Elenco() {
			nelem = 0;
		}		 
		
		void push(const T &) throw(Duplicato);
		bool pop(const int);
		bool empty() const {
			return (nelem==0);
		}
		bool full() const {
			return (nelem==max);
		}
		void stampa() const;
		void memorizzaDati(ostream &) const;
};
#endif
