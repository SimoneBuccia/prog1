#include "codacircolare.h"


 Coda::Coda() {
   nelem=0;
   t=0; 
   c=0;
}

bool Coda::empty() const  {
    return nelem==0;
}    

bool Coda::full() const {
  return nelem==DIM;  
}    

int Coda::get_MAXDIM() const {return DIM;}

bool Coda::inserisci(const T & U) {
      if(!full()) {
        C[c]= U;
		c=((c+1)%DIM);
        nelem++;
        return true;
     }        
    else return false;
}  

bool Coda::elimina(T & U) {
    if(!empty()) {
	    U=C[t];
        t=((t+1)%DIM);
        nelem--;
        return true;
   }        
   else return false;
} 



