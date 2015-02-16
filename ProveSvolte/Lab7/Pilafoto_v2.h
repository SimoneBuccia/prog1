#ifndef _Pilafoto_h
#define _Pilafoto_h

#include <cstring>


using namespace std;

class Immagine {
	
friend ostream & operator << (ostream &, const Immagine &);	
friend istream & operator >> (istream &, Immagine &);

	private:
		char * Proprietario;
		char * Formato;
	public:
		Immagine() {Proprietario=0; Formato=0;}
        Immagine(const char *, const char *);
       	Immagine(const 	Immagine &);
       	Immagine & operator=(const 	Immagine &);
        const char * getP() const {return Proprietario;}
        const char * getF() const {return Formato;}
        void setF(const char *);
        void setP(const char *);
        virtual void print() const;  // per l'esempio di polimorfismo nel modulo utente
        virtual ~Immagine() {if (Proprietario) delete [] Proprietario; if(Formato) delete [] Formato;}	
};

class Fotografia: public Immagine {
	
friend ostream & operator << (ostream &, const Fotografia &);
friend istream & operator >> (istream &, Fotografia &);
		
  private:
     int key;
     char * Soggetto;
     bool flag;
  public:
    Fotografia():Immagine() {Soggetto=0; key=0; flag=false;}
    Fotografia(const char *, const char *, const int, const char *, const bool);
    Fotografia(const Fotografia &);
    Fotografia & operator=(const Fotografia &);
    void setFlag(const bool F) {flag=F;}
    void setS(const char *);
    const char * getS() const {return Soggetto;}
    int getID() const {return key;}
    virtual void print() const; // per l'esempio di polimorfismo nel modulo utente
    virtual ~Fotografia() { if(Soggetto) delete [] Soggetto;}
};

class Pila {
 static const int N=5;
 Fotografia V[N];
 int testa;
 
 bool ricerca(const int, int &) const;
 
 public:
     Pila() {testa=0;}
     bool pop(Fotografia &);
     void top(Fotografia &) const;
     bool push(const Fotografia &);
     bool empty() const {return testa==0;}
     bool full() const {return testa==N;}
     void sposta(const int) ; 
     //void stampa(ostream &) const;
     void visualizza() const;
     friend ostream & operator << (ostream &, const Pila &);
     friend istream & operator >> (istream &, Pila &);
     
     
}; 


#endif  
