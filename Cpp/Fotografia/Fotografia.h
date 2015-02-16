#ifndef _FOTOGRAFIA_H_
#define _FOTOGRAFIA_H_

#include "Immagine.h"

class Fotografia: public Immagine {
	friend ostream & operator<<(ostream &, const Fotografia &);
	friend istream & operator>>(istream &, Fotografia &);
	
	private:
		int Chiave;
		char * Soggetto;
	public:
		Fotografia(const char * = "", const char * = "", const int = 0, const char * = "");
		Fotografia(const Fotografia &);
		virtual ~Fotografia() {
			delete [] Soggetto;
		}
		int getChiave() const;
		void setChiave(const int);
		const char * getSoggetto() const;
		void setSoggetto(const char *);
		
		const Fotografia & operator=(const Fotografia &);
		
		virtual void print() const;
};

#endif
