#ifndef _LAVORATORE_H_
#define _LAVORATORE_H_

#include <iostream>
#include <cstring>

using namespace std;

class Lavoratore {
	friend ostream & operator<<(ostream &, const Lavoratore &);
	friend istream & operator>>(istream &, Lavoratore &);
	
	protected:
		char * Matricola;
		char * Azienda;
		int Anzianita;
		float StipendioBase;
	public:
		Lavoratore(const char * = "", const char * = "", const int = 0, const float = 0.0);
		Lavoratore(const Lavoratore &);
		virtual ~Lavoratore() {
			delete [] Matricola;
			delete [] Azienda;	
		}
		
		const char * getMatricola() const;
		void setMatricola(const char *);
		const char * getAzienda() const;
		void setAzienda(const char *);
		int getAnzianita() const;
		void setAnzianita(const int);
		float getStipendioBase() const;
		void setStipendioBase(const float);
		
		virtual float calcolaStipendio() const;
		
		const Lavoratore & operator=(const Lavoratore &);
};
#endif
