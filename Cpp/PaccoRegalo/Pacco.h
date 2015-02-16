#ifndef _PACCHETTOREGALO_H_
#define _PACCHETTOREGALO_H_

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Pacco {
	friend ostream & operator<<(ostream &, const Pacco &);
	friend istream & operator>>(istream &, Pacco &);
	
	private:
		char * Destinatario;
		float Peso;
		char * Forma;
	public:
		Pacco(const char * = "", float = 0.0, const char * = "");
		Pacco(const Pacco &);
		~Pacco();
		const Pacco & operator=(const Pacco &);
		
		const char * getDestinatario() const;
		void setDestinatario(const char *);
		float getPeso() const;
		void setPeso(const float);
		const char * getForma() const;
		void setForma(const char *);
			
};

#endif
