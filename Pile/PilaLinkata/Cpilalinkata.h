#ifndef _PILA_H
#define _PILA_H

#include <iostream>


using namespace std;

typedef int T;

struct Record;

typedef Record * Ptr;

typedef struct Record {
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
 void pop(T&);
 void top(T &) const;

//Predicati
bool empty() const;
bool full() const;
~Pila();
};



#endif
