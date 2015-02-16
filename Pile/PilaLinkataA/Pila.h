#ifndef _PILA_H_
#define _PILA_H_

#include "Pacco.h"
#include "FileExcep.h"

typedef Pacco T;

struct Record;

struct Record {
	T elem;
	Record * next;
};

class Pila {
	private:
		Record * testa;
		int nelem;
	public:
		Pila() {
			testa = 0;
			nelem = 0;
		}
		~Pila();
		
		bool push(const T &);
		bool pop(T &);
		bool top(T &) const;
		bool empty() const;
		bool full() const;
		
		void salvaFile(ofstream &) const;
		void leggiFile(ifstream &) throw(Ecc);
		void stampa() const;
};

#endif
