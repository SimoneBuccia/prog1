#ifndef ERRORE_H
#define ERRORE_H

#include <string>


using namespace std;

class Errore {
    string msg;
    public:
        Errore(): msg("something of strange happened!!!!") {}
        Errore(const string & s): msg(s){}
        virtual string what()const {return msg;}
    
};

#endif  
