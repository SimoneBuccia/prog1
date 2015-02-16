#ifndef PILA_H
#define PILA_H

#include "Quotidiano.h"
#include "Errore.h"

typedef Giornale* Q;

class Pila {
friend ostream & operator<<(ostream &,const Pila&);
friend ofstream & operator<<(ofstream &,const Pila&);
private:
 static const int N=5;
 Q V[N];
 int testa;
 int nelem;
 
 bool ricerca(const int, int &) const;
 
 public:
     Pila() {testa=nelem=0;}
     bool pop(Q &);
     void top(Q &) const;
     void push(const Q &) throw (Errore);
     bool empty() const {return testa==0;}
     bool full() const {return testa==N;}
     ostream & stampa(ostream &) const;
     ofstream & memorizzaPila(ofstream &)const;
     void visualizza() const;
     
}; 

#endif
