#include "ProdusSarat.h"
#include "Util.h"
#include <iostream>

ProdusSarat::ProdusSarat() : Produs()
{
}

ProdusSarat::ProdusSarat(string nume, double pret, int cantitate, double cantitateSare) : Produs(nume, pret, cantitate)
{
	this->cantitateSare = cantitateSare;
}

ProdusSarat::ProdusSarat(const ProdusSarat& p) : Produs(p)
{
	this->cantitateSare = p.cantitateSare;
}

ProdusSarat::~ProdusSarat()
{
}

Produs* ProdusSarat::clone()
{
	return new ProdusSarat(this->nume, this->pret, this->cantitate, this->cantitateSare);
}

double ProdusSarat::getCantitateSare()
{
	return this->cantitateSare;
}

void ProdusSarat::setCantitateSare(double cantitateSare)
{
	this->cantitateSare = cantitateSare;
}

ProdusSarat& ProdusSarat::operator=(const ProdusSarat& p)
{
	Produs::operator=(p);
	this->cantitateSare = p.cantitateSare;
	return *this;
}

bool ProdusSarat::operator==(const ProdusSarat& p)
{
	return Produs::operator==(p) && this->cantitateSare == p.cantitateSare;
}

string ProdusSarat::toString(string delim)
{
	return "PS" + delim + Produs::toString(delim) + delim + convertDoubleToString(this->cantitateSare);
}

