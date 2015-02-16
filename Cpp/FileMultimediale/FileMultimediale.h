#ifndef _FILEMULTIMEDIALE_H_
#define _FILEMULTIMEDIALE_H_

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class File {
	friend ostream & operator<<(ostream &, const File &);
	friend istream & operator>>(istream &, File &);
	
	protected:
		char * URL;
		int Kb;
		char * Form;
		
	public:
		File(const char * = "", int = 0, const char * = "");
		File(const File &);
		virtual ~File();
		const File & operator=(const File &);
		
		const char * getURL() const;
		void setURL(const char *);
		const int getKb() const;
		void setKb(const int);
		const char * getForm() const;
		void setForm(const char *);
		
		virtual void stampa() const;
		virtual void memorizza(ostream &) const;
};

#endif
