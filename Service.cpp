#include "Service.h"
#include "ProdusDulce.h"
#include "ProdusSarat.h"
#include <algorithm>
#include "RepoException.h"
#include "ValidationException.h"
#include "ReadFromFileException.h"

using namespace std;

Service::Service()
{
	this->repo = NULL;
}

Service::Service(RepoFile* repo)
{
	this->repo = repo;
}

Service::~Service()
{
	if (this->repo != NULL)
	{
		delete this->repo;
	}
}

vector<Produs*> Service::getAll()
{
	return this->repo->getAll();
}

Produs* Service::getProdusAtPosition(int pos) throw(RepoException)
{
	return this->repo->getProdus(pos);
}

void Service::addProdusDulce(string nume, double pret, int cantitate, string glazura)
	throw(ValidationException, RepoException)
{
	ProdusDulce* pd = new ProdusDulce(nume, pret, cantitate, glazura);
	this->repo->addProdus(pd);
}

void Service::addProdusSarat(string nume, double pret, int cantitate, double cantitateSare)
	throw(ValidationException, RepoException)
{
	ProdusSarat* ps = new ProdusSarat(nume, pret, cantitate, cantitateSare);
	this->repo->addProdus(ps);
}

void Service::updateProdusDulce(string numeVechi, string numeNou, double pret, int cantitate, string glazura)
	throw(ValidationException, RepoException)
{
	Produs* pVechi = new Produs(numeVechi, 0, 0);
	ProdusDulce* pNou = new ProdusDulce(numeNou, pret, cantitate, glazura);
	this->repo->updateProdus(pVechi, pNou);
}

void Service::updateProdusSarat(string numeVechi, string numeNou, double pret, int cantitate, double cantitateSare)
	throw(ValidationException, RepoException)
{
	Produs* pVechi = new Produs(numeVechi, 0, 0);
	ProdusSarat* pNou = new ProdusSarat(numeNou, pret, cantitate, cantitateSare);
	this->repo->updateProdus(pVechi, pNou);
}

void Service::deleteProdus(string nume) throw(RepoException)
{
	Produs* p = new Produs(nume, 0, 0);
	this->repo->deleteProdus(p);
}

vector<Produs*> Service::filterByPrice(double lowerBound, double upperBound)
{
	vector<Produs*> produse = this->repo->getAll();
	vector<Produs*> result;
	for (Produs* p : produse)
	{
		if (p->getPret() >= lowerBound && p->getPret() <= upperBound)
		{
			result.push_back(p->clone());
		}
	}
	return result;
}

bool compareByQuantity(Produs* p1, Produs* p2)
{
	return p1->getCantitate() < p2->getCantitate();
}

vector<Produs*> Service::sortByQuantity()
{
	vector<Produs*> produse = this->repo->getAll();
	sort(produse.begin(), produse.end(), compareByQuantity);
	return produse;
}

int Service::cumpara(string nume, int cantitate, double& pretTotal)
{
	pretTotal = 0;
	vector<Produs*> produse = this->repo->getAll();
	for (Produs* p : produse)
	{
		if (p->getNume() == nume)
			if (p->getCantitate() >= cantitate)
			{
				pretTotal = p->getPret() * cantitate;
				p->setCantitate(p->getCantitate() - cantitate);
				this->saveToFile();
				return 0;
			}
			else
			{
				return -1;
			}
	}
	return -2;
}

int Service::returneaza(string nume, int cantitate)
{
	vector<Produs*> produse = this->repo->getAll();
	for (Produs* p : produse)
	{
		if (p->getNume() == nume)
		{
			p->setCantitate(p->getCantitate() + cantitate);
			this->saveToFile();
			return 0;
		}
	}
	return -1;
}

void Service::loadFromFile() throw(ReadFromFileException)
{
	this->repo->loadFromFile();
}

void Service::saveToFile()
{
	this->repo->saveToFile();
}

void Service::setFileName(string fileName)
{
	this->repo->setFileName(fileName);
}

void Service::setRepo(RepoFile* repo)
{
	this->repo = repo;
}
