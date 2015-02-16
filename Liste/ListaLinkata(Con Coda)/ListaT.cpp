#include <iostream>
#include "ListaT.h"

using namespace std;

bool Lista::InsertAtFront(const T& E){
    if(Full()) return false;
    Record * p;
    p=new Record;
    p->elem=E;
    p->next=testa;
    testa=p;
    if(testa->next==0)coda=testa;
    return true;
}
    
bool Lista::InsertAtBack(const T & E){
     if(Full()) return false;
     if(Empty()) return InsertAtFront(E);
         Record * p;
         p=new Record;
         p->elem=E;
         p->next=0;
         coda->next=p;
         coda=p; 
         return true;
 }
 
bool Lista::RemoveFromFront(T & E){
     if(Empty()) return false;
     Record * temp=testa; 
     E=testa->elem;
     testa=testa->next;
     delete temp;
     if (Lenght()==0) coda=0;
     return true;   
 }
 
bool Lista::RemoveFromBack(T & E){
     if(Empty()) return false;
     if(testa->next==0) return RemoveFromFront(E);
     else {
     Record * temp=testa; 
     Record * temp1;
     while(temp->next!=coda) temp=temp->next;
     E=coda->elem;
     temp1=coda;
     temp->next=0;
     coda=temp;
     delete temp1;
     return true; }  
 }
 
bool Lista::InList(const T & E) const {
    bool trovato=false;
    Record * temp=testa;
    
    while(temp && !trovato)
      if(temp->elem == E)
        trovato=true;
      else temp=temp->next;
    return trovato;    
}

int Lista::Lenght() const{
    int count =0;
    Record * temp=testa;
    while(temp) {count++; temp=temp->next;} 
    return count;   
}
   
Lista::~Lista(){            
   Record * temp=testa;
   while(testa){
     temp=testa; 
     testa = testa->next;
     delete temp;
}
   
   
                  

}
 
bool Lista::Print() const       
 {   if (Empty()) return false;
     else {
     Record * temp= testa;
     while(temp) {
       cout << temp->elem << "\t";
       temp=temp->next;
     }      
   }   
   return true; 
 }
