#ifndef _QUOTIDIANO_H_
#define _QUOTIDIANO_H_

#include "Giornale.h"

class Quotidiano : public Giornale {
	friend ostream & operator<<(ostream &, const Quotidiano &);
	friend istream & operator>>(istream &, Quotidiano &);
	friend ofstream & operator<<(ofstream &, const Quotidiano &);
	
	private:
		char * direttore;
		bool inserto;
		
	public:
		Quotidiano(const float = 0.0, const char * = "", const bool = false, const char * = "", const bool = false);
		Quotidiano(const Quotidiano &);
		const Quotidiano & operator=(const Quotidiano &);
		virtual ~Quotidiano();
		
		const char * getDirettore() const;
		void setDirettore(const char *);
		const bool getInserto() const;
		void setInserto(const bool);
		
		virtual ostream & stampaDati(ostream &) const;
		virtual ofstream & memorizzaDati(ofstream &) const;
};

#endif
