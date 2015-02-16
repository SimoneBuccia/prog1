#ifndef _FICHES_H_
#define _FICHES_H_

#include "Gettone.h"

class Fiches : public Gettone {
	friend ostream & operator<<(ostream &, const Fiches &);
	friend istream & operator>>(istream &, Fiches &);
	
	private:
		char * For;
		char * Col;
	
	public:
		Fiches(const char * = "", const int = 0, const char * = "", const char * = "");
		Fiches(const Fiches &);
		const Fiches & operator=(const Fiches &);
		virtual ~Fiches();
		
		const char * getFor() const;
		void setFor(const char *);
		const char * getCol() const;
		void setCol(const char *);
		
		virtual void print() const;
};
#endif
