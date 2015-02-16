#ifndef _PILA_H
#define _PILA_H

#include <iostream>
#include "operaio.h"
#include "errore.h"
using namespace std;

typedef operaio T;

struct Record;

typedef Record * Ptr;

struct Record {
    T elem;
    Ptr next;      
};

class Pila {
 friend ostream & operator<<(ostream &, const Pila &);
 private:
      Ptr l;
 public:        
 Pila() {l=0;}
//Funzioni
 void push(const T &);
 void pop(T&) throw (errore);
 void top(T &) const;
//aggiungere cc e op=
//Predicati
bool empty() const;
bool full() const;
~Pila();
};



#endif
