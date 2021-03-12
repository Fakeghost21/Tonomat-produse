#include "Produs.h"
#include "Util.h"
#include <iostream>

Produs::Produs()
{
	this->pret = 0;
	this->cantitate = 0;
}

Produs::Produs(string nume, double pret, int cantitate)
{
	this->nume = nume;
	this->pret = pret;
	this->cantitate = cantitate;
}

Produs::Produs(const Produs& p)
{
	this->nume = p.nume;
	this->pret = p.pret;
	this->cantitate = p.cantitate;
}

Produs::~Produs()
{
}

Produs* Produs::clone()
{
	return new Produs(this->nume, this->pret, this->cantitate);
}

string Produs::getNume()
{
	return this->nume;
}

double Produs::getPret()
{
	return this->pret;
}

int Produs::getCantitate()
{
	return this->cantitate;
}

void Produs::setNume(string nume)
{
	this->nume = nume;
}

void Produs::setPret(double pret)
{
	this->pret = pret;
}

void Produs::setCantitate(int cantitate)
{
	this->cantitate = cantitate;
}

Produs& Produs::operator=(const Produs& p)
{
	this->nume = p.nume;
	this->pret = p.pret;
	this->cantitate = p.cantitate;
	return *this;
}

bool Produs::operator==(const Produs& p)
{
	return this->nume == p.nume && this->pret == p.pret && this->cantitate == p.cantitate;
}

string Produs::toString(string delim)
{
	return this->nume + delim + convertDoubleToString(this->pret) + delim + to_string(this->cantitate);
}
