ofstream & operator<<(ofstream & ofs, const Pacco & p) {
	int size = strlen(p.getIndirizzo());
	int codice = p.getCodice();
	float peso = p.getPeso();
	ofs.write((const char *)(&codice), sizeof(int));
	ofs.write((const char *)(&peso), sizeof(float));
	ofs.write((const char *)(&size), sizeof(int));
	ofs.write(p.getIndirizzo(), size*sizeof(char));
	return ofs;
}

ifstream & operator>>(ifstream & ifs, Pacco & p) {
	int codice;
	float peso;
	int size;
	char bufferI[100];
	ifs.read((char *)(&codice), sizeof(int));
	ifs.read((char *)(&peso), sizeof(int));
	ifs.read((char *)(&size), sizeof(int));
	ifs.read(bufferI, size*sizeof(char));
	bufferI[size] = '\0';
	p.setCodice(codice);
	p.setPeso(peso);
	p.setIndirizzo(bufferI);
	return ifs;
}
