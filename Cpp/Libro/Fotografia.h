#ifndef _FOTOGRAFIA_H_
#define _FOTOGRAFIA_H_

#include "Libro.h"

class Fotografia: public Libro {
	friend ostream & operator<<(ostream &, const Fotografia &);
	friend istream & operator>>(istream &, Fotografia &);
	
	private:
		char * soggetto;
		char * formato;
	public:
		Fotografia(const char * = "", const char * = "", const char * = "", const char * = "", const int = 0, const char * = "", const char * = "");
	  	Fotografia(const Fotografia &);
		const Fotografia & operator=(const Fotografia &);
		virtual ~Fotografia() {
			delete [] soggetto;
			delete [] formato;
		}
		
		const char * getSoggetto() const;
		void setSoggetto(const char *);
		const char * getFormato() const;
		void setFormato(const char *);
};

#endif
