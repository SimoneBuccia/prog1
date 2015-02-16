#ifndef _DYNARRAY_
#define _DYNARRAY_

#include <iostream>
#include <iomanip>

using namespace std;

typedef int T;

struct DynArray{
    T * first; // punta al primo elemento
    T * last;  // punta alla posizione successiva all'ultimo elemento
    T * end;   // punta alla posizione successiva all'ultimo allocato
};    

void start(DynArray &);
void initiate(DynArray &, const T);
void pushback(DynArray &, const T);
void popback(DynArray &, T &);
void copy(DynArray &, const DynArray &);
long  get_size(const DynArray &);
long  get_capacity(const DynArray &);
bool empty(const DynArray &);
bool full(const DynArray &);
void clear(DynArray &);
void print(const DynArray &);

#endif
