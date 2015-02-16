#include "Oggetto.h"

Oggetto::Oggetto(const char * i, const char * t) {
	id = new char[strlen(i)+1];
	strcpy(id, i);
	tipo = new char[strlen(t)+1];
	strcpy(tipo, t);
}

Oggetto::Oggetto(const Oggetto & o) {
	id = new char[strlen(o.id)+1];
	strcpy(id, o.id);
	tipo = new char[strlen(o.tipo)+1];
	strcpy(tipo, o.tipo);
}

const Oggetto & Oggetto::operator=(const Oggetto & o) {
	if(this!=&o) {
		if(id) delete [] id;
		id = new char[strlen(o.id)+1];
		strcpy(id, o.id);
		if(tipo) delete [] tipo;
		tipo = new char[strlen(o.tipo)+1];
		strcpy(tipo, o.tipo);
	}
	return *this;
}
	
const char * Oggetto::getId() const {
	return id;
}

void Oggetto::setId(const char * i) {
	if(id) delete [] id;
	id = new char[strlen(i)+1];
	strcpy(id, i);
}

const char * Oggetto::getTipo() const {
	return tipo;
}
void Oggetto::setTipo(const char * t) {
	if(tipo) delete [] tipo;
	tipo = new char[strlen(t)+1];
	strcpy(tipo, t);
}

ostream & operator<<(ostream & out, const Oggetto & o) {
	out << o.getId() <<' '<< o.getTipo();
	return out;
}

istream & operator>>(istream & in, Oggetto & o) {
	char temp[100];
	cout<<"\nId -> ";
	in.getline(temp,100);
	o.setId(temp);
	cout<<"Tipo -> ";
	in.getline(temp,100);
	o.setTipo(temp);
	return in;
}
