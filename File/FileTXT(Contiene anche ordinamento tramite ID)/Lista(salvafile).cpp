#include "Lista.h"


	void Lista::InsertAtFront(const T & l) throw(Errore) {
    if(this->InList(l.get_Codice())) throw Errore("Elemento Duplicato");
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
    void Lista::Salva_File(const char*s) const{
	ofstream fout (s, ios::out);
	Record* temp = testa;
	while(temp){
		fout << temp -> elem << '\n';
		temp = temp -> next;
	}
}	   
	bool Lista::Cancella(const char*s){
	Record* temp = testa;
	while(temp){
		if(strcmp(temp->elem.get_Codice(),s)==0){
			Record* temp0 = testa;
			while(temp0->next!=temp){
				temp0 = temp0 -> next;
			}
			temp0 -> next = temp -> next;
			delete temp;
			nelem--;
			return true;
		}
		temp = temp -> next;
	}
	return false;

	}
	bool Lista::InList(const char*  ID) const {
    bool trovato=false;
    Record * temp=testa;
    while(temp && !trovato)
      if(strcmp(temp->elem.get_Codice(),ID)==0)
        trovato=true;
      else temp=temp->next;
    return trovato;
    }
	Lista::~Lista(){
	Record * temp=testa;
   while(testa){
     temp=testa; 
     testa = testa->next;
     delete temp;}
     }
