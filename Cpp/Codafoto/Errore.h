#ifndef _ERRORE_H_
#define _ERRORE_H_

#include <iostream>
#include <cstring>

class Errore {
	private:
		char * msg;
	public:
		Errore(const char * m = "") {
			msg = new char[strlen(m)+1];
			strcpy(msg, m);
		}
		~Errore() {
			delete [] msg;
		}
		const char * what() const {
			return msg;
		}
};
#endif
