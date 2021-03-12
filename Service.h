#pragma once
#include "RepoFile.h"
class Service {
private:
	RepoFile* repo;
public:
	Service();
	Service(RepoFile* repo);
	~Service();

	vector<Produs*> getAll();
	Produs* getProdusAtPosition(int pos);
	void addProdusDulce(string nume, double pret, int cantitate, string glazura);
	void addProdusSarat(string nume, double pret, int cantitate, double cantitateSare);
	void updateProdusDulce(string numeVechi, string numeNou, double pret, int cantitate, string glazura);
	void updateProdusSarat(string numeVechi, string numeNou, double pret, int cantitate, double cantitateSare);
	void deleteProdus(string nume);

	vector<Produs*> filterByPrice(double lowerBound, double upperBound);
	vector<Produs*> sortByQuantity();
	int cumpara(string nume, int cantitate, double& pretTotal);
	int returneaza(string nume, int cantitate);

	void loadFromFile();
	void saveToFile();
	void setFileName(string fileName);
	void setRepo(RepoFile* repo);
};

bool compareByQuantity(Produs* p1, Produs* p2);