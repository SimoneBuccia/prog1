#include "Fotografia.h"
#include "Coda.h"

int main(int argc, char *argv[]) {

Fotografia a("ARMANDO","aaa");
Fotografia b("BBB","bbb");
Fotografia c("CCC","ccc");
Fotografia d("DDD","ddd");
Fotografia e("EEE","eee");
Fotografia f("FFF","fff");
Fotografia g("GGG","ggg");
Fotografia h("HHH","hhh");
Fotografia i=a;
Fotografia L,H;

cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f<<endl<<g<<endl<<h<<endl;
cout<<i;


cout<<endl<<"Scrivo "<<endl;
ofstream out("./Prova.bin",ios::binary|ios::out);
out<<b<<c;    
out.close();


ifstream in("./Prova.bin",ios::binary|ios::in);
cout<<endl<<"Leggo "<<endl;
in>>L; 
in>>H;
in.close();
cout<<L<<"\n";   
cout<<H<<"\n";

cout<<endl<<"Coda da file "<<endl;
Coda c1("./Prova.bin"), c2;
c1.stampa();

cout<<endl<<"Errore "<<endl;
try {
	c2.pop(H);
} catch(Errore e) {
	cout<<e.what();
}
return 0;

}
