#ifndef FOTOGRAFIA_H
#define FOTOGRAFIA_H

#include "Libro.h"


class Fotografia : public Libro {


	friend ostream & operator<<(ostream &, const Fotografia&);
	friend istream & operator>>(istream &, Fotografia&);
	
	private:
	char* Soggetto;
	char* Formato;
	
	public:
	Fotografia(const char* ="",const char* ="",const char* ="", const char* ="",const int=0,const char* ="",const char* ="");
	Fotografia(const Fotografia&);
	Fotografia & operator=(const Fotografia&);
	const char* get_Soggetto() const;
	const char* get_Formato() const;
	
	void set_Soggetto(const char*);
	void set_Formato(const char*);
	
	virtual ~Fotografia(){delete[] Soggetto;delete[]Formato;}
	
	};
	
	#endif
