#ifndef CODAT_H
#define CODAT_H

#include <iostream>
#include "Persona.h"

using namespace std;

typedef Persona* T;

struct Record;

struct Record { 
    T elem;
    Record * next; 
}; 

class Coda {
    
//friend ostream & operator << (ostream &, const CodaTransazioni &);

public:
    Coda() {testa=0; coda=0;}
    bool Append(const T &);
    bool Pop(T &);
    bool Empty() const {return testa==0;}
    bool Full()  const {return false;}
    bool StampaCoda() const;
    ~Coda();
private:    
     Record * testa;
     Record * coda;
     void push(const T&);
};     







#endif

