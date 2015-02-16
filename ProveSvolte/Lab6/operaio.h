#ifndef _OPERAIO
#define _OPERAIO
#include "lavoratore.h"

#include <iostream>
#include <cstring>

using namespace std;

class operaio: public lavoratore{
    
    friend istream& operator>>(istream&,operaio &);
    friend ostream& operator<<(ostream&,const operaio &);
    
    protected:
        char* settore;
        int numOre;
    public:
        
        operaio(const char * ="", const char * ="", const int =0, const float =0.0, const char * ="", const int =0);
        operaio(const operaio &);
        const operaio& operator=(const operaio&);
        void setSett(const char*);
        const char* getSett() const {return settore;}
        virtual float calcolaStipendio() const {return stipendioBase*anzianita*numOre;}
        virtual ~operaio() {delete [] settore;}
        
};
            
        




#endif
