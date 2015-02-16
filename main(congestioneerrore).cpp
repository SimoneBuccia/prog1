#include "Lista.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Fotografia F;
	Fotografia F1("aaa","tipo1","autore1","titolo1", 2015,"soggetto1","formato1");
	Fotografia F2("bbb","tipo2","autore2","titolo2", 2015,"soggetto2","formato2");
	Fotografia F3("ccc","tipo3","autore3","titolo3", 2015,"soggetto3","formato3");
	Fotografia F4("ddd","tipo4","autore4","titolo4", 2015,"soggetto4","formato4");
	Fotografia F5("eee","tipo5","autore5","titolo5", 2015,"soggetto5","formato5");
	Fotografia F6=F2;

	cout<<F1<<endl<<F2<<endl<<F3<<endl<<F4<<endl<<F5<<endl;
	cout<<"\n\n\n";
	
	Lista L;
	L.InsertAtFront(F1);
	L.InsertAtFront(F2);
	L.InsertAtFront(F3);
	L.InsertAtFront(F4);
	L.InsertAtFront(F5);
	L.Print();
	
	try {
		L.InsertAtFront(F1);
	}catch (MyError E) {
	cout<<E.what();
	}
	

	return 0;
}
