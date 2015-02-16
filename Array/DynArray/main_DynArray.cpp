#include <iostream>
#include <stdlib.h>
#include "DynArray.h"

using namespace std;

int main(int argc, char *argv[])
{
  DynArray mydyn, mydyn1;
  T e;
  
  start(mydyn);
  start(mydyn1);
  initiate(mydyn,0);
  initiate(mydyn1,0);
  print(mydyn);
  cout << "\n";
  cout << "\n riempimento: " << get_size(mydyn) << endl;
  cout << "\n capacita': " << get_capacity(mydyn) << endl;
  
  pushback(mydyn,1);
  pushback(mydyn,2);
  pushback(mydyn,3);
  print(mydyn);
  cout << "\n";
  cout << "\n riempimento: " << get_size(mydyn) << endl;
  cout << "\n capacita': " << get_capacity(mydyn) << endl;
  pushback(mydyn,4);
  pushback(mydyn,5);
  pushback(mydyn,6);
  print(mydyn);
  cout << "\n";
  cout << "\n riempimento: " << get_size(mydyn) << endl;
  cout << "\n capacita': " << get_capacity(mydyn) << endl;
  popback(mydyn,e);
  cout << "\n valore estratto: " << e << endl;
  cout << "\n";
  cout << "\n riempimento: " << get_size(mydyn) << endl;
  cout << "\n capacita': " << get_capacity(mydyn) << endl;
  cout << "\n copio il vettore..." <<endl;
  copy(mydyn1, mydyn);
  cout << "\n vettore copiato:" <<endl;
  print(mydyn1);
  cout << "\n";
  cout << "\n riempimento: " << get_size(mydyn1) << endl;
  cout << "\n capacita': " << get_capacity(mydyn1) << endl;
  clear(mydyn);
  clear(mydyn1);
  cout << "\n";
  system("PAUSE");	
  return 0;
}
