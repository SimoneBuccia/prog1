#ifndef _ALIMENTARI_H_
#define _ALIMENTARI_H_

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Alimentari {
	friend ostream & operator<<(ostream &, const Alimentari &);
	
	protected:
		char * Cod;
		char * Des;
		int Mes;
		float Pre;
		
		Alimentari(const char * = "", const char * = "", int = 0, float = 0.0);
		Alimentari(const Alimentari &);
		const Alimentari & operator=(const Alimentari &);
		virtual ~Alimentari() {
			delete [] Cod;
			delete [] Des;
		}
		
	public:
		
		const char * getCod() const;
		void setCod(const char *);
		const char * getDes() const;
		void setDes(const char *);
		const int getMes() const;
		void setMes(const int);
		const float getPre() const;
		void setPre(const float);
		
		virtual void stampaDati() const;
		virtual void memorizzaDati(ostream &) const;
		
		virtual float Offerta(int) = 0;
};

#endif
