#ifndef QUOTIDIANO_H
#define QUOTIDIANO_H

#include "Giornale.h"




class Quotidiano:public Giornale{
	friend ostream & operator<<(ostream &, const Quotidiano&);
	friend ofstream & operator<<(ofstream &, const Quotidiano&);
	friend istream & operator>>(istream &,Quotidiano&);
	
	private:
	char* Direttore;
	bool Inserto;

	public:
	Quotidiano(const float =0.0,const char* ="", const bool =false,const char* ="",const bool =false);
	Quotidiano(const Quotidiano&);
	Quotidiano & operator=(const Quotidiano&);
	const char* get_Direttore()const;
	const bool get_Inserto()const;
	void set_Direttore(const char*);
	void set_Inserto(const bool);
	virtual ostream & stampa_Dati(ostream &)const;
	virtual ofstream & memorizza_Dati(ofstream &)const;
	virtual ~Quotidiano(){delete [] Direttore;}

};

#endif
