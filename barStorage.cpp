#include <iostream>
#include <fstream>

using namespace std;

void setup();

int main() {
	
	// Inicializa todas as variaveis do sistema.
	setup();
	
	int entry = 0;
	do {
		cout << "---------Menu----------" << endl;
		
		cout << "0 - Sair" << endl;
		
		cout << "1 - Cadastrar Bar" << endl;
		
		cout << "2 - Cadastrar Cervejas" << endl;
		
		cout << "3 - Cadastrar Ofertas" << endl;
		
		switch(entry) {
			case 1: cout << "Bar cadastrado!" << endl;
			break;
			
			case 2: cout << "Cerveja cadastrada!" << endl;
			break;
			
			case 3: cout << "Oferta cadastrada!" << endl;
			break;
		}
		
		// item do menu
		cin >> entry;
	}
	while(entry);
	
	return 0;
}

void setup() {
	ofstream baresStorage ("bares.txt");
	ofstream cervejasStorage ("cervejas.txt");
	ofstream ofertasStorage ("ofertas.txt");
	
	//if (myfile.is_open()) {
	//	myfile << "\n";
	//	myfile << "This is another line.\n";
	//	myfile.close();
	//}
	//else cout << "Unable to open file";
}
