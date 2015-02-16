#ifndef _BRANOMUSICALE_H_
#define _BRANOMUSICALE_H_

#include "FileMultimediale.h"

class Brano : public File {
	friend ostream & operator<<(ostream &, const Brano &);
	friend istream & operator>>(istream &, Brano &);
	
	private:
		char * Br;
		char * In;
		int Du;
	public:
		Brano(const char * = "", int = 0, const char * = "", const char * = "", const char * = "", int = 0);
		Brano(const Brano &);
		virtual ~Brano();
		const Brano & operator=(const Brano &);
		
		const char * getBr() const;
		void setBr(const char *);
		const char * getIn() const;
		void setIn(const char *);
		const int getDu() const;
		void setDu(const int);
		
		virtual void stampa() const;
		virtual void memorizza(ostream &) const;
};

#endif
