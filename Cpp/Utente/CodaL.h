#ifndef _CODAL_
#define _CODAL_

#include "Utente.h"

typedef Utente T;

struct Record;

struct Record {
	T elem;
	Record * next;
};

class Coda {
	
	private :
		Record * testa;
		Record * coda;
		void push(const T &);
		
	public:
		Coda() : testa(0), coda(0) {}
		~Coda() {}
		
		bool append (const T &);
		bool pop(T &);
		
		bool empty() const {return (testa == 0);}
		bool full() const {return false;}

};


#endif
