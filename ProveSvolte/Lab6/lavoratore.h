#ifndef _LAVORATORE
#define _LAVORATORE

#include <cstring>
#include <iostream>

using namespace std;

class lavoratore{
    
    friend ostream& operator<<(ostream&,const lavoratore&);
    friend istream& operator>>(istream&,lavoratore&);
    
    protected:
        char *matricola;
        char *azienda;
        int anzianita;
        float stipendioBase;
    public:
        lavoratore(const char * ="", const char * ="", const int =0, const float =0.0);
        lavoratore(const lavoratore &);
        const lavoratore& operator=(const lavoratore &);
        void setMatr(const char*);
        void setAz(const char*);
        const char* getMatr() const {return matricola;}
        const char* getAz() const {return azienda;}
        virtual float calcolaStipendio() const {return stipendioBase*anzianita;}
        virtual ~lavoratore() {delete [] matricola; delete [] azienda;}
};


#endif  
        
