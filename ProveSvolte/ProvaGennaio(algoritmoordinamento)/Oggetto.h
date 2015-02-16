#ifndef OGGETTO_H
#define OGGETTO_H


#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Oggetto{
	friend ostream & operator<<(ostream &, const Oggetto&);
	friend istream & operator>>(istream &, Oggetto&);
	
	protected:
	char* ID;
	char* Tipo;
	
	public:
	Oggetto();
	Oggetto(const char*, const char*);
	Oggetto(const Oggetto&);
	Oggetto & operator=(const Oggetto&);
	const char* get_ID() const;
	const char* get_Tipo() const;
	void set_ID(const char*);
	void set_Tipo(const char*);
	virtual ~Oggetto(){delete [] ID; delete[] Tipo;}

};

#endif
