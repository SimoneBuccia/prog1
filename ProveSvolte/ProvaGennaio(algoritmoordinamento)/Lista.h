#include "Fotografia.h"
#include "MyError.h"

#ifndef CODAT_H
#define CODAT_H

#include <iostream>

using namespace std;

typedef Fotografia T;

struct Record;

struct Record { 
    T elem;
    Record * next; 
}; 

class Lista {
    

public:
    Lista() {testa=0; }
    void InsertAtFront(const T &) throw(MyError);
    void Print() const;
    bool InList(const char*) const; 
    ~Lista();
private:    
     Record * testa;
};     
#endif
