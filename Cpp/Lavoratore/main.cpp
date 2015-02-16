#include <iostream>
#include <stdlib.h>
#include "Operaio.h"
#include "Pila.h"

using namespace std;


int main (){

  Lavoratore L1("mmmaaa", "ibm", 4, 600);
  Lavoratore L2("bbbaaa", "sony", 7, 700);
  Lavoratore L3("cccvvv", "ansaldo", 3, 400);
  Operaio O1("o1o1o1o", "ibm", 8, 600, "sistemista", 40);
  Operaio O2("o2o2o2o", "selex", 9, 500, "sistemista", 40);

  Lavoratore * v[5];
  
  v[0]=&L1;
  v[1]=&L2;
  v[2]=&L3;
  v[3]=&O1;
  v[4]=&O2;
  
  for(int i=0; i<5; i++) {
      cout << v[i]->getMatricola() << ":" << v[i]->calcolaStipendio() << endl;
  }
  
  cout << "\nO3\n";
  Pila P;
  
  Operaio O3 = O2;
  cout << O3.getMatricola() << ":" << O3.calcolaStipendio()<<endl;

  P.push(O1);
  P.push(O2);
  
  
  cout << "\nPila\n";
  cout << P << endl;
  
  cout << "\nEstrai\n";
  P.pop(O3); 
  cout << "estratto: " << O3 << endl;
  P.pop(O3); 
  cout << "estratto: " << O3 << endl;
  
  cout << "\nErrore\n";
  try {
  	P.pop(O3); 
	cout << "estratto: " << O3 << endl;
  }  catch(Errore e){
      cout << e.what() << endl;
  }
  cout<< endl;
  system("PAUSE");
  return 0;
}
