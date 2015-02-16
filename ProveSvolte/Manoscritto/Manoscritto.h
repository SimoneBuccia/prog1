#ifndef _MANOSCRITTO_H_
#define _MANOSCRITTO_H_

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Manoscritto {
	friend ostream & operator<<(ostream &, const Manoscritto &);
	friend istream & operator>>(istream &, Manoscritto &);
	
	protected:
		int Cod;
		char * Aut;
		char * For;
		int Num;
	public:
		Manoscritto(const int = 0,const char * = "",const char * = "",const int = 0);
		Manoscritto(const Manoscritto &);
		const Manoscritto & operator=(const Manoscritto &);
		virtual ~Manoscritto();
		
		const int getCod() const;
		const char * getAut() const;
		const char * getFor() const;
		const int getNum() const;
		
		void setCod(const int);
		void setAut(const char *);
		void setFor(const char *);
		void setNum(const int);
		
		virtual void visualizzaDati() const;
		virtual void memorizzaDati(ostream &) const;
 };

#endif
