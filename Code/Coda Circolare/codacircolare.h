#ifndef CODA_H
#define CODA_H


#include <iostream>
#include "utente2.h"

using namespace std;
typedef Utente T;

class Coda {
  private:	
   static const int DIM=3;
   T C[DIM];
   int t;         // indice che punta alla testa
   int c;         // indice che punta alla coda
   int nelem;     // numero di elementi in coda
 public:
   Coda(); 
   bool inserisci(const T &);
   bool elimina(T &);
   bool empty() const ;
   bool full() const;  
   int get_MAXDIM() const;
};
    

#endif    
             



