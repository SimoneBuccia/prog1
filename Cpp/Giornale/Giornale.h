#ifndef _GIORNALE_H_
#define _GIORNALE_H_

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Giornale {
	friend ostream & operator<<(ostream &, const Giornale &);
	friend istream & operator>>(istream &, Giornale &);
	friend ofstream & operator<<(ofstream &, const Giornale &);
	
	protected:
		float costo;
		char * titolo;
		bool periodico;
		
	public:
		Giornale(const float = 0.0, const char * = "", const bool = false);
		Giornale(const Giornale &);
		const Giornale & operator=(const Giornale &);
		virtual ~Giornale();
		
		const float getCosto() const;
		void setCosto(const float);
		const char * getTitolo() const;
		void setTitolo(const char *);
		const bool getPeriodico() const;
		void setPeriodico(const bool);
		
		virtual ostream & stampaDati(ostream &) const;
		virtual ofstream & memorizzaDati(ofstream &) const;
};

#endif
