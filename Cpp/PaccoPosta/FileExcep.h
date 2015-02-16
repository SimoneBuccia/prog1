#ifndef _FILEEXCEP_H_
#define _FILEEXCEP_H_

#include "Pacco.h"

class Ecc {
	private:
		string msg;
	public:
		Ecc(string m = "") {
			msg = m;
		}
		const string what() const {
			return msg;
		}
};

#endif
