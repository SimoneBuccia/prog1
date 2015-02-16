#ifndef _PILA_H_
#define _PILA_H_

#include "Fotografia.h"

typedef Fotografia T;

class Pila {
	friend ostream & operator<<(ostream &, const Pila &);
	friend istream & operator>>(istream &, Pila &);
	
	private:
		static const int dim = 5;
		T V[dim];
		int testa;
	public:
		Pila() {
			testa = 0;
		}; 
		bool pop(T &);
		bool top(T &) const;
		bool push(const T &);
		bool empty() const;
		bool full() const;
		bool sposta_in_testa(const int);

};

#endif
