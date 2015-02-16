/*
Studente: VALENTE MAURO
Matricola: 043/000199
Docente: Casola

Università di Napoli Federico II
Corso di Laurea in Ingegneria Informatica

 - Esame di Programmazione 1- 9 CFU
Prova pratica del 16 dicembre 2014
Durata della prova: 2h


Cognome Valente Nome Mauro Matr. N43/199


Testo della prova
Si realizzi in C++ una gerarchia Lavoratore-Operaio. 
La classe Lavoratore contiene le seguenti variabili membro:
-	Matricola, codice identificativo del lavoratore (stringa allocata dinamicamente)
-	Azienda, azienda presso cui lavora (stringa allocata dinamicamente)
La classe Operaio aggiunge la variabile membro:
-	Settore, settore di specializzazione, ad esempio: tessile, edilizia, autovetture, etc (stringa di caratteri 
allocata dinamicamente)

Le classi devono gestire correttamente l'estensione dinamica fornendo le opportune funzionalità. Devono inoltre 
fornire le funzioni di accesso e posizionamento e l'overloading degli operatori di flusso << e >>.

Si realizzi quindi una classe PILA, rappresentata mediante un vettore allocato dinamicamente . La pila 
prevede, oltre alle classiche funzionalità, anche le funzionalità necessarie ad una corretta gestione dell'estensione 
dinamica. La classe Pila deve consentire all'utente di utilizzare in maniera polimorfa le funzioni di accesso (get) 
definite nella gerarchia quando applicate ad uno degli elementi estratti dalla pila.
Il programma di test deve effettuare il test della gerarchia e della struttura dati mostrando anche che è possibile 
l'assegnazione di due pile e la inizializzazione di una pila con una pila già esistente. La funzione che estrai elementi 
dalla pila lancia una eccezione di tipo Errore (definita dallo studente) nel caso si tenti di estrarre da una pila vuota. 
Si strutturi il codice secondo le appropriate tecniche di programmazione modulare illustrate durante il corso e nei 
libri di testo adottati.

*/


#include <iostream>
#include <stdlib.h>
#include "operaio.h"
#include "Cpilalinkata.h"

using namespace std;


int main (){

  lavoratore L1("mmmaaa", "ibm", 4, 600);
  lavoratore L2("bbbaaa", "sony", 7, 700);
  lavoratore L3("cccvvv", "ansaldo", 3, 400);
  operaio O1("o1o1o1o", "ibm", 8, 600, "sistemista", 40);
  operaio O2 ("o2o2o2o", "selex", 9, 500, "sistemista", 40);

  lavoratore * v[5];
  
  v[0]=&L1;
  v[1]=&L2;
  v[2]=&L3;
  v[3]=&O1;
  v[4]=&O1;
  
  for(int i=0; i<5; i++) {
      cout << v[i]->getMatr() << ":" << v[i]->calcolaStipendio() << endl;
  }
  
  Pila P;
  operaio O3;
  P.push(O1);
  P.push(O2);
  cout << P << endl;
  
  P.pop(O3); cout << "estratto: " << O3 << endl;
  P.pop(O3); cout << "estratto: " << O3 << endl;
  
  try {
  P.pop(O3); cout << "estratto: " << O3 << endl;
  }  
  catch(errore e){
      cout << e.what() << endl;
  }
  
  cout<< endl;
  system("PAUSE");
  return 0;
}
