#ifndef _PILA_H
#define _PILA_H

#include <iostream>
//#include "fiore.h"

using namespace std;

//typedef Prodotto T;
typedef int T;

//const int N=100;

class Pila {
private:   
    static const int N=2;          
    T P[N];
    int t;    
public:
//Funzioni
Pila();
void push(const T &);
void pop(T&);
void top(T&) const;
//Predicati
bool empty() const;
bool full() const;

friend ostream & operator<<(ostream &, const Pila &);
};









#endif
