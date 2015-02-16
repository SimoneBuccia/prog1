#include "BranoMusicale.h"
#include "Video.h"
#include "Coda.h"

int main(int argc, char** argv) {
	File F1("url1", 10, "form1"),
		F2("url2", 20, "form2"),
		F3("url3", 10, "form3"),
		F4=F1,
		F5;
	Brano B1("url1", 10, "form1", "br1", "in1", 10),
		B2("url2", 20, "form2", "br2", "in2", 10),
		B3("url3", 10, "form3", "br3", "in3", 10),
		B4=B1,
		B5;	
	Video V1("url1", 10, "form1", "au1", "so1", "da1"),
		V2("url2", 20, "form2", "au2", "so2", "da2"),
		V3("url3", 10, "form3", "au3", "so3", "da3"),
		V4=V1,
		V5;
		
	cout << F1 << '\n' << F2 << '\n' << F3 << '\n' << F4<< "\n\n\n";
	//cin >> F5;
	//cout << F5 << "\n\n\n";
	
	cout << B1 << '\n' << B2 << '\n' << B3 << '\n' << B4 << "\n\n\n";
	//cin >> B5;
	//cout << B5 << "\n\n\n";
	
	cout << V1 << '\n' << V2 << '\n' << V3 << '\n' << V4 << "\n\n\n";
	//cin >> V5;
	//cout << V5 << "\n\n\n";
	
	Coda C1;
	C1.append(&F1);
	C1.append(&B2);
	C1.append(&V3);
	C1.stampaCoda();
	
	ofstream file1;
	file1.open("./test.txt", ios::out);
	if(!file1) {
		cout << "Errore.";
	} else {
		C1.memorizzaDati(file1);
	}
	file1.close();
	
	cout << "\n\n\n";
	File * v[3];
	v[0] = &F1;
	v[1] = &B2;
	v[2] = &V3;
	
	for(int i =0 ; i < 3; i++) {
		v[i]->stampa();
		cout << "\n";
	}
	return 0;
}
