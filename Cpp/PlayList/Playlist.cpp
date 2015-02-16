#include "Playlist.h"

void Playlist::ordina() {
	for(int i=0; i<nelem; i++) {
		for(int j=i+1; j<nelem-1; j++) {
			if (C[i].getDurata()>C[j].getDurata()){
	            Brano temp;
	            temp = C[j];
	            C[j]=C[i];
	            C[i]=temp;
	        }
		}
	}
	
}

float Playlist::play() {
	T e;
	if(mode==0) ordina();
	float d = 0.0;
	while(pop(e)) {
		show(e);
		d+e.getDurata();
	}
	return d;
}


void Playlist::show(const T & e) const {
	cout << "Eseguito: " << e << endl;
}
