#ifndef _SQUADRA_
#define _SQUADRA_

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Squadra {
	friend ostream& operator<<(ostream&, const Squadra &);
	friend istream& operator>>(istream&, Squadra &);
	
	private:
		int Punti;
		char * Nome;
	public:
		Squadra(const int P = 0,  const char * N = "" ) {
			Punti = P;
			Nome = new char[strlen(N)+1];
			strcpy(Nome, N);
		}
		Squadra(const Squadra & S) {
			Punti = S.Punti;
			if(Nome) delete [] Nome;
			Nome = new char[strlen(S.Nome)+1];
			strcpy(Nome, S.Nome);
		}
		~Squadra() {
			delete [] Nome;
		}
		
		const char * getNome() const;
		int getPunti() const;
		void setPunti (const int);
		void setNome (const char *);
		void modificaPunti(const int);
		
		const Squadra & operator=(const Squadra &);
		
		bool operator==(const Squadra &) const;
		bool operator!=(const Squadra &) const;
		bool operator>=(const Squadra &) const;
		bool operator<=(const Squadra &) const;
		bool operator>(const Squadra &) const;
		bool operator<(const Squadra &) const;
};

#endif
