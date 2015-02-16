#ifndef _ECCEZIONE_H_
#define _ECCEZIONE_H_

#include <iostream>
#include <cstring>

class MyError {
	private:
		char * msg;
	public:
		MyError(const char * m = "") {
			msg = new char[strlen(m)+1];
			strcpy(msg, m);
		}
		~MyError() {
			delete [] msg;
		}
		
		const char * what() const {
			return msg;
		}
};

#endif
