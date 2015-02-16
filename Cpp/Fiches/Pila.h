#ifndef _PILA_H_
#define _PILA_H_

#include "Fiches.h"

typedef Fiches T;

struct Record;
typedef Record * Ptr;
struct Record {
	T elem;
	Ptr next;
};

class Pila {
	friend ostream & operator<<(ostream &, const Pila &);
	
	private:
		Ptr testa;
	
	public:
		Pila() {
			testa=0;
		}
		~Pila();
		
		bool push(const T &);
		bool pop(T &);
		bool top(T &) const;
		
		bool empty() const;
		bool full() const;
};
#endif
