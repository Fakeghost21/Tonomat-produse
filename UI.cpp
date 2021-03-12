#include "UI.h"
#include <iostream>
#include <fstream>
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "ValidationException.h"
#include "ReadFromFileException.h"
#include "ProdusDulce.h"
#include "Util.h"
#include "RepoException.h"

using namespace std;

void UI::displayMenu()
{
	cout << "1. Citeste din fisier\n";
	cout << "2. Afiseaza toate produsele\n";
	cout << "3. Adauga produs dulce\n";
	cout << "4. Adauga produs sarat\n";
	cout << "5. Modifica produs\n";
	cout << "6. Sterge produs\n";
	cout << "7. Filtreaza produse dupa pret\n";
	cout << "8. Sorteaza produse dupa cantitate\n";
	cout << "9. Cumpara un produs\n";
	cout << "10. Returneaza un produs\n";
	cout << "----------------\n";
	cout << "0. exit\n";
}

void UI::chooseFileType()
{
	int option = 0;
	cout << "Alegeti ce tip de fisier doriti. Scrieti 1 pt. TXT si 2 pt. CSV: ";
	cin >> option;
	while (option < 1 || option > 2)
	{
		cout << "Ati trecut un identificator gresit! Scrieti 1 pt. TXT si 2 pt. CSV: ";
		cin >> option;
	}
	if (option == 1)
	{
		this->serv.setRepo(new RepoFileTXT("fisier.txt"));
	}
	else
	{
		this->serv.setRepo(new RepoFileCSV("fisier.csv"));
	}
}

void UI::UILoadFromFile()
{
	try {
		this->serv.loadFromFile();
	}
	catch (ReadFromFileException & e) {
		cout << e.what()<<endl;
		cout << "Dati un alt nume de fisier: ";
		string fileName;
		getline(cin, fileName);
		this->serv.setFileName(fileName);
	}
	catch (ValidationException & e) {
		cout << e.what()<< endl;
	}
}

void UI::UIAddProdusDulce()
{
	cout << "Dati numele: ";
	string nume;
	getline(cin, nume);
	double pret;
	cout << "Dati pretul: ";
	cin >> pret;
	int cantitate;
	cout << "Dati cantitatea: ";
	cin >> cantitate;
	cin.ignore();
	string glazura;
	cout << "Dati glazura: ";
	getline(cin, glazura);
	try {
		this->serv.addProdusDulce(nume, pret, cantitate, glazura);
	}
	catch (ValidationException & e) {
		cout << e.what()<<endl;
	}
	catch (RepoException & e) {
		cout << e.what() << endl;
	}
}

void UI::UIAddProdusSarat()
{
	cout << "Dati numele: ";
	string nume;
	getline(cin, nume);
	double pret;
	cout << "Dati pretul: ";
	cin >> pret;
	int cantitate;
	cout << "Dati cantitatea: ";
	cin >> cantitate;
	double cantitateSare;
	cout << "Dati cantitatea de sare: ";
	cin >> cantitateSare;
	try {
		this->serv.addProdusSarat(nume, pret, cantitate, cantitateSare);
	}
	catch (ValidationException & e) {
		cout << e.what() << endl;
	}
	catch (RepoException & e) {
		cout << e.what() << endl;
	}
}

void UI::UIModifyProdus()
{
	cout << "Dati numele vechiului produs: ";
	string numeVechi;
	getline(cin, numeVechi);
	int option;
	do {
		cout << "De care produs vreto sa adaugati? 1. dulce 2. sarat \n";
		cin >> option;
	} while (option < 1 || option > 2);
	cin.ignore();
	cout << "Dati numele nou: ";
	string numeNou;
	getline(cin, numeNou);
	double pretNou;
	cout << "Dati pretul nou: ";
	cin >> pretNou;
	int cantitateNoua;
	cout << "Dati cantitatea noua: ";
	cin >> cantitateNoua;
	cin.ignore();

	if (option == 1) {
		string glazura;
		cout << "Dati noua glazura: ";
		getline(cin, glazura);
		try {
			this->serv.updateProdusDulce(numeVechi, numeNou, pretNou, cantitateNoua, glazura);
		}
		catch (ValidationException & e) {
			cout << e.what() << endl;
		}
		catch (RepoException & e) {
			cout << e.what() << endl;
		}
	}
	else {
		double cantitateSareNoua;
		cout << "Dati noua cantitate de sare: ";
		cin >> cantitateSareNoua;
		try {
			this->serv.updateProdusSarat(numeVechi, numeNou, pretNou, cantitateNoua, cantitateSareNoua);
		}
		catch (ValidationException & e) {
			cout << e.what() << endl;
		}
		catch (RepoException & e) {
			cout << e.what() << endl;
		}
	}
}

void UI::UIDeleteProdus()
{
	cout << "Dati numele produsului pe care doriti sa il stergeti: ";
	string nume;
	getline(cin, nume);
	try {
		this->serv.deleteProdus(nume);
	}
	catch (RepoException & e) {
		cout << e.what() << endl;
	}
}

void UI::UIShowAll()
{
	this->printProduse(this->serv.getAll());
}

void UI::printProduse(vector<Produs*> produse)
{
	for (Produs* p : produse)
	{
		cout << p->toString(" ").erase(0,3)<< endl;
	}
}

void UI::UIFilterByPrice()
{
	double lowerBound, upperBound;
	cout << "Dati limita inferioara: ";
	cin >> lowerBound;
	do {
		cout << "Dati limita superioara: ";
		cin >> upperBound;
	} while (upperBound < lowerBound);
	this->printProduse(this->serv.filterByPrice(lowerBound, upperBound));
}

void UI::UISortByQuantity()
{
	this->printProduse(this->serv.sortByQuantity());
}

void UI::UICumpara()
{
	string nume;
	cout << "Dati numele produsului: ";
	getline(cin, nume);
	int cantitate;
	double pretTotal;
	cout << "Dati cantitatea de produse pe care doriti sa le cumparati: ";
	cin >> cantitate;
	int status = this->serv.cumpara(nume, cantitate, pretTotal);
	if (status == 0)
	{
		cout << "Produsul " + nume + " a fost cumparat cu succes! Costul a fost de " 
			+ convertDoubleToString(pretTotal) + " lei" ;
		return;
	}
	if (status == -1)
	{
		cout << "Nu sunt suficiente exemplare pe stoc!";
		return;
	}
	cout << "Nu exista un produs cu numele " + nume + "!\n";
}

void UI::UIReturneaza()
{
	string nume;
	cout << "Dati numele produsului: ";
	getline(cin, nume);
	int cantitate;
	cout << "Dati cantitatea de produse pe care vreti sa o returnati: ";
	cin >> cantitate;
	int status = this->serv.returneaza(nume, cantitate);
	if (status == 0)
	{
		cout << "Produsul " + nume + " a fost returnat cu succes!";
		return;
	}
	cout << "Nu exista un produs cu numele " + nume + "!\n";
}

UI::UI()
{
}

UI::~UI()
{
}

void UI::runUI()
{
	this->chooseFileType();
	bool shouldRun = true;
	int option;
	while (shouldRun)
	{
		this->displayMenu();
		cin >> option;
		cin.ignore();
		switch (option)
		{
		case 1: {
			this->UILoadFromFile();
			break;
		}
		case 2: {
			this->UIShowAll();
			break;
		}
		case 3: {
			this->UIAddProdusDulce();
			break;
		}
		case 4: {
			this->UIAddProdusSarat();
			break;
		}
		case 5: {
			this->UIModifyProdus();
			break;
		}
		case 6: {
			this->UIDeleteProdus();
			break;
		}
		case 7: {
			this->UIFilterByPrice();
			break;
		}
		case 8: {
			this->UISortByQuantity();
			break;
		}
		case 9: {
			this->UICumpara();
			break;
		}
		case 10: {
			this->UIReturneaza();
			break;
		}
		case 0: {
			shouldRun = false;
			break;
		}
		default: {
			break;
		}
		}
	}
}
