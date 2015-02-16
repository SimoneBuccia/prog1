#ifndef GIORNALE_H
#define GIORNALE_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;


class Giornale{
	friend ostream & operator<<(ostream &, const Giornale&);
	friend ofstream & operator<<(ofstream &, const Giornale&);
	friend istream & operator>>(istream &,Giornale&);
	
	protected:
	float Costo;
	char* Titolo;
	bool Periodico;

	public:
	Giornale(const float =0.0,const char* ="", const bool =false);
	Giornale(const Giornale&);
	Giornale & operator=(const Giornale&);
	const float get_Costo()const;
	const char* get_Titolo()const;
	const bool get_Periodico()const;
	void set_Costo(const float);
	void set_Titolo(const char*);
	void set_Periodico(const bool);
	virtual ostream & stampa_Dati(ostream &)const;
	virtual ofstream & memorizza_Dati(ofstream &)const;
	virtual ~Giornale(){delete [] Titolo;}

};





#endif
