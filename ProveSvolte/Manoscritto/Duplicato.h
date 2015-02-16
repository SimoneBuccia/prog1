#ifndef _DUPLICATO_H_
#define _DUPLICATO_H_

#include "Lettera.h"

class Duplicato {
	private:
		string msg;
	public:
		Duplicato(string m = "Errore.") {
			msg = m;
		}
		const string what() const {
			return msg;
		}
};
#endif
