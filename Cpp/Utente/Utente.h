#ifndef _UTENTE_
#define _UTENTE_


#include <iostream>
#include <cstring>

using namespace std;

class Utente {
	friend ostream & operator<<(ostream &, const Utente &);
	friend istream & operator>>(istream &, Utente &);
	
	private:
		char * Nome;
		char * Cognome;
		
	public:
		Utente(const char * = "", const char * = "");
		Utente(const Utente &);
		~Utente();
		
		const char * getNome() const;
		const char * getCognome() const;
		void setNome(const char *);
		void setCognome(const char *);
};


#endif

