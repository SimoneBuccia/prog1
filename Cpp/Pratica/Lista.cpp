#include "Lista.h"

Lista::Lista(const Lista & l) {
	testa = 0;
	Record * temp = l.testa;
	while(temp) {
		InsertAtBack(temp->elem);
		temp=temp->next;
	}
}

const Lista & Lista::operator=(const Lista & l) {
	if(this != &l) {
		if(testa) {
			clear();
		}
		if(l.testa) {
			testa = 0;
			Record * temp = l.testa;
			while(temp) {
				InsertAtBack(temp->elem);
				temp=temp->next;
			}
		}
	}
	return *this;
}

Lista::~Lista() {
	clear();
}
		
bool Lista::InsertAtFront(const T & e) {
	if(Full()) return false;
	Record * nodo;
	nodo = new Record;
	nodo->elem = e;
	nodo->next = testa;
	testa = nodo;
	return true;
}

bool Lista::InsertAtBack(const T & e) {
	if(Full()) return false;
	if(Empty()) {
		return InsertAtFront(e);
	}
	Record * nodo;
	Record * temp = testa;
	
	nodo = new Record;
	nodo->elem = e;
	nodo->next = 0;
	
	while(temp->next) {
		temp = temp->next;
	}
	temp->next = nodo;
	return true;
}

bool Lista::RemoveFromFront(T & e) {
	if(Empty()) return false;
	Record * temp = testa;
	e = testa->elem;
	testa = testa->next;
	delete temp;
	return true;
};

bool Lista::RemoveFromBack(T & e) {
	if(Empty()) return false;
	if(testa->next == 0) {
		return RemoveFromBack(e);
	} else {
		Record * temp = testa;
		Record * temp1;
		
		while(temp->next->next) {
			temp = temp->next;
		}
		
		temp1=temp->next;
		temp->next = 0;
		e = temp1->elem;
		delete temp1;
		return true;
	}
}

bool Lista::InList(const T & e) const {
	Record * temp = testa;
	bool trovato = false;
	
	while(temp && !trovato) {
		if(e == temp->elem) {
			trovato = true;
		} else {
			temp = temp->next;
		}
	}
	
	return trovato;
}

int Lista::Lenght() const {
	int count = 0;
	Record * temp = testa;
	
	while(temp) {
		count++;
		temp=temp->next;
	}
	return count;
}
  
bool Lista::Empty() const {
	return (testa == 0);
}

bool Lista::Full()  const {
	return false;
}

bool Lista::Print() const {
	if(Empty()) return false;
	Record * temp = testa;
	while(temp) {
		cout<<"\nElemento: "<<temp->elem;
		temp = temp->next;
	}
	return true;
}

void Lista::clear() {
	Record * temp;
	while(testa) {
		temp = testa; 
		testa = testa->next;
		delete temp;
	}
}
