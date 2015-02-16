#include "Pila.h"



ostream & operator<<(ostream &os,const Pila&P){
return P.stampa(os);
}
ofstream & operator<<(ofstream &os,const Pila&P){
return P.memorizzaPila(os);
}
        
bool Pila::pop(Q & F){
    if (!empty()) {
    testa--;
    nelem--;
    F=V[testa];
    return true;}
    else return false;
}
void Pila::top(Q & F) const{
    F=V[testa-1];
}
void Pila::push(const Q & F)throw (Errore){
    if (full()) throw Errore("Pila Piena");
    V[testa]=F;
    testa++;
    nelem++;
}


ofstream & Pila::memorizzaPila(ofstream & out)const{
	for(int i=0;i<nelem;i++){
	out<<*V[i];
}
return out;
}
ostream & Pila::stampa(ostream & out) const {
    for (int i=0; i<nelem; i++) {
      out << *V[i] << '\n';
   }
   return out;
}

