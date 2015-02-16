#ifndef _OGGETTO_H_
#define _OGGETTO_H_

#include <iostream>
#include <cstring>

using namespace std;

class Oggetto {
	friend ostream & operator<<(ostream &, const Oggetto &);
	friend istream & operator>>(istream &, Oggetto &);
	
	protected:
		char * id;
		char * tipo;
	public:
		Oggetto(const char * = "", const char * = "");
		Oggetto(const Oggetto &);
		const Oggetto & operator=(const Oggetto &);
		virtual ~Oggetto() {
			delete [] id;
			delete [] tipo;
		}
		
		const char * getId() const;
		void setId(const char *);
		const char * getTipo() const;
		void setTipo(const char *);
		
		
};

#endif
