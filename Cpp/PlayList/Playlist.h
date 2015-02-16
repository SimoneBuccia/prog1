#ifndef _PLAYLIST_
#define _PLAYLIST_

#include "Coda.h"

class Playlist: public Coda {
	private:
		int mode;
		void ordina();
		void show(const T &) const;
	public:
		Playlist(const int dim = 10, const int m = 0) : Coda(dim) {
			mode = m;
		}
		int getMode() const {
			return mode;
		}
		void setMode(const int m) {
			mode = m;
		}
		
		float play();
};


#endif
