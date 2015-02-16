#ifndef _PRATICA_
#define _PRATICA_

#include <iostream>
#include <cstring>

using namespace std;

class Pratica {
	friend ostream & operator<<(ostream &, const Pratica &);
	friend istream & operator>>(istream &, Pratica &);
	
	private:
		char * Codice; 
		char * Tipo;   

	public:
		Pratica(const char * = "", const char * = "");
		Pratica(const Pratica &);
		~Pratica() {
			delete [] Codice;
			delete [] Tipo;
		}
		
		const char * getCodice() const {return Codice;}
		const char * getTipo() const {return Tipo;}
		void setCodice(const char *);
		void setTipo(const char *);
		
		bool operator==(const Pratica &) const;
};

#endif
