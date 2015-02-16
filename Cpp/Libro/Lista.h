#ifndef _LISTA_H_
#define _LISTA_H_

#include "Fotografia.h"
#include "Eccezione.h"

typedef Fotografia T;

struct R;

struct R {
	T elem;
	R * next;
};

class Lista {
	private:
		R * testa;
		void push(const T &);
		
	public:
		Lista() {
			testa = 0;
		}
		~Lista();
		
		void inserisci(const T & l) throw(MyError);
		void stampa() const;
		bool ricerca(const char *) const;
		
		bool empty() {
			return testa==0;
		}
};

#endif
