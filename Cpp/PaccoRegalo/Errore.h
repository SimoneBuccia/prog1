#ifndef _ERRORE_H_
#define _ERRORE_H_

#include "Vettore.h"

class Errore {
	private:
		string msg;
	public:
		Errore(string m = "Errore.") {
			msg = m;
		}
		
		const string what() const {
			return msg;
		}
};

#endif
