#ifndef _PILA_H_
#define _PILA_H_

#include "Quotidiano.h"
#include "Rivista.h"
#include "SpaceOverflow.h"
 
typedef Giornale * Q;

class Pila {
	friend ostream & operator<<(ostream &, const Pila &);
	friend ofstream & operator<<(ofstream &, const Pila &);
	
	private:
		static const int max = 10;
		Q V[max];
		int testa;
		int nelem;
	
	public: 
		Pila() {
			testa=nelem=0;
		}
		
		void push(const Q &) throw(SpaceOverflow);
		bool pop(Q &);
		bool top(Q &) const;
		
		bool empty() const;
		bool full() const;
		
		ostream & stampaPila(ostream &) const;
		ofstream & memorizzaPila(ofstream &) const;
};
#endif
