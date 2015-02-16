#ifndef _MYERROR_h
#define _MYERROR_h

#include <string>


using namespace std;

class MyError{
    string msg;
    public:
        MyError(): msg("something of strange happened!!!!") {}
        MyError(const string & s): msg(s){}
        virtual string what()const {return msg;}
    
};

#endif  
