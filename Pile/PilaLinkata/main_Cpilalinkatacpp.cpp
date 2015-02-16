#include <cstdlib>
#include <iostream>
#include "Cpilalinkata.h"

using namespace std;


int main(int argc, char *argv[])
{
    Pila P1;
    
    T elem;
    
    cout << "\nEffettuo tre inserimenti in pila...";
    if (!P1.full()) P1.push(1);
    else cout << "\npila piena!";
    if (!P1.full()) P1.push(2);
    else cout << "\npila piena!";
    if (!P1.full()) P1.push(3);
    else cout << "\npila piena!";
    
    cout << "\nstato attuale della pila: " <<endl;
    cout << P1;
    
    if(!P1.empty()){
       P1.pop(elem);
       cout << "\nelemento estratto: " << elem;
    }
    else cout << "\npila vuota!";
    
    cout << "\nstato attuale della pila: "<< endl;
    cout << P1;
    
    P1.top(elem);
    cout << "\nelemento affiorante: " << elem;
   
    
    
    if(!P1.empty()){
       P1.pop(elem);
       cout << "\nelemento estratto: " << elem;
    }
    else cout << "\npila vuota!";
    
    if(!P1.empty()){
       P1.pop(elem);
       cout << "\nelemento estratto: " << elem;
    }
    else cout << "\npila vuota!";
    
    if(!P1.empty()){
       P1.pop(elem);
       cout << "\nelemento estratto: " << elem;
    }
    else cout << "\npila vuota!";
    
    cout << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
