#pragma once
#include "Produs.h"
#include <vector>
#include "ValidatorProdusDulce.h"
#include "ValidatorProdusSarat.h"

using namespace std;

class RepoFile {
protected:
	vector<Produs*> produse;
	string fileName;
	ValidatorProdusDulce validatorPD;
	ValidatorProdusSarat validatorPS;
public:
	RepoFile();
	RepoFile(string fileName);
	~RepoFile();
	void setFileName(string fileName);

	RepoFile& operator=(const RepoFile& repo);

	vector<Produs*> getAll();
	int getSize();
	Produs* getProdus(int pos);
	int findProdus(Produs* p);
	void addProdus(Produs* p);
	void updateProdus(Produs* pVechi, Produs* pNou);
	void deleteProdus(Produs* p);

	void emptyRepo();

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};


