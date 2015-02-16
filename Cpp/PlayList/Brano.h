#ifndef _BRANO_
#define _BRANO_

#include <iostream>
#include <cstring>

using namespace std;

class Brano {
	friend ostream & operator<<(ostream &, const Brano &);
	friend istream & operator>>(istream &, Brano &);
	
	private:
		string Titolo;
		string Autore;
		int Id;
		float Durata;
	public:
		Brano(const string = "", const string = "", const int = 0, const float = 0.0);
		string getTitolo() const;
		void setTitolo(const string);
		string getAutore() const;
		void setAutore(const string);
		int getId() const;
		void setId(const int);
		float getDurata() const;
		void setDurata(const float);
};




#endif
