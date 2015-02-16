#include <iostream>
#include <fstream>

#include "Vettore.h"

int main(int argc, char** argv) {
	Pacco P1("aaa", 22.22, "aaa"),
		P2("bbb", 33.33, "bbb"),
		P3("ccc", 501, "ccc"),
		P4("ddd", 300, "ddd"),
		P5=P1,
		P6;
		
	cout<<P1<<'\n'<<P2<<'\n'<<P3<<'\n'<<P4<<'\n'<<P5<<'\n';
	P5=P2;
	cout<<P2<<'\n';
	Vettore V(1);
	V[0] = P1;
	cout<<"\n"<< V[0];
	cout<<"\n"<< V.Access(0);
	
	try {
		cout<<"\n"<<V.Access(20);
	} catch (Errore e) {
		cout<<"\n"<<e.what();
	}
	
	cin >> P6;
	cout<<P6<<'\n';
	
	
	ofstream file;
	char temp[100];
	cin.ignore();
	cin.getline(temp,100);
	
	file.open(temp);
	
	if(!file) {
		cout<<"Errore file!";
	} else {
		file<<P1;
	}
	
	
	
	
	
}
