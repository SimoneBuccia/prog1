#ifndef _PILA_H_
#define _PILA_H_

#include "Operaio.h"
#include "Errore.h"

typedef Operaio T;

struct Record;

struct Record {
	T elem;
	Record * next;	
};

class Pila {
	friend ostream & operator<<(ostream&, const Pila & P);
	
	private: 
		Record * testa;
	public:
		Pila() {
			testa = 0;
		}
		~Pila();
		
		bool push(const T &);
		void pop(T &) throw(Errore);
		bool top(T &) const ;
		
		bool empty() const {
			return (testa == 0);
		}
		
		bool full() const {
			return false;
		}
		
};

#endif
