#include "RepoFile.h"
#include <typeinfo>
#include "ProdusDulce.h"
#include "ProdusSarat.h"
#include "RepoException.h"
#include "ValidationException.h"

RepoFile::RepoFile()
{
}

RepoFile::RepoFile(string fileName)
{
	this->fileName = fileName;
}

RepoFile::~RepoFile()
{
	this->emptyRepo();
}

void RepoFile::setFileName(string fileName)
{
	this->fileName = fileName;
}

RepoFile& RepoFile::operator=(const RepoFile& repo)
{
	this->fileName = repo.fileName;
	return *this;
}

vector<Produs*> RepoFile::getAll()
{
	return this->produse;
}

int RepoFile::getSize()
{
	return this->produse.size();
}
 
Produs* RepoFile::getProdus(int pos) throw(ValidationException, RepoException)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->produse[pos]->clone();
	}
	throw RepoException("Indexul este invalid!");
}

int RepoFile::findProdus(Produs* p)
{
	for (int i = 0; i < this->produse.size(); i++)
	{
		if (this->produse[i]->getNume() == p->getNume())
		{
			return i;
		}
	}
	return -1;
}

void RepoFile::addProdus(Produs* p) throw(ValidationException, RepoException)
{
	if (typeid(*p) == typeid(ProdusDulce))
	{
		this->validatorPD.validate(p);
	}
	if (typeid(*p) == typeid(ProdusSarat))
	{
		this->validatorPS.validate(p);
	}
	if (this->findProdus(p) >= 0)
	{
		throw RepoException("Exista deja un produs cu numele dat!");
	}
	this->produse.push_back(p->clone());
	this->saveToFile();
}

void RepoFile::updateProdus(Produs* pVechi, Produs* pNou) throw(ValidationException, RepoException)
{

	if (typeid(*pNou) == typeid(ProdusDulce))
	{
		this->validatorPD.validate(pNou);
	}
	if (typeid(*pNou) == typeid(ProdusSarat))
	{
		this->validatorPS.validate(pNou);
	}
	if (this->findProdus(pVechi) < 0)
	{
		throw RepoException("Nu exista niciun un produs cu numele dat!");
	}
	for (int i = 0; i < this->produse.size(); i++)
	{
		if (this->getProdus(i)->getNume() == pVechi->getNume())
		{
			delete this->produse[i];
			this->produse[i] = pNou->clone();
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::deleteProdus(Produs* p) throw(RepoException)
{
	for (int i = 0; i < this->produse.size(); i++)
	{
		// this->produse.begin() + i <=> un iterator care pointeaza spre pozitia i din vector
		if (this->produse[i]->getNume() == p->getNume())
		{
			delete this->produse[i];
			//este necesar un iterator pt. metoda erase
			this->produse.erase(this->produse.begin() + i);
			this->saveToFile();
			return;
		}
	}
	throw RepoException("Nu exista niciun produs cu numele dat!");
}

void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		delete this->produse[i];
	}
	this->produse.clear();
}

