#ifndef _LIBRO_H_
#define _LIBRO_H_

#include "Oggetto.h"

class Libro: public Oggetto {
	friend ostream & operator<<(ostream &, const Libro &);
	friend istream & operator>>(istream &, Libro &);
	
	protected:
		char * autore;
		char * titolo;
		int anno;
	public:
		Libro(const char * = "", const char * = "", const char * = "", const char * = "", const int = 0);
	  	Libro(const Libro &);
		const Libro & operator=(const Libro &);
		virtual ~Libro() {
			delete [] autore;
			delete [] titolo;
		}
		
		const char * getAutore() const;
		void setAutore(const char *);
		const char * getTitolo() const;
		void setTitolo(const char *);
		const int getAnno() const;
		void setAnno(const int);
		
		
};

#endif
