#ifndef _ELENCOFRESCHI_H_
#define _ELENCOFRESCHI_H_

#include "ProdottoFresco.h"
#include "Duplicato.h"

typedef Prodotto T;

struct Record;

struct Record {
	T elem;
	Record * next;
};

typedef Record * Ptr;

class Elenco {
	private:
		Record * testa;
	public:
		Elenco() {
			testa = 0;
		}
		~Elenco();
		
		void inserisci(const T &) throw(Duplicato);
		bool elimina(const char *, T &);
		bool ricerca(const char *, Ptr &) const;
		void stampaElenco() const;
		void stampaFile(ofstream &) const;
		bool empty() const;
		bool full() const;
};
#endif
