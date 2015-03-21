#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

using namespace std;

struct Establishment {
	int id;
	string name;
} bar;

struct Product {
	int id;
	string name;
} cerveja;

struct Price {
	int id;
	int product_id;
	float amount;
} oferta;

bool setup();

int writeOnFile(char* message, ofstream &file);
void readOnFile(ifstream &file);
int countOnFile(ifstream &file);

int createEstablishment(Establishment bar);
void readEstablishments();

int createProduct(Product cerveja);
void readProducts();

int createPrice(Price oferta);
void readPrices();

void printDivider();

int main() {
	// Inicializa todas as variaveis do sistema.
	if (!setup()) {
		cout << "Failed to bootstrap system";

		return 0;
	}
	
	int entry = 0;
	
	cout << "----------Menu-----------" << endl;
	cout << "0 - Sair" << endl;
	cout << "1 - Cadastrar Bar" << endl;
	cout << "2 - Cadastrar Cerveja" << endl;
	cout << "3 - Cadastrar Oferta" << endl;
	cout << "4 - Ver Bares" << endl;
	cout << "5 - Ver Cervejas" << endl;
	cout << "6 - Ver Ofertas" << endl;

	printDivider();

	do {
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

			case 4:
				readEstablishments();
			break;

			case 5:
				readProducts();
			break;

			case 6:
				readPrices();
			break;
		}
		
		cout << "Menu: ";
		// Item do menu.
		cin >> entry;

		// clear buffer
		cin.ignore();
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
		cout << "Directory already exists or error creating directory!" << endl;

		return true;
	}

	// Create storage files and write your headers.
	char establishmentHeader[] = "id;nome";
	ofstream establishmentsStorage ("Storage/bares.csv", ios::app);
	writeOnFile(establishmentHeader, establishmentsStorage);

	char productHeader[] = "id;nome";
	ofstream productsStorage ("Storage/cervejas.csv", ofstream::app);
	writeOnFile(productHeader, productsStorage);
	
	char priceHeader[] = "id;nome;preco";
	ofstream pricesStorage ("Storage/ofertas.csv", ios::app);
	writeOnFile(priceHeader, pricesStorage);

	return true;
}

/**
 * Write any string on the given file.
 *
 */
int writeOnFile(char* message, ofstream &file) {
	if (!file.is_open()) {
  	cout << "Unable to open file";
  	return 0;
  }
  
  file << message << endl;
  file.close();

  return 1;
}

/**
 * Read file
 *
 */
void readOnFile(ifstream &file) {
  string line;

  while ( getline (file, line) ) {
    cout << line << endl;
  }
  
  file.close();
}

/**
 * Count lines of file.
 *
 */
int countOnFile(ifstream &file) {
  string line;

  int counter = 0;
  while ( getline (file, line) ) {
    counter = counter + 1;
  }

  file.close();

  return counter;
}

/**
 * CRUD functions
 */

 /**
  * Create a new establishment such as a bar.
  *
  */
int createEstablishment(Establishment bar) {
	cout << "----------Cadastrar Bar----------" << endl;
	ofstream baresStorage ("Storage/bares.csv", ios::app);
	ifstream readBaresStorage ("Storage/bares.csv");

	if (!baresStorage.is_open()) {
		return 0;
	}
	
	bar.id = countOnFile(readBaresStorage) - 1;
	cout << "Digite o nome do bar: ";
	getline(cin, bar.name);

	// convert string to char array.
	const char * barNameC = bar.name.c_str();

	// Line to write in file.
	char line[254];
	sprintf(line, "%d;%s", bar.id, barNameC);
	
	writeOnFile(line, baresStorage);

	cout << "Bar Cadastrado!" << endl;
	printDivider();

	return 1;
}

/**
 * Read all Establishment registed.
 *
 */
void readEstablishments() {
	ifstream baresStorage ("Storage/bares.csv");
	ifstream readBaresStorage ("Storage/bares.csv");
	
	if ((countOnFile(readBaresStorage) - 1 ) == 0) {
		cout << "----------Nenhum Bar------------" << endl;
		
		return;
	}

	cout << "----------Todos os Bares----------" << endl;
	readOnFile(baresStorage);
	printDivider();
}

int createProduct(Product cerveja) {
	cout << "----------Cadastrar Cerveja----------" << endl;
	ofstream productStorage ("Storage/cervejas.csv", ios::app);
	ifstream readProductStorage ("Storage/cervejas.csv");

	if (!productStorage.is_open()) {
		return 0;
	}
	
	cerveja.id = countOnFile(readProductStorage) - 1;
	cout << "Digite o nome da cerveja: ";
	getline(cin, cerveja.name);

	// convert string to char array.
	const char * cervejaNameC = cerveja.name.c_str();

	// Line to write in file.
	char line[254];
	sprintf(line, "%d;%s", cerveja.id, cervejaNameC);
	
	writeOnFile(line, productStorage);

	cout << "Cerveja Cadastrada!" << endl;
	printDivider();

	return 1;
}

/**
 * Read all Establishment registed.
 *
 */
void readProducts() {
	ifstream productStorage ("Storage/cervejas.csv");
	ifstream readProductStorage ("Storage/cervejas.csv");
	
	if ((countOnFile(readProductStorage) - 1 ) == 0) {
		cout << "----------Nenhuma Cerveja------------" << endl;
		
		return;
	}

	cout << "----------Todas as Cervejas----------" << endl;
	readOnFile(productStorage);
	printDivider();
}

/**
 *
 */
int createPrice(Price oferta) {
	cout << "----------Cadastrar Oferta----------" << endl;
	ofstream ofertaStorage ("Storage/ofertas.csv", ios::app);
	ifstream readOfertaStorage ("Storage/ofertas.csv");

	if (!ofertaStorage.is_open()) {
		return 0;
	}
	
	oferta.id = countOnFile(readOfertaStorage) - 1;

	cout << "Digite o ID da Cerveja: ";
	cin >> oferta.product_id;
	cin.ignore();

	cout << "Digite o preco da oferta: ";
	cin >> oferta.amount;

	// Line to write in file.
	char line[254];
	sprintf(line, "%d;%d;%f", oferta.id, oferta.product_id, oferta.amount);
	
	writeOnFile(line, ofertaStorage);

	cout << "Oferta Cadastrada!" << endl;
	printDivider();

	return 1;
}

/**
 * Read all prices.
 */
void readPrices() {
	ifstream priceStorage ("Storage/ofertas.csv");
	ifstream readPriceStorage ("Storage/ofertas.csv");
	
	if ((countOnFile(readPriceStorage) - 1 ) == 0) {
		cout << "----------Nenhuma Oferta------------" << endl;
		
		return;
	}

	cout << "----------Todas as Ofertas----------" << endl;
	readOnFile(priceStorage);
	printDivider();	
}

/**
 * Helper function to print a divider.
 */
void printDivider() {
	cout << "---------------------------------------" << endl;
}
