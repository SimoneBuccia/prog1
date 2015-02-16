#include "Vettore.h"

Vettore::Vettore(const int n) {
	size = (n>0) ? n : 1;
	
	ptr = new T[size];
	
	for(int i=0; i<size; i++) {
		ptr[i]=0;
	}
}

Vettore::Vettore(const Vettore & V) {
	size = V.size;
	
	ptr = new T[size];
	
	for(int i=0; i<size; i++) {
		ptr[i]=V[i];
	}
}

Vettore::~Vettore() {
	delete [] ptr;
}

int Vettore::getSize() const {
	return size;
}

const Vettore & Vettore::operator=(const Vettore & V) {
	
	if(this != &V) {
		if(size!=V.size) {
			size = V.size;
			delete [] ptr;
			ptr = new T[size];
		}
		for(int i=0; i<size; i++) {
			ptr[i]=V[i];
		}
	}
	
	return *this;
}


bool Vettore::operator==(const Vettore & V) const {
	if(this == &V) {
		return true;
	} else if (size!=V.size) {
		return false;
	} else {
		for(int i=0; i<size; i++) {
			if(ptr[i]!=V[i]) {
				return false;
			}
		}
		return true;
	}
	
}

bool Vettore::operator!=(const Vettore & V) const {
	return !(*this==V);
}

T Vettore::operator[](const int i) const {
	if(i<0||i>size) {
		exit(1);
	}
	return ptr[i];
}

T & Vettore::operator[](const int i) {
	if(i<0||i>size) {
		exit(1);
	}
	return ptr[i];
}

ostream & operator<<(ostream & os, const Vettore & V) {
	for(int i=0; i<V.size; i++) {
		os << V[i] << endl;
	}
	return os;
}

istream & operator>>(istream & in, Vettore & V) {
	for(int i=0; i<V.size; i++) {
		cout << "Inserisci elemento in posizione "<<i<<": ";
		in>>V[i];
	}
	return in;
}
