#ifndef _AUTOBUS_H_
#define _AUTOBUS_H_

#include "Autovettura.h"

class Autobus : public Autovettura {
	friend ostream & operator<<(ostream &, const Autobus &);
	friend istream & operator>>(istream &, Autobus &);
	
	private:
		char * Dest;
		int Massa;
		
	public:
		Autobus(const char * = "", const char * = "", const char * = "", const int = 0, const char * = "", const int = 0);
		Autobus(const Autobus &);
		const Autobus & operator=(const Autobus &);
		virtual ~Autobus();	
		
		const char * getDest() const;
		void setDest(const char *);
		const int getMassa() const;
		void setMassa(const int);
		
		virtual void stampaDati() const;
		virtual const float calcolaPedaggio(const int) const;
};

#endif
