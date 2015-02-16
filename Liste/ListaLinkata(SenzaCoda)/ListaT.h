#ifndef CODAT_H
#define CODAT_H

#include <iostream>

using namespace std;

//typedef Pratica T;
typedef int T;

struct Record;

struct Record { 
    T elem;
    Record * next; 
}; 

class Lista {
    
//friend ostream & operator << (ostream &, const CodaTransazioni &);

public:
    Lista() {testa=0;}
    Lista(const Lista &);
    bool InsertAtFront(const T &);
	bool InsertAtBack(const T &);
	bool RemoveFromFront(T &);
	bool RemoveFromBack(T &);
	bool InList(const T &) const;
    const Lista & operator=(const Lista &);
	int Lenght() const;  // calcola il numero di elementi corrente
    bool Empty() const {return testa==0;}
    bool Full()  const {return false;}
    bool Print() const;
    ~Lista();
private:    
     Record * testa;
     void clear();
};     


#endif

