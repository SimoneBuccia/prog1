#ifndef _BADSTATUS_H_
#define _BADSTATUS_H_

#include "Autobus.h"

class BadStatus {
	private:
		string msg;
	public:
		BadStatus(string m = "") {
			msg = m;
		}
		const string errorLog() const {
			return msg;
		}
};
#endif
