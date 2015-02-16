#ifndef _PACCO_H_
#define _PACCO_H_

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Pacco {
	friend ostream & operator<<(ostream &, const Pacco &);
	friend istream & operator>>(istream &, Pacco &);
	friend ofstream & operator<<(ofstream &, const Pacco &);
	friend ifstream & operator>>(ifstream &, Pacco &);
	
	private:
		int Codice;
		float Peso;
		char * Indirizzo;
	public:
		Pacco(const int = 0, const float = 0.0, const char * = "");
		Pacco(const Pacco &);
		const Pacco & operator=(const Pacco &);
		~Pacco();
		
		const int getCodice() const;
		void setCodice(const int);
		const float getPeso() const;
		void setPeso(const float);
		const char * getIndirizzo() const;
		void setIndirizzo(const char *);
};



#endif
