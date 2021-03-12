#pragma once
#include "Produs.h"

class ProdusSarat : public Produs {
private:
	double cantitateSare;
public:
	ProdusSarat();
	ProdusSarat(string nume, double pret, int cantitate, double cantitateSare);
	ProdusSarat(const ProdusSarat& p);
	~ProdusSarat();

	Produs* clone();

	double getCantitateSare();
	void setCantitateSare(double cantitateSare);
	ProdusSarat& operator=(const ProdusSarat& p);
	bool operator==(const ProdusSarat& p);
	string toString(string delim);
};