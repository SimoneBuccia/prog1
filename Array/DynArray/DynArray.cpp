
#include "DynArray.h"

const int DEFSIZE=5;

// funzioni utilizzate solo da questo modulo
void resize(DynArray &);
//void fill(T*, T*, const T);

// implementazione

void start(DynArray & D){
    D.first=D.end=D.last=0;
}

void initiate(DynArray & D, const T e){
    D.first=new T[DEFSIZE];
    D.last=D.first;
    D.end=D.first+DEFSIZE;
    for (int i=0; i<DEFSIZE; i++)
    *(D.first+i)=e;   
    //fill(D.first,D.last,e);
}

void pushback(DynArray & D, const T e){
    
    if(D.end==D.last) resize(D);
    // aggiunge l'elemento alla fine del vettore
    *D.last=e;
     D.last++;
}

void popback(DynArray & D, T & e){D.last--; e=*D.last;}

void copy(DynArray & D, const DynArray & O){
     // calcola la capacità del vettore origine
     long newcapacity=get_capacity(O);
     // dealloca il "vecchio" vettore
     delete [] D.first;
     // rialloca 
     D.first=new T[newcapacity];
     // aggiorna le variabili di stato sulla base di quelle del vettore origine
     D.last=D.first+get_size(O);
     D.end=D.first+newcapacity;
     // copia il vettore origine nel vettore destinazione
     T* f=D.first;
     T* fo=O.first;
     for(; f!=D.last; f++,fo++) *f=*fo;
}

long  get_size(const DynArray & D){return D.last-D.first;}

long  get_capacity(const DynArray & D){return D.end-D.first;}

bool empty(const DynArray & D){return D.first==D.last;}

bool full(const DynArray & D){return false;}

void clear(DynArray & D) {
     delete [] D.first;
     D.first=D.last=D.end=0;
}

void print(const DynArray & D){
     if (empty(D))  cout << "[ ]";
     else {
     T* f=D.first;
     T* l=D.last;
     cout << "[";
     for(; f!=l; f++) cout<< setw(5) << *f;
     cout << "]";
     }    
}

void resize(DynArray & D)  { // resize
    long newcapacity=get_capacity(D)+10;
    long oldsize=get_size(D);
    // alloca il "nuovo" vettore di capacità aumentata
    T* newArray=new T[newcapacity];
    // copia il contenuto del "vecchio" vettore nel nuovo
    T* f=D.first;
    T* fnew=newArray;
    for(; f!=D.last; f++,fnew++) *fnew=*f;
    // dealloca lo spazio di memoria associato al "vecchio" vettore
    delete [] D.first;
    // aggiorna tutte le variabili di stato
    D.first=newArray;
    D.last=D.first+oldsize;
    D.end=D.first+newcapacity;
}

/*
void fill(T * f, T* l, const T e){  
    for(; f!=l; ++f) *f=e;  
}
*/



