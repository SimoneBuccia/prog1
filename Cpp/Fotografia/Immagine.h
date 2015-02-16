#ifndef _IMMAGINE_H_
#define _IMMAGINE_H_

#include <iostream>
#include <cstring>

using namespace std; 

class Immagine {
	friend ostream & operator<<(ostream &, const Immagine &);
	friend istream & operator>>(istream &, Immagine &);
	
	protected:
		char * Proprietario;
		char * Formato;
	public:
		Immagine(const char * = "", const char * = "");
		Immagine(const Immagine &);
		virtual ~Immagine() {
			delete [] Proprietario;
			delete [] Formato;
		}
		const char * getProprietario() const;
		void setProprietario(const char *);
		const char * getFormato() const;
		void setFormato(const char *);
		
		const Immagine & operator=(const Immagine &);
		
		virtual void print() const;
};



#endif
