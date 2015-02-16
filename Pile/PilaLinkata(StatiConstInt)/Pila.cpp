void swap(Fotografia &, Fotografia&);

        
bool Pila::pop(Fotografia & F){
    if (!empty()) {
    testa--;
    F=V[testa];
    return true;}
    else return false;
}

void Pila::top(Fotografia & F) const{
    F=V[testa-1];
}

bool Pila::push(const Fotografia & F){
    if (!full()) {
    V[testa]=F;
    testa++;
    return true;}
    else return false;
}
bool Pila::ricerca(const int K, int & pos)const{
    bool trovato=false;
    int i=0;
    while(i<testa && !trovato)
      if (V[i].getID()==K) {
        trovato=true;
        pos=i;
    }      
     else i++;   
   return trovato;
}

void Pila::sposta(const int K) {
    int pos=-1;
    if (!ricerca(K,pos)) throw bad_event("elemento da spostare non presente");
    swap(V[pos],V[testa-1]); 
}

void Pila::visualizza() const {
 
    int temp=(testa-1);
    for (int i=temp; i>=0; i--) {
      cout << V[i] << endl;
   }      
}

void swap(Fotografia & F1, Fotografia& F2) {
    Fotografia temp;
    temp=F1;
    F1=F2;
    F2=temp;
}    

istream & operator >> (istream & in, Pila & P) {
    Fotografia F;
	while(in >> F) P.push(F);
	return in;
}

ostream & operator << (ostream & out, const Pila & P) {
	int temp=(P.testa-1);
    for (int i=temp; i>=0; i--) {
      out << P.V[i] << '\n';
   } 
   return out;
}



void Pila::stampa(ostream & out) const {
	int temp=(testa-1);
    for (int i=temp; i>=0; i--) {
      out << V[i] << '\n';
   } 
}
