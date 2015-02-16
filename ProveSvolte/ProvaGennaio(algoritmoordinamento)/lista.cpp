#include "Lista.h"


	void Lista::InsertAtFront(const T & l) throw(MyError) {
    if(this->InList(l.get_ID())) throw MyError("elemento id duplicato");
	Record * p;
    p=new Record;
    p->elem=l;
    p->next=testa;
    testa=p;
	}
    void Lista::Print() const{
     Record * temp= testa;
     while(temp) {
       cout << temp->elem << "\n";
       temp=temp->next;
     }      
   }   
    Lista::~Lista(){
	Record * temp=testa;
   while(testa){
     temp=testa; 
     testa = testa->next;
     delete temp;}
     }
     
    bool Lista::InList(const char*  ID) const {
    bool trovato=false;
    Record * temp=testa;
    while(temp && !trovato)
      if(strcmp(temp->elem.get_ID(),ID)==0)
        trovato=true;
      else temp=temp->next;
    return trovato;
    }
