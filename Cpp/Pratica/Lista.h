#ifndef _LISTA_
#define _LISTA_

#include <iostream>
#include <cstring>
#include "Pratica.h"

using namespace std;

typedef Pratica T;

struct Record;

struct Record {
	T elem;
	Record * next;
};

class Lista {
	private:
		Record * testa;
		void clear();
	public:
		Lista() {
			testa = 0;
		}
		Lista(const Lista &);
		~Lista();
		
		bool InsertAtFront(const T &);
		bool InsertAtBack(const T &);
		bool RemoveFromFront(T &);
		bool RemoveFromBack(T &);
		bool InList(const T &) const;
		int Lenght() const;  
		bool Empty() const;
		bool Full()  const;
		bool Print() const;
		
		const Lista & operator=(const Lista &);

	
};

#endif
