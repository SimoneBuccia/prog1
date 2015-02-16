#include "Squadra.h"

int main(int argc, char *argv[])
{
 Squadra s1( 19, "Napoli" );
 Squadra s2( 15, "Inter" );
 Squadra s3;

 // verifica degli operatori ridefiniti relazionali e di uguaglianza:
 cout << "s1:  " << s1 << endl; 
 cout << "s2:  " << s2 << endl; 
 cout << "s3:  " << s3 << endl; 
 cout<< "\n\nRisultati del confronto tra s2 and s1:" << endl;
 cout << "\ns2 == s1: " << ( s2 == s1 )
 << "\ns2 != s1 :" << ( s2 != s1 )
 << "\ns2 > s1: " << ( s2 > s1 )
 << "\ns2 < s1: " << ( s2 < s1 )
 << "\ns2 >= s1: " << ( s2 >= s1 )
 << "\ns2 <= s1: " << ( s2 <= s1 );
 
// verifica del costruttore di copia: 
Squadra * sptr	= new Squadra(s1);
cout << "\n*sptr = " << *sptr << endl;

// verifica dell'operatore di assegnazione: 
cout<< "\n\nRisultato dell'assegnamento s3=s2:" << endl;	
s3=s2;
cout << "\ns3 = " << s3 << endl;

// verifica delle set e delle get:
s3.setNome("Roma");
s3.setPunti(24);
cout << "\ns3 = " << s3.getNome() << "," << s3.getPunti() << endl;

// verifica delle operazioni di incremento e decremento: 
s3.modificaPunti(2);	
cout<< "\n\n Punteggio di s3 incrementato di 2 punti:" << s3.getPunti() << endl;	
s3.modificaPunti(-4);
cout<< "\n\n Punteggio di s3 decrementato di 4 punti:" << s3.getPunti() << endl;		

// verifica del distruttore: 	
delete sptr; 	
	
	system("pause");
	return 0;
}
