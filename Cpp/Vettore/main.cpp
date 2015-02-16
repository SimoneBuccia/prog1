#include "Vettore.h"

using namespace std;

int main(int argc, char *argv[])
{
  // Programma di test tratto dal libro di testo:
  
  Vettore integers1( 7 ); // array di 7 elementi
  Vettore integers2; // array di 10 elementi (per default)
  
 // visualizza dimensione e contenuto di integers1
 cout << "Size of Array integers1 is"
 << integers1.getSize()
 << "\nArray after initialization:\n" << integers1;

 // visualizza dimensione e contenuto di integers2
 cout << "\nSize of Array integers2 is "
 << integers2.getSize()
 << "\nArray after initialization:\n" << integers2;

 // inserisce i valori di integers1 e integers2 e li visualizza
 cout << "\nEnter 17 integers:" << endl;
 cin >> integers1 >> integers2;

 cout << "\nAfter input, the Arrays contain:\n"
 << "integers1:\n" << integers1
 << "integers2:\n" << integers2;

 // utilizza la ridefinizione dell’operatore di disuguaglianza
 cout << "\nEvaluating: integers1 != integers2" << endl;

 if ( integers1 != integers2 )
 cout << "integers1 and integers2 are not equal" << endl;

 // crea l’array integers3 utilizzando integers1 come
 // inizializzatore; visualizza dimensione e contenuto
 Vettore integers3( integers1 ); // chiama il costruttore di copia

 cout << "\nSize of Array integers3 is "
 << integers3.getSize()
 << "\nArray after initialization:\n" << integers3;

 // utilizza la ridefinizione dell’operatore di assegnamento
 cout << "\nAssigning integers2 to integers1:" << endl;
 integers1 = integers2; // il primo array è più piccolo

 cout << "integers1:\n" << integers1
 << "integers2:\n" << integers2;

 // utilizza la ridefinizione dell’operatore di uguaglianza
cout << "\nEvaluating: integers1 == integers2" << endl;

 if ( integers1 == integers2 )
 cout << "integers1 and integers2 are equal" << endl;

 // utilizza l’operatore di indicizzazione ridefinito per creare un rvalue
 cout << "\nintegers1[5] is " << integers1[5];	
 
 // utilizza l’operatore di indicizzazione ridefinito per creare un lvalue
 cout << "\n\nAssigning 1000 to integers1[5]" << endl;
 integers1[5] = 1000;
 cout << "integers1:\n" << integers1;

 // tentativo di fornire un indice fuori intervallo
  cout << "\nAttempt to assign 1000 to integers1[15]" << endl;
  integers1[15] = 1000; // ERRORE: indice fuori intervallo
	
  /*  prova effettuata alle fine della lezione
    
	Vettore V(4), V2(-3);
    Vettore V1;
    cout << V << endl;
    cout << V2 << endl;
    cout << "inserire gli elementi del vettore: " << endl;
    cin >> V;
    cout << V;
    V1=V;
    cout << "vettore V1: " << endl;
    cout << V1; 
	*/
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
