#include <iostream>
#include <stdlib.h>
#include "ListaT.h"
using namespace std;

int main(int argc, char *argv[])
{
  Lista L;
  T E;
  
  L.InsertAtBack(3);
  L.InsertAtFront(4);
  cout << "Lista: ";
  L.Print();
  L.InsertAtBack(2);
  L.InsertAtBack(1);
  cout << "\n";
  cout << "Lista: ";
  L.Print();
   
  L.RemoveFromBack(E);
  cout << "Eliminato: " << E << endl;
  cout << "Lista: ";
  L.Print();
  cout << "\n";
  L.InsertAtBack(-7);
  L.InsertAtFront(0);
  cout << "Lista: ";
  L.Print();
  cout << "\n";
  cout << "Lista: ";
  L.Print();
  cout << "\n";
  if(L.InList(-7)) cout << "elemento presente!" << endl;
  else cout << "elemento non presente" << endl;
  if(L.InList(10)) cout << "elemento presente!" << endl;
  else cout << "elemento non presente" << endl;
  cout << "numero di elementi in lista: " << L.Lenght() << endl;
  cout << "\n";
  L.RemoveFromBack(E);
  L.RemoveFromBack(E);
  L.RemoveFromBack(E);
  L.RemoveFromBack(E);
  L.RemoveFromBack(E);
  if(!L.RemoveFromBack(E)) cout << "lista vuota!" << endl;
  
  L.InsertAtBack(9);
  L.InsertAtFront(8);
  L.InsertAtBack(10);
  L.InsertAtFront(7);
  cout << "Lista: ";
  L.Print();
  cout << "\n";
  L.RemoveFromFront(E);
  L.RemoveFromFront(E);
  L.RemoveFromFront(E);
  L.RemoveFromFront(E);
  if(!L.RemoveFromFront(E)) cout << "lista vuota!" << endl;

  L.InsertAtFront(-2);
  L.InsertAtBack(-3);
  L.InsertAtFront(-1);
  L.InsertAtBack(-4);
  L.Print();
  cout << "\n";
  L.RemoveFromFront(E);
  L.RemoveFromBack(E);
  L.RemoveFromFront(E);
  L.RemoveFromBack(E);
  if(!L.RemoveFromBack(E)) cout << "lista vuota!" << endl;
  system("PAUSE");	
  return 0;
}
