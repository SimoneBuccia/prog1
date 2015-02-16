#ifndef _FOTOGRAFIA_H_
#define _FOTOGRAFIA_H_

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


class Fotografia {
	friend ostream & operator<<(ostream &, const Fotografia &);
	friend istream & operator>>(istream &, Fotografia &);
	friend ofstream & operator<<(ofstream &, const Fotografia &);
	friend ifstream & operator>>(ifstream &, Fotografia &);
	
	private:
		char * Titolo;
		char * Formato;
	public:
		Fotografia(const char * = "", const char * = "");
		Fotografia(const Fotografia &);
		~Fotografia();
		const Fotografia & operator=(const Fotografia &);
		
		const char * getTitolo() const;
		void setTitolo(const char *);
		const char * getFormato() const;
		void setFormato(const char *);	
}; 

#endif
