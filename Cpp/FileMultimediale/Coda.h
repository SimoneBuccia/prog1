#ifndef _CODA_H_
#define _CODA_H_

#include "BranoMusicale.h"
#include "Video.h"

typedef File * T;

class Coda {
	private:
		static const int max = 5;
		T V[max];
		int testa;
		int coda;
		int nelem;
	public:
		Coda() {
			testa = coda = nelem = 0;
		}
		
		bool append(const T &);
		bool pop(File &);
		bool empty() const {
			return (nelem == 0);
		}
		bool full() const {
			return (nelem==max);
		}
		bool stampaCoda() const;
		
		void memorizzaDati(ofstream &) const;
};

#endif
