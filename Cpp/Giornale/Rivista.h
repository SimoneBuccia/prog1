#ifndef _RIVISTA_H_
#define _RIVISTA_H_

#include "Giornale.h"

class Rivista : public Giornale {
	friend ostream & operator<<(ostream &, const Rivista &);
	friend istream & operator>>(istream &, Rivista &);
	friend ofstream & operator<<(ofstream &, const Rivista &);
	
	private:
		char * editore;
		char * periodo;
		
	public:
		Rivista(const float = 0.0, const char * = "", const bool = false, const char * = "", const char * = "");
		Rivista(const Rivista &);
		const Rivista & operator=(const Rivista &);
		virtual ~Rivista();
		
		const char * getEditore() const;
		void setEditore(const char *);
		const char * getPeriodo() const;
		void setPeriodo(const char *);
		
		virtual ostream & stampaDati(ostream &) const;
		virtual ofstream & memorizzaDati(ofstream &) const;
};

#endif
