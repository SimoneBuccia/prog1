#include "Lista.h"

Lista::~Lista(){
	R * temp = testa;
	while(testa) {
		testa = testa->next;
		delete temp;
	}
}

void Lista::push(const T & e) {
	R * temp;
	temp = new R;
	temp->elem = e;
	temp->next = testa;
	testa = temp;
}
		
void Lista::inserisci(const T & e) throw(MyError) {
	if(empty()) {
		push(e);
	} else {
		if(ricerca(e.getId())) throw MyError("\nElemento gia' presente.\n");
		R * succ = testa;
		R * prec = testa;
		bool stop = false;
		
		while(!stop&&succ) {
			if(strcmp(e.getId(), succ->elem.getId())==1) {
				prec = succ;
				succ = succ->next;
			} else {
				stop = true;
			}
		} 
		
		if(prec==succ) {
			push(e);
		} else {
			R * temp;
			temp = new R;
			temp->elem = e;
			temp->next = succ;
			prec->next = temp;
		}
	}
}

void Lista::stampa() const {
	R * temp = testa;
	while(temp) {
		cout << temp->elem << "\n";
		temp = temp->next;
	}
}

bool Lista::ricerca(const char * id) const {
	bool trovato=false;
	R * temp = testa;
	while(temp&&!trovato) {
		if(strcmp(temp->elem.getId(),id)==0) {
			trovato = true;
		}
		temp=temp->next;
	}
	if(trovato) {
		return true;
	} else {
		return false;
	}
}




