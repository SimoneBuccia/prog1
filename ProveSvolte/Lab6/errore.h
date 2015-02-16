#ifndef _ERROR
#define _ERROR
#include <string>
#include <iostream>

using namespace std;

class errore{
    private:
        string msg;
    public:
        errore() {msg="Errore pila vuota";}
        errore(const char * err) {msg=err;}
        string what()const {return msg;}
};
#endif      
