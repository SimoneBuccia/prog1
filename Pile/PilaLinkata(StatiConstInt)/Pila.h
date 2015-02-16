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

