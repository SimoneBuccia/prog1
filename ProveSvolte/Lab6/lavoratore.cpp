#include "lavoratore.h"

using namespace std;

lavoratore::lavoratore(const char * M, const char * A, const int Anni, const float S){
    matricola=new char[strlen(M)+1];
    strcpy(matricola,M);
    azienda=new char[strlen(A)+1];
    strcpy(azienda,A);
    anzianita=Anni;
    stipendioBase=S;
}

lavoratore::lavoratore(const lavoratore& L){
    matricola=new char[strlen(L.matricola)+1];
    strcpy(matricola,L.matricola);
    if(azienda) delete[]azienda;
    azienda= new char[strlen(L.azienda)+1];
    strcpy(azienda,L.azienda);
    anzianita=L.anzianita;
    stipendioBase=L.stipendioBase;
}

const lavoratore & lavoratore::operator=(const lavoratore &L){
    if(this!=&L) {
    if(matricola) delete[]matricola;
    matricola=new char[strlen(L.matricola)+1];
    strcpy(matricola,L.matricola);
    if(azienda) delete[]azienda;
    azienda= new char[strlen(L.azienda)+1];
    strcpy(azienda,L.azienda);
    anzianita=L.anzianita;
    stipendioBase=L.stipendioBase;
    }    
    return *this;
}

ostream& operator<<(ostream& out, const lavoratore& L){
    out<<L.matricola<<" "<<L.azienda;
    return out;
}

istream& operator>>(istream& in, lavoratore& L){
	// to fill
	return in;
}

void lavoratore::setMatr(const char * M){
    if (matricola) delete [] matricola;
   	matricola=new char[strlen(M)+1];
    strcpy(matricola,M);
}

void lavoratore::setAz(const char* A){
    if (azienda) delete [] azienda;
    azienda=new char[strlen(A)+1];
    strcpy(azienda,A);
}

