#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

using namespace std;

struct Establishment {
	int id;
	string nome;
} bar;

struct Product {
	int id;
	string nome;
} cerveja;

struct Price {
	int id;
	string nome;
} oferta;

bool setup();
int createEstablishment(Establishment bar);
int createProduct(Product cerveja);
int createPrice(Price oferta);

int main() {
	// Inicializa todas as variaveis do sistema.
	if (!setup()) {
		cout << "Failed to bootstrap system";

		return 0;
	}
	
	int entry = 0;
	do {
		cout << "---------Menu----------" << endl;
		
		cout << "0 - Sair" << endl;
		
		cout << "1 - Cadastrar Bar" << endl;
		
		cout << "2 - Cadastrar Cervejas" << endl;
		
		cout << "3 - Cadastrar Ofertas" << endl;

		switch (entry) {
			case 1:
				createEstablishment(bar);
			break;
			
			case 2:
				createProduct(cerveja);
			break;
			
			case 3:
				createPrice(oferta);
			break;
		}
		
		// Item do menu.
		cin >> entry;
	}
	while(entry);
	
	return 0;
}

/**
 * Setup function
 * Usada para setar as principais variáveis do sistema.
 *
 * @return void
 */ 
bool setup() {
	// Cria pasta.
	char storageFolder[] = "Storage";
	const int dir_err = mkdir(storageFolder, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	if (-1 == dir_err) {
		cout << "Error creating directory!" << endl;

		return false;
	}

	ofstream baresStorage ("Storage/bares.txt");
	ofstream cervejasStorage ("Storage/cervejas.txt");
	ofstream ofertasStorage ("Storage/ofertas.txt");

	return true;
}


/**
 * CRUD functions
 */
int createEstablishment(Establishment bar) {
	cout << "Bar cadastrado!" << endl;

	return 0;
}

int createProduct(Product cerveja) {
	cout << "Cerveja cadastrada!" << endl;
	
	return 0;
}

int createPrice(Price oferta) {
	cout << "Oferta cadastrada!" << endl;

	return 0;
}
