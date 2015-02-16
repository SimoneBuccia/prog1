#ifndef _ERRORE_H_
#define _ERRORE_H_

#include <cstring>
#include <iostream>

using namespace std;

class Errore {
	private:
		char * msg;
	public:
		Errore(const char * err = "") {
			msg = new char[strlen(err)+1];
			strcpy(msg, err);
		} 
		~Errore() {
			delete [] msg;
		}
		const char * what() const {return msg;}
};

#endif
