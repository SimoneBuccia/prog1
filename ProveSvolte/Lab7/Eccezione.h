#ifndef _Eccezione_h
#define _Eccezione_h

#include <string>


using namespace std;

class bad_event {
    string msg;
    public:
        bad_event(): msg("something of strange happened!!!!") {}
        bad_event(const string & s): msg(s){}
        virtual string what()const {return msg;}
    
};

#endif  
