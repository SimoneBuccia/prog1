#include "Fotografia.h"

Fotografia::Fotografia(const char * t, const char * f) {
	Titolo = new char[strlen(t)+1];
	strcpy(Titolo,t);
	Formato = new char[strlen(f)+1];
	strcpy(Formato, f);
}

Fotografia::Fotografia(const Fotografia & f) {
	Titolo = new char[strlen(f.Titolo)+1];
	strcpy(Titolo,f.Titolo);
	Formato = new char[strlen(f.Formato)+1];
	strcpy(Formato, f.Formato);
} 

Fotografia::~Fotografia() {
	delete [] Titolo;
	delete [] Formato;
}

const Fotografia & Fotografia::operator=(const Fotografia & f) {
	if(this!=&f) {
		if(Titolo) delete [] Titolo;
		Titolo = new char[strlen(f.Titolo)+1];
		strcpy(Titolo,f.Titolo);
		if(Formato) delete [] Formato;
		Formato = new char[strlen(f.Formato)+1];
		strcpy(Formato, f.Formato);
	}
	return *this;
}

const char * Fotografia::getTitolo() const {
	return Titolo;
}

void Fotografia::setTitolo(const char * t) {
	if(Titolo) delete [] Titolo;
	Titolo = new char[strlen(t)+1];
	strcpy(Titolo,t);
}

const char * Fotografia::getFormato() const {
 	return Formato;
}

void Fotografia::setFormato(const char * f) {
	if(Formato) delete [] Formato;
	Formato = new char[strlen(f)+1];
	strcpy(Formato, f);
}	

ostream & operator<<(ostream & out, const Fotografia & f) {
	out << f.getTitolo() << ' ' << f.getFormato();
	return out;
}

istream & operator>>(istream & in, Fotografia & f) {
	char temp[100];
	cout<<"\nTitolo-> ";
	cin.getline(temp,100);
	f.setTitolo(temp);
	cout<<"Formato-> ";
	cin.getline(temp, 100);
	f.setFormato(temp);
	return in;
}

ofstream & operator<<(ofstream & ofs, const Fotografia & f) {
	int size = strlen(f.getTitolo());
	ofs.write((const char *)(&size), sizeof(int));
	ofs.write(f.getTitolo(), size*sizeof(char));
	
	size = strlen(f.getTitolo());
	ofs.write((const char *)(&size), sizeof(int));
	ofs.write(f.getFormato(), size*sizeof(char));
	return ofs;
}

ifstream & operator>>(ifstream & ifs, Fotografia & f) {
	int size = 0;
	
	ifs.read((char *)(&size), sizeof(int));
	char * bufferT = new char[size];
	ifs.read(bufferT, size*sizeof(char));
	bufferT[size]='\0';
	f.setTitolo(bufferT);
	
	
	ifs.read((char *)(&size), sizeof(int));
	char * bufferF = new char[size];
	ifs.read(bufferF, size*sizeof(char));
	bufferF[size]='\0';
	f.setFormato(bufferF);
	
	return ifs;
}
	
	
	
