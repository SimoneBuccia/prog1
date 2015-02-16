#include <cstdlib>
#include <iostream>
#include "pilavetclasse.h"

using namespace std;
//#include "fiore.h"

int main(int argc, char *argv[])
{
    Pila P1;
    T elem;

    cout << "\ninserisco piu' elementi di quanti la pila possa contenere.";
    if (!P1.full()) P1.push(1);
    else cout << "\npila piena!";
    if (!P1.full()) P1.push(2);
    else cout << "\npila piena!";
    if (!P1.full()) P1.push(4);
    else cout << "\npila piena!";
    
    cout << "\nstampo la pila";
    cout << P1 <<endl;
    
    cout << "\nestraggo l' elemento di testa";
    if(!P1.empty()) P1.pop(elem);
    else cout << "\npila vuota!";
    
    
    cout << "\nstampo la pila";
    cout << P1 << endl;
    
    P1.top(elem);
    cout << "\nelemento affiorante: " << elem << endl;
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
