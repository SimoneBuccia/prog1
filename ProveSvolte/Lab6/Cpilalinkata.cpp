#include "Cpilalinkata.h"


void Pila::push(const T & e){
     Ptr q=new Record;
     q->elem=e;
     q->next=l;
     l=q;
}

void Pila::pop(T& e) throw(errore) {
    if(empty()) throw errore();
    Ptr temp=l;
    e=l->elem;
    l=l->next;
    delete temp; 
}

void Pila::top(T& e)const{
      e=l->elem;
}

ostream & operator<<(ostream & os, const Pila & P){
     Ptr ptr;
     ptr=P.l;
     while(ptr){
       os << ptr->elem << endl;
       ptr=ptr->next;
       }
       return os;
}

//Predicati
bool Pila::empty()const{
     return l==0;
}
bool Pila::full()const{
     return false;
}

Pila::~Pila() {
    Ptr temp;
    while(l) {
      temp=l;
      l=l->next;
      delete temp;
    }
}

