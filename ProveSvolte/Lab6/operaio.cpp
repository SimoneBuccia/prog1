#include "operaio.h"

using namespace std;

operaio::operaio(const char * M, const char * A, const int Anni, const float S, const char * Set, const int ore) : lavoratore(M,A, Anni, S)
    {
    settore=new char[strlen(Set)+1];
    strcpy(settore,Set);
    numOre=ore; 
}

operaio::operaio(const operaio & O): lavoratore(O){
    settore=new char [strlen(O.settore)+1];
    strcpy(settore,O.settore);
    numOre=O.numOre;
}

ostream& operator<<(ostream& out,const operaio& O){
    out<<(lavoratore&)O<< ' ' << O.settore<< ' ' << O. numOre;
    return out;
}

istream& operator>>(istream& in, operaio& O){
  // to fill
    return in;
} 

void operaio::setSett(const char* S){
    if(settore) delete [] settore;
    settore=new char[strlen(S)+1];
    strcpy(settore,S);
}

const operaio& operaio::operator=(const operaio& O){
    if (this!=&O) {
    lavoratore::operator=(O);
    if(settore) delete[]settore;
    settore=new char [strlen(O.settore)+1];
    strcpy(settore,O.settore);
    numOre=O.numOre;
   } 
  return *this;   
}
    
