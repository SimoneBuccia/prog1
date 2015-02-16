#ifndef _AUTOVETTURA_H_
#define _AUTOVETTURA_H_

#include "Autoveicolo.h"

class Autovettura : public Autoveicolo {
	friend ostream & operator<<(ostream &, const Autovettura &);
	friend istream & operator>>(istream &, Autovettura &);
	
	protected:
		char * Tipo;
		int Posti;
		
	public:
		Autovettura(const char * = "", const char * = "", const char * = "", const int = 0);
		Autovettura(const Autovettura &);
		const Autovettura & operator=(const Autovettura &);
		virtual ~Autovettura();	
		
		const char * getTipo() const;
		void setTipo(const char *);
		const int getPosti() const;
		void setPosti(const int);
		
		virtual void stampaDati() const;
		virtual const float calcolaPedaggio(const int) const;
};
#endif
