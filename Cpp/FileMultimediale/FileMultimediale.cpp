#include "FileMultimediale.h"

File::File(const char * u, int k, const char * f) {
	URL = new char[strlen(u)+1];
	strcpy(URL,u);
	Kb = k;
	Form = new char[strlen(f)+1];
	strcpy(Form, f);
}

File::File(const File & f) {
	URL = new char[strlen(f.URL)+1];
	strcpy(URL,f.URL);
	Kb = f.Kb;
	Form = new char[strlen(f.Form)+1];
	strcpy(Form, f.Form);
}

File::~File() {
	delete [] URL;
	delete [] Form;
}

const File & File::operator=(const File & f) {
	if(this!=&f) {
		if(URL) delete [] URL;
		URL = new char[strlen(f.URL)+1];
		strcpy(URL,f.URL);
		Kb = f.Kb;
		if(Form) delete [] Form;
		Form = new char[strlen(f.Form)+1];
		strcpy(Form, f.Form);
	}
	return *this;
}

const char * File::getURL() const {
	return URL;
}

void File::setURL(const char * u) {
	if(URL) delete [] URL;
	URL = new char[strlen(u)+1];
	strcpy(URL,u);
}

const int File::getKb() const {
	return Kb;
}

void File::setKb(const int k) {
	Kb = k;
}

const char * File::getForm() const {
	return Form;
}

void File::setForm(const char * f) {
	if(Form) delete [] Form;
	Form = new char[strlen(f)+1];
	strcpy(Form, f);
}

ostream & operator<<(ostream & out, const File & f) {
	out << f.getURL() << ' ' << f.getKb() << ' ' << f.getForm() << ' ';
	return out;
}

istream & operator>>(istream & in, File & f) {
	char tempU[100], tempF[100];
	in >> tempU >> f.Kb >> tempF;
	f.setURL(tempU);
	f.setForm(tempF);
	return in;
}

void File::stampa() const {
	cout<<*this;
}

void File::memorizza(ostream & ofs) const {
	ofs << *this;
}
