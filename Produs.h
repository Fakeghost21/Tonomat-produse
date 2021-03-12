#pragma once
#include <string>

using namespace std;
class Produs {
protected:
	string nume;
	double pret;
	int cantitate;

public:
	Produs();
	Produs(string nume, double pret, int cantitate);
	Produs(const Produs& p);
	~Produs();

	virtual Produs* clone();

	string getNume();
	double getPret();
	int getCantitate();
	void setNume(string nume);
	void setPret(double pret);
	void setCantitate(int cantitate);
	Produs& operator=(const Produs& p);
	bool operator==(const Produs& p);
	friend istream& operator>>(istream& is, Produs& p);
	virtual string toString(string delim);
};