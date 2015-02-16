#ifndef _VETTORE_H_
#define _VETTORE_H_

#include<iostream>
#include<cstdlib>

using namespace std;
typedef int T;
class Vettore{
	friend ostream& operator<<(ostream&, const Vettore&);
	friend istream& operator>>(istream&, Vettore&);
	private:
		T* vet;
		int num;
	public:
		Vettore(int );
		Vettore( const Vettore&);
		Vettore& operator=(const Vettore&);
		bool operator==(const Vettore&)const ;	// ritorna se i due vettori sono uguali
		bool operator!=(const Vettore& Vet)const{ return !(*this==Vet); }
		void set_size(int &n){ this->num=n;		}
		const int get_size() const { return num;	}
		T& operator[](const int n) { return vet[n];}
	     const T& operator[](const int n) const {return vet[n];}
		~Vettore(){	delete [] vet;}
	
};

#endif
