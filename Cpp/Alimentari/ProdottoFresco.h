#ifndef _PRODOTTOFRESCO_H_
#define _PRODOTTOFRESCO_H_

#include "Alimentari.h"

class Prodotto : public Alimentari {
	private:
		char * Dat;
	public:
		Prodotto(const char * = "", const char * = "", int = 0, float = 0.0, const char * = "");
		Prodotto(const Prodotto &);
		const Prodotto & operator=(const Prodotto &);
		virtual ~Prodotto() {
			delete [] Dat;
		} 
		
		const char * getDat() const;
		void setDat(const char *);
		
		virtual void stampaDati() const;
		virtual void memorizzaDati(ostream &) const;
		
		virtual float Offerta(const int);
};
#endif
