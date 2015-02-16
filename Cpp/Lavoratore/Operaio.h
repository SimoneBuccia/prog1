#ifndef _OPERAIO_H_
#define _OPERAIO_H_

#include "Lavoratore.h"

class Operaio: public Lavoratore {
	friend ostream & operator<<(ostream &, const Operaio &);
	friend istream & operator>>(istream &, Operaio &);
	
	private: 
		char * Settore;
		int OreMese;
	public:
		Operaio(const char * = "", const char * = "", const int = 0, const float = 0.0, const char * = "", const int = 0);
		Operaio(const Operaio &);
		virtual ~Operaio() {
			delete [] Settore;	
		}
		const Operaio & operator=(const Operaio &);
		
		const char * getSettore() const;
		void setSettore(const char *);
		int getOreMese() const;
		void setOreMese(const int);
		
		virtual float calcolaStipendio() const;
};

#endif
