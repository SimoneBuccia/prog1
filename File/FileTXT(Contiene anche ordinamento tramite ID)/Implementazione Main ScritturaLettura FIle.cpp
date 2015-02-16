cout << "stampo il contenuto della pila su file di testo." << endl;
  ofstream myfile;
  char nomefile[30];
  
  cout << "inserire il nome del file: ";
  cin.getline(nomefile,30);
  myfile.open(nomefile, ios::out);
  if(!myfile) cout << "operazione non riuscita!!!!" << endl;
  else {
//	P.stampa(myfile);
    myfile << P;
	myfile.close();	
  }
  
 system("PAUSE"); 
  
 // test LETTURA da  file
  Pila mypila2;
  ifstream myfile2;
  char nomefile2[30];
  
  cout << "inserire il nome del file: ";
  cin.getline(nomefile2,30);
  myfile2.open(nomefile2, ios::in);
  if(!myfile2) cout << "operazione non riuscita!!!!" << endl;
  else {
    myfile2>>mypila2;
	myfile2.close();	
  }
