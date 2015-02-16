#include "pilavetclasse.h"

Pila::Pila(){
  t=0;
}

void Pila::push(const T & e){
      P[t]=e;
      t++;
}

void Pila::pop(T& e){
       t--;
       e=P[t];
}

void Pila::top(T& e) const{
     e=P[t-1];
}
ostream & operator<<(ostream & os, const Pila & p) {
     for(int i=p.P[p.t-1]; i>=0; i--)
       os << p.P[i] << endl;
     return os;  
}

//Predicati
bool Pila::empty()const {
     return t==0;
}
bool Pila::full()const{
     return t==N;
}



