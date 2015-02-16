#ifndef _SPACEOVERFLOW_H_
#define _SPACEOVERFLOW_H_

#include "Quotidiano.h"
 
class SpaceOverflow {
	private:
		string msg;
		
	public:
		SpaceOverflow(const string m = "Errore.") {
			msg = m;
		}
		
		const string errorLog() const {
			return msg;
		}
};

#endif
