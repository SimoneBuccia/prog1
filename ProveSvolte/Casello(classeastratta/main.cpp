#include "Coda.h"

int main(int argc, char** argv) {
	const int TARIFFA = 2;
	
	Autovettura A1("bj066mx", "benzina", "suv", 6);
	Autovettura A2("kt887gg", "gpl", "monovolume", 5);
	Autovettura A3("dh572xc", "metano", "berlina", 5);
	Autovettura A4("mq111nd", "diesel", "utilitaria", 4);
	Autobus A5("cc789oi", "benzina", "bus", 50, "Milano", 200);
	Autobus A6("st230ks", "gpl", "bus", 50, "Roma", 300);
	Autobus A7("vv234sd", "metano", "bus", 25, "Napoli", 100);
	Autobus A8("we785ss", "diesel", "bus", 60, "Parma", 400);
	
	Autoveicolo * v[8];
	v[0] = &A1;
	v[1] = &A2;
	v[2] = &A3;
	v[3] = &A4;
	v[4] = &A5;
	v[5] = &A6;
	v[6] = &A7;
	v[7] = &A8;
	
	cout<<"Polimorfismo:\n";
	for(int i=0; i<8; i++) {
		v[i]->stampaDati();
		cout << "\n";
	}
	
	
	Coda C1, C2, C3;
	C1.append(&A1);
	C1.append(&A2);
	C1.append(&A3);
	C1.append(&A4);
	C1.append(&A5);
	C1.append(&A6);
	C1.append(&A7);
	C1.append(&A8);
	
	C2.append(&A1);
	C2.append(&A2);
	C2.append(&A3);
	C2.append(&A4);
	C2.append(&A5);
	C2.append(&A6);
	C2.append(&A7);
	
	C3.append(&A1);
	C3.append(&A2);
	C3.append(&A3);
	C3.append(&A4);
	C3.append(&A5);
	C3.append(&A6);
	
	
	
	cout<<"\n\n\nCoda1:\n";
	cout<<C1;
	cout<<"\n\n\nCoda2:\n";
	cout<<C2;
	cout<<"\n\n\nCoda3:\n";
	cout<<C3;
	cout<<"\n\n\n";
	
	int e1, e2, e3;
	e1 = C1.getNelem();
	e2 = C2.getNelem();
	e3 = C3.getNelem();
	
	for(int i = 0; i<e1; i++) {
		Autoveicolo * elem;
		C1.pop(elem, TARIFFA); 
		cout<<"Elemento rimosso -> ";
		elem->stampaDati();
		cout<<endl;
	}
	cout<<"\n\n\n";
	for(int i = 0; i<e2; i++) {
		Autoveicolo * elem;
		C2.pop(elem, TARIFFA); 
		cout<<"Elemento rimosso -> ";
		elem->stampaDati();
		cout<<endl;
	}
	cout<<"\n\n\n";
	for(int i = 0; i<e3; i++) {
		Autoveicolo * elem;
		C3.pop(elem, TARIFFA); 
		cout<<"Elemento rimosso -> ";
		elem->stampaDati();
		cout<<endl;
	}
	if(C1.getIncasso()>100) {
		cout<<"\n\n\nIncasso totale: "<<C1.getIncasso()<< " bombe!";
	} else {
		cout<<"\n\n\nIncasso totale: "<<C1.getIncasso()<<" frecce!";
	}
	
	return 0;
}
