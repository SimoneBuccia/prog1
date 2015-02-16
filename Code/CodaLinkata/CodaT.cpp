#include <iostream>
#include "CodaT.h"

using namespace std;


void Coda::push(const T& E){
    
    Record * p;
    p=new Record;
    p->elem=E;
    p->next=testa;
    testa=p;
}
     
     
 bool Coda::Append(const T & E){
     if(Full()) return false;
     if(testa==0){ push(E); coda=testa;}
     else {
         Record * p;
         p=new Record;
         p->elem=E;
         p->next=0;
         coda->next=p;
         coda=p; 
     }    
     return true;
 }
 
 bool Coda::Pop(T & E){
     if(Empty()) return false;
     Record * temp=testa; 
     E=testa->elem;
     testa=testa->next;
     delete temp;
     return true;   
 }
   
 Coda::~Coda(){	
 Record* temp;
	while(testa) {
		temp = testa;
		testa = testa->next;
		delete temp;
	}}
 
bool Coda::StampaCoda() const       
 {   if (Empty()) return false;
     else {
     Record * p= testa;
     while(p) {       
       p->elem.print();
       p=p->next;
     }      
   }   
   return true; 
 }
