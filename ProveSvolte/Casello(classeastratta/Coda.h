#ifndef _CODA_H_
#define _CODA_H_

#include "Autobus.h"
#include "BadStatus.h"

typedef Autoveicolo * T;

struct Record;
typedef Record * Ptr;
struct Record {
	T elem;
	Ptr next;
};

class Coda {
	friend ostream & operator<<(ostream &, const Coda &);
	private:
		Ptr testa;
		Ptr coda;
		int nelem;
		static int Incasso;
		
		bool push(const T &);
		
	public:
		Coda() {
			testa = coda = 0;
			nelem = 0;
		}
		~Coda();
		
		bool append(const T &);
		void pop(T &, int) throw(BadStatus);
		bool empty();
		bool full();
		const int getNelem() const {
			return nelem;
		}
		static int getIncasso() {
			return Incasso;
		}
		
};

#endif
