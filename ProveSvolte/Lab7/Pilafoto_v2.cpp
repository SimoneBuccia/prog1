#include <iostream>
#include "Pilafoto_v2.h"
#include "Eccezione.h"

using namespace std;


// implementazione della classe Immagine


Immagine::Immagine(const char * P, const char * F){
	Proprietario=new char[strlen(P)+1];
    strcpy(Proprietario,P);
    Formato=new char[strlen(F)+1];
    strcpy(Formato,F);
}

Immagine::Immagine(const Immagine & I){
	Proprietario=new char[strlen(I.Proprietario)+1];
    strcpy(Proprietario,I.Proprietario);
    Formato=new char[strlen(I.Formato)+1];
    strcpy(Formato,I.Formato);
}
Immagine & Immagine::operator=(const Immagine & I){
	if(this!=&I) {
	   if (Proprietario) delete [] Proprietario;
	   Proprietario=new char[strlen(I.Proprietario)+1];
       strcpy(Proprietario,I.Proprietario);
	   if (Formato) delete [] Formato;
	   Formato=new char[strlen(I.Formato)+1];
       strcpy(Formato,I.Formato);
	}
    return * this;
}
void Immagine::setF(const char * F){
	if (Formato) delete [] Formato;
	Formato=new char[strlen(F)+1];
    strcpy(Formato,F);
}
void Immagine::setP(const char * P){
	 if (Proprietario) delete [] Proprietario;
	 Proprietario=new char[strlen(P)+1];
     strcpy(Proprietario,P);
}

ostream & operator << (ostream & out, const Immagine & I)	{
	out << I.Proprietario << ' ' << I.Formato;
	return out;
}

istream & operator >> (istream & in, Immagine & I) {
	char tempP[100], tempF[100];
	in >> tempP >> tempF;
	I.setP(tempP);
	I.setF(tempF);
	return in;
}

void Immagine:: print() const {
	cout << "Proprietario: " << Proprietario << ' ' << "Formato: " << Formato;
}

// implementazione della classe Fotografia

Fotografia::Fotografia(const char * P, const char * F, const int K, const char * S, const bool B): Immagine(P,F) {
    Soggetto=new char[strlen(S)+1];
    strcpy(Soggetto,S);
    key=K;
    flag=B;
}

Fotografia::Fotografia(const Fotografia & F): Immagine(F){
    Soggetto=new char[strlen(F.Soggetto)+1];
    strcpy(Soggetto,F.Soggetto);
    key=F.key;
    flag=F.flag;
}

Fotografia & Fotografia::operator=(const Fotografia & F){
	if(this!=&F) {
	   Immagine::operator=(F);	
	   if (Soggetto) delete [] Soggetto;
       Soggetto=new char[strlen(F.Soggetto)+1];
       strcpy(Soggetto,F.Soggetto);
       key=F.key;
       flag=F.flag;
	}
    return * this;
}

void Fotografia::setS(const char * S) {
	 if (Soggetto) delete [] Soggetto;
	 Soggetto=new char[strlen(S)+1];
     strcpy(Soggetto,S);
}


ostream & operator << (ostream & out, const Fotografia & F){
	out << (Immagine &)F << ' ' << F.key  << ' '<< F.Soggetto;
	return out;
}

istream & operator >> (istream & in, Fotografia & F) {
	char tempS[100];
	in >> (Immagine &)F >> F.key >> tempS;
	F.setS(tempS);
	return in;
}

void Fotografia:: print() const {
	Immagine::print();
	cout << "Chiave: " << key << ' ' << "Soggetto: " << Soggetto;
}



// implementazione della classe Pila


void swap(Fotografia &, Fotografia&);

        
bool Pila::pop(Fotografia & F){
    if (!empty()) {
    testa--;
    F=V[testa];
    return true;}
    else return false;
}

void Pila::top(Fotografia & F) const{
    F=V[testa-1];
}

bool Pila::push(const Fotografia & F){
    if (!full()) {
    V[testa]=F;
    testa++;
    return true;}
    else return false;
}
bool Pila::ricerca(const int K, int & pos)const{
    bool trovato=false;
    int i=0;
    while(i<testa && !trovato)
      if (V[i].getID()==K) {
        trovato=true;
        pos=i;
    }      
     else i++;   
   return trovato;
}

void Pila::sposta(const int K) {
    int pos=-1;
    if (!ricerca(K,pos)) throw bad_event("elemento da spostare non presente");
    swap(V[pos],V[testa-1]); 
}

void Pila::visualizza() const {
 
    int temp=(testa-1);
    for (int i=temp; i>=0; i--) {
      cout << V[i] << endl;
   }      
}

void swap(Fotografia & F1, Fotografia& F2) {
    Fotografia temp;
    temp=F1;
    F1=F2;
    F2=temp;
}    

istream & operator >> (istream & in, Pila & P) {
    Fotografia F;
	while(in >> F) P.push(F);
	return in;
}

ostream & operator << (ostream & out, const Pila & P) {
	int temp=(P.testa-1);
    for (int i=temp; i>=0; i--) {
      out << P.V[i] << '\n';
   } 
   return out;
}


/*
void Pila::stampa(ostream & out) const {
	int temp=(testa-1);
    for (int i=temp; i>=0; i--) {
      out << V[i] << '\n';
   } 
}
*/



