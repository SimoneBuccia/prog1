#ifndef _CODA_
#define _CODA_

#include "Brano.h"

using namespace std;

typedef Brano T;

class Coda {
	protected:
		T * C;
		int testa;
		int coda;
		int nelem;
		int maxdim;
		
	public:
		Coda(const int = 10);
		Coda(const Coda &);
		~Coda() {
			delete [] C;
		}
		
		bool append(const T &);
		bool pop(T &);
		bool empty() const;
		bool full() const;
		int getMaxdim() const;
		
		const Coda & operator=(const Coda &);
		
		void print() const;
};

#endif
