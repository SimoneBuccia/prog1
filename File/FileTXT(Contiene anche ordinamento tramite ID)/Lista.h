#ifndef LISTA_H
#define LISTA_H


#include "ProdottiFreschi.h"
#include "Errore.h"
#include <fstream>

using namespace std;

typedef Prodotti T;

struct Record;

struct Record { 
    T elem;
    Record * next; 
}; 

class Lista {
	private:    
     Record * testa;
     int nelem;
     
	public:
    Lista() {
	testa=0;}
    void InsertAtFront(const T &) throw(Errore);
    void Print() const;
    void Salva_File(const char*) const;
    bool InList(const char*) const;
    bool Cancella(const char*);
	bool empty(){
	return testa==0;}
	bool full(){
	return false;} 
    ~Lista();
};     
#endif
