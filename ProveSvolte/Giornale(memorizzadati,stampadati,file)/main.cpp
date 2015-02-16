#include <iostream>
#include "Pila.h"
#include "Rivista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
Giornale G;
Giornale G1(1.1,"TITOLO1",true);
Giornale G2(2.2,"TITOLO2",false);
Giornale G3(3.3,"TITOLO3",true);
Giornale G4(4.4,"TITOLO4",false);
Giornale G5=G4;
Giornale G6;
/*
cout<<G1<<endl<<G2<<endl<<G3<<endl<<G4<<endl<<G5<<endl;
cout<<"\n\n";
cin>>G6;

cout<<G6;

*/

Rivista R;
Rivista R1(1.1,"TITOLO1",true,"EDITORE1","PERIODICO1");
Rivista R2(2.2,"TITOLO2",false,"EDITORE2","PERIODICO2");
Rivista R3(3.3,"TITOLO3",true,"EDITORE3","PERIODICO3");
Rivista R4(4.4,"TITOLO4",false,"EDITORE4","PERIODICO4");
Rivista R5=R4;
Rivista R6;
/*
cout<<R1<<endl<<R2<<endl<<R3<<endl<<R4<<endl<<R5<<endl;
cout<<"\n\n";
cin>>R6;

cout<<R6;
*/

Quotidiano Q;
Quotidiano Q1(1.1,"TITOLO1",true,"DIRETTORE1",true);
Quotidiano Q2(2.2,"TITOLO2",false,"DIRETTORE2",false);
Quotidiano Q3(3.3,"TITOLO3",true,"DIRETTORE3",true);
Quotidiano Q4(4.4,"TITOLO4",false,"DIRETTORE4",false);
Quotidiano Q5=Q4;
Quotidiano Q6;
/*
cout<<Q1<<endl<<Q2<<endl<<Q3<<endl<<Q4<<endl<<Q5<<endl;
cout<<"\n\n";
cin>>Q6;

cout<<Q6;
*/

Giornale * vet[5];

vet[0]=&G1;
vet[1]=&R1;
vet[2]=&Q1;
vet[3]=&G2;
vet[4]=&R2;

for(int i=0;i<5;i++)
cout<<*vet[i]<<"\n";


Pila P;
Pila P1;
for(int i=0;i<5;i++){
P.push(vet[i]);
}
cout<<P<<"\n";

/*-------------------------------*/

  ofstream myfile;
  myfile.open("./prova.txt", ios::out);
  if(!myfile) {cout << "operazione non riuscita!!!!" << endl;
  }else {
    myfile << P;
    }
	myfile.close();	

/*------------------*/
try{
P.push(&Q6);
}
catch(Errore E){
cout<<E.what()<<endl;
}





	return 0;
}
