#include"Vettore.h"

Vettore::Vettore(int n=10){
	vet= new T[n];
	this->num=n;
	for(int i=0;i<n;i++)this->vet[i]=0;
}
Vettore::Vettore( const Vettore& v1){
	this->num=v1.num;
	this->vet=new T[this->num];
	for(int i=0;i<num;i++)vet[i]=v1.vet[i];
}
Vettore& Vettore::operator=(const Vettore& V){
	if(this!=&V){	// controllo se non si tratta di un auto-assegnamento
		if(this->num!=V.num) delete [] this->vet;
		this->vet=new T[V.num];
		this->num=V.num;
		for(int i=0;i<num;i++)vet[i]=V.vet[i]; 
	}
	return *this;
}
bool Vettore::operator==(const Vettore& V)const {
	int count=0;
	if(this->num==V.num){
		for(int i=0;i<V.num;i++){
			if(this->vet[i]==V.vet[i])count++;
		}
		if(count==V.num) return true; else return false;
	} else return false;
}

ostream& operator<<(ostream& os, const Vettore& Vet){
	for(int i=0;i<Vet.num;i++)os<<"\nPosizione: "<<i+1<<Vet.vet[i];
	os<<"La grandezza totale del vettore e'\t"<<Vet.get_size();
	return os;
}
istream& operator>>(istream& is, Vettore& Vet){
	for(int i=0;i<Vet.num;i++)is>>Vet.vet[i];
	return is;	
}
