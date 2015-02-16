#ifndef _VETTORE_H_
#define _VETTORE_H_

#include "Pacco.h"
#include "Errore.h"

class Vettore {
	friend ostream & operator<<(ostream &, const Vettore &);
	friend istream & operator>>(istream &, Vettore &);
	
	private:
		Pacco * V;
		int nelem;
	public:
		explicit Vettore(const int = 10);
		Vettore(const Vettore &);
		~Vettore();
		const Vettore & operator=(const Vettore &);
		
		const int getNelem() const {
			return nelem;
		}
		
		Pacco & operator[](int);
		const Pacco & operator[](int) const;
		
		Pacco & Access(int) throw(Errore);
		const Pacco & Access(int) const throw(Errore);
		
		void Elimina();
};

#endif
