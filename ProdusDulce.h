#pragma once
#include "Produs.h"

class ProdusDulce : public Produs {
private:
	string glazura;
public:
	ProdusDulce();
	ProdusDulce(string nume, double pret, int cantitate, string glazura);
	ProdusDulce(const ProdusDulce& p);
	~ProdusDulce();

	Produs* clone();

	string getGlazura();
	void setGlazura(string glazura);
	ProdusDulce& operator=(const ProdusDulce& p);
	bool operator==(const ProdusDulce& p);
	string toString(string delim);
};