#ifndef _AUTOVEICOLO_H_
#define _AUTOVEICOLO_H_

#include <iostream>
#include <cstring>

using namespace std;

class Autoveicolo {
	friend ostream & operator<<(ostream &, const Autoveicolo &);
	friend istream & operator>>(istream &, Autoveicolo &);
	
	protected:
		char * Targa;
		char * Alim;
		
		Autoveicolo(const char * = "", const char * = "");
		Autoveicolo(const Autoveicolo &);
		const Autoveicolo & operator=(const Autoveicolo &);
		virtual ~Autoveicolo();	
			
	public:
		const char * getTarga() const;
		void setTarga(const char *);
		const char * getAlim() const;
		void setAlim(const char *);
		
		virtual void stampaDati() const = 0;
		virtual const float calcolaPedaggio(const int) const = 0;
};

#endif
