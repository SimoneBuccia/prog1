#ifndef _VETTORE_
#define _VETTORE_

#include <iostream>
#include <cstdlib>

using namespace std;

typedef int T;

class Vettore {
	
	friend ostream & operator<<(ostream &, const Vettore &);
	friend istream & operator>>(istream &, Vettore &);
	
	private:
		T * ptr;
		int size;
	public:
		explicit Vettore(const int = 1);
		Vettore(const Vettore &);
		~Vettore();
		
		int getSize() const;
		
		const Vettore & operator=(const Vettore &);
		
		bool operator==(const Vettore &) const;
		bool operator!=(const Vettore &) const;
		
		T operator[](const int) const;
		T & operator[](const int);
		
};

#endif
