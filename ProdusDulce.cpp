#include "ProdusDulce.h"

ProdusDulce::ProdusDulce() : Produs()
{
}

ProdusDulce::ProdusDulce(string nume, double pret, int cantitate, string glazura) : Produs(nume, pret, cantitate)
{
	this->glazura = glazura;
}

ProdusDulce::ProdusDulce(const ProdusDulce& p) : Produs(p)
{
	this->glazura = p.glazura;
}

ProdusDulce::~ProdusDulce()
{
}

Produs* ProdusDulce::clone()
{
	return new ProdusDulce(this->nume, this->pret, this->cantitate, this->glazura);
}

string ProdusDulce::getGlazura()
{
	return this->glazura;
}

void ProdusDulce::setGlazura(string glazura)
{
	this->glazura = glazura;
}

ProdusDulce& ProdusDulce::operator=(const ProdusDulce& p)
{
	Produs::operator=(p);
	this->glazura = p.glazura;
	return *this;
}

bool ProdusDulce::operator==(const ProdusDulce& p)
{
	return Produs::operator==(p) && this->glazura == p.glazura;
}

string ProdusDulce::toString(string delim)
{
	return "PD" + delim + Produs::toString(delim) + delim + this->glazura;
}
