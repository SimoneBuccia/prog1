#ifndef RIVISTA_H
#define RIVISTA_H

#include "Giornale.h"


using namespace std;


class Rivista:public Giornale{
	friend ostream & operator<<(ostream &, const Rivista&);
	friend ofstream & operator<<(ofstream &, const Rivista&);
	friend istream & operator>>(istream &,Rivista&);
	
	private:
	char* Editore;
	char* Periodo;

	public:
	Rivista(const float =0.0,const char* ="", const bool =false,const char* ="",const char* ="");
	Rivista(const Rivista&);
	Rivista & operator=(const Rivista&);
	const char* get_Periodo()const;
	const char* get_Editore()const;
	void set_Periodo(const char*);
	void set_Editore(const char*);
	virtual ostream & stampa_Dati(ostream &)const;
	virtual ofstream & memorizza_Dati(ofstream &)const;
	virtual ~Rivista(){delete [] Editore;}

};





#endif
