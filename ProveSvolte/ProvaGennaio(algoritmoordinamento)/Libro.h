#ifndef LIBRO_H
#define LIBRO_H
#include "Oggetto.h"


class Libro:public Oggetto{


	friend ostream & operator<<(ostream &, const Libro&);
	friend istream & operator>>(istream &, Libro&);
	
	protected:
	char* Autori;
	char* Titolo;
	int Anno;
	
	public:
	Libro():Oggetto(){Autori=0;Titolo=0;Anno=0;}
	Libro(const char*,const char*,const char*, const char*,const int);
	Libro(const Libro&);
	Libro & operator=(const Libro&);
	const char* get_Autori() const;
	const char* get_Titolo() const;
	int get_Anno() const;
	void set_Autori(const char*);
	void set_Titolo(const char*);
	void set_Anno(const int);
	
	virtual ~Libro(){delete[] Autori;delete[] Titolo;
	}





};
#endif
