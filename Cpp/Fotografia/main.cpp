#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Pila.h"

using namespace std;

int main(int argc, char *argv[])
{
  Immagine I1("ME", "800x120"); 
  Immagine I2("ME", "600x120");	
  Fotografia F1("ME", "200x120", 1,"Monti");
  Fotografia F2("ME", "600x120", 2,"Mare");
  Fotografia F3("ME", "200x1800", 3,"Laura");
  Fotografia F4("ME", "100x1800", 4,"Cielo stellato");
  Fotografia F;
 // esempio di polimorfismo
 //*************************************************
  Immagine * vet[5];
  vet[0]=&I1;
  vet[1]=&F1;
  vet[2]=&F2;
  vet[3]=&I2;
  vet[4]=&F3;
  cout << "chiamata alla funzione virtuale (print):" << endl; 
  for(int i=0; i<5; i++){
	vet[i]->print();       //binding dinamico
    cout << "\n ";
  }
  cout << "\n ";
  system("PAUSE");  
//*************************************************
 
// test della pila
//**************************************************  
  Pila P;
  
// test funzione push
  cout << "\n\n\ninserimento:" << endl; 
  if(P.push(F1)) cout << "inserimento riuscito"<< endl;
  else cout << "Pila piena"<< endl;
  if(P.push(F2)) cout << "inserimento riuscito"<< endl;
  else cout << "Pila piena"<< endl;
  if(P.push(F3)) cout << "inserimento riuscito"<< endl;
  else cout << "Pila piena"<< endl;
  if(P.push(F4)) cout << "inserimento riuscito"<< endl;
  else cout << "Pila piena"<< endl;
  
 // test funzioni visualizza, top e empty
  cout << "contenuto della pila:" << endl;
  if(!P.empty()) cout<<P;
  else cout << "Pila vuota!"<< endl;
  
  if(!P.empty())  { 
    P.top(F);
    cout << "elemento di testa:" << F.getChiave() << " - " << F.getSoggetto() << endl;
    }    
   else cout << "Pila vuota!"<< endl;
   
 system("PAUSE");   
 
 // test funzioni sposta, ricerca, swap. Gestione dell'eccezione.   
  
  cout << "\n\n\nsposto in testa l'elemento di chiave 1:" << endl; 
  
  P.sposta_in_testa(1);
    
  cout << "contenuto della pila:" << endl;
  if(!P.empty()) cout<<P;
  else cout << "Pila vuota!"<< endl;
  
 system("PAUSE");  
 
   // test funzione pop
  cout << "\n\n\neliminazione:" << endl; 
  if(P.pop(F)) cout << "eliminazione riuscita"<< endl;
  else cout << "Pila vuota"<< endl;
  cout << "contenuto della pila:" << endl;
  if(!P.empty()) cout <<P;
  else cout << "Pila vuota!"<< endl;
  
 system("PAUSE");  
 
  // test STAMPA su file
  cout << "\n\n\nstampo il contenuto della pila su file di testo." << endl;
  ofstream myfile;
  char nomefile[30];
  
  cout << "inserire il nome del file: ";
  cin.getline(nomefile,30);
  myfile.open(nomefile, ios::out);
  if(!myfile) cout << "operazione non riuscita!!!!" << endl;
  else {
    myfile << P;
	myfile.close();	
  }
  
 system("PAUSE"); 
  
 // test LETTURA da  file
  Pila mypila2;
  ifstream myfile2;
  char nomefile2[30];
  
  cout << "\n\n\ninserire il nome del file: ";
  cin.getline(nomefile2,30);
  myfile2.open(nomefile2, ios::in);
  if(!myfile2) cout << "operazione non riuscita!!!!" << endl;
  else {
    myfile2>>mypila2;
	myfile2.close();	
  }
  cout << "stampo il contenuto della pila letta da file di testo." << endl;
  cout << mypila2 << endl;
  
   system("PAUSE"); 
  
  cout << "\n\n\nsvuoto la pila." << endl;
  
  if(P.pop(F)) cout << "eliminazione riuscita"<< endl;
  else cout << "Pila vuota"<< endl;
  
  if(P.pop(F)) cout << "eliminazione riuscita"<< endl;
  else cout << "Pila vuota"<< endl;
  
  if(P.pop(F)) cout << "eliminazione riuscita"<< endl;
  else cout << "Pila vuota"<< endl;
  
   if(P.pop(F)) cout << "eliminazione riuscita"<< endl;
  else cout << "Pila vuota"<< endl;
  
  system("PAUSE");	
  return 0;
}
