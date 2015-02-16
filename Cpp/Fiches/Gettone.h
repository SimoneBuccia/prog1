#ifndef _GETTONE_H_
#define _GETTONE_H_

#include <iostream>
#include <cstring>

using namespace std; 

class Gettone {
	friend ostream & operator<<(ostream &, const Gettone &);
	friend istream & operator>>(istream &, Gettone &);
	
	protected:
		char * Mat;
		int Val;
	
	public:
		Gettone(const char * = "", const int = 0);
		Gettone(const Gettone &);
		const Gettone & operator=(const Gettone &);
		virtual ~Gettone();
		
		const char * getMat() const;
		void setMat(const char *);
		const int getVal() const;
		void setVal(const int);
		
		virtual void print() const;
		
};

#endif
