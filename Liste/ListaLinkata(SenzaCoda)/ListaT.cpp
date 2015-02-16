#include <iostream>
#include "ListaT.h"

using namespace std;



Lista::Lista(const Lista & L) {
	testa=0;
	Record * temp=L.testa;
	while(temp) {  InsertAtBack(temp->elem);
	            temp=temp->next;
	
	}
}

const Lista & Lista::operator=(const Lista & L) {
	if(this!=&L) {
		if (testa) clear();
		if (L.testa) {
		   Record * temp=L.testa;
        	while(temp) {
	            InsertAtBack(temp->elem);
	            temp=temp->next;
        	}
		} 
	}
	return *this;
}

bool Lista::InsertAtFront(const T& E){
    if(Full()) return false;
    Record * p;
    p=new Record;
    p->elem=E;
    p->next=testa;
    testa=p;
    return true;
}
    
bool Lista::InsertAtBack(const T & E){
     if(Full()) return false;
     if(Empty()) return InsertAtFront(E);
      Record * p;
      Record * temp=testa;
      p=new Record;
      p->elem=E;
      p->next=0;
      while(temp->next) temp=temp->next;
      temp->next=p;
      return true;
 }
 
bool Lista::RemoveFromFront(T & E){
     if(Empty()) return false;
     Record * temp=testa; 
     E=testa->elem;
     testa=testa->next;
     delete temp; 
     return true;   
 }
 
bool Lista::RemoveFromBack(T & E){
     if(Empty()) return false;
     if(testa->next==0) return RemoveFromFront(E);
     else {
     Record * temp=testa; 
     Record * temp1;
     while(temp->next->next) temp=temp->next;
     temp1=temp->next;
     E=temp->next-> elem;
     temp->next=0;
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
   
void Lista::clear() {
   Record * temp=testa;
   while(testa){
      temp=testa; 
      testa = testa->next;
      delete temp;
   }
} 

Lista::~Lista(){            
  clear();
}
 
bool Lista::Print() const       
 {   if (Empty()) return false;
     else {
     Record * temp= testa;
     while(temp) {
       cout << temp->elem << ' ';
       temp=temp->next;
     }      
   }   
   return true; 
 }
