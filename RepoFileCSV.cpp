#include "RepoFileCSV.h"
#include <fstream>
#include "ProdusDulce.h"
#include "ProdusSarat.h"
#include "ReadFromFileException.h"

RepoFileCSV::RepoFileCSV() : RepoFile()
{
}

RepoFileCSV::RepoFileCSV(string fileName) : RepoFile(fileName)
{
}

RepoFileCSV::~RepoFileCSV()
{
}

void RepoFileCSV::loadFromFile() throw(ReadFromFileException)
{
	ifstream f(this->fileName);
	if (f.is_open())
	{
		this->emptyRepo();
		string linie;
		string delim = ",";
		try {
			while (getline(f, linie))
			{
				if (linie.substr(0, 2) == "PD")
				{
					linie = linie.erase(0, 3);

					int pos = linie.find(delim);
					string nume = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					double pret = stod(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					int cantitate = stoi(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string glazura = linie.substr(0, pos);

					ProdusDulce* pd = new ProdusDulce(nume, pret, cantitate, glazura);
					this->validatorPD.validate(pd);
					this->produse.push_back(pd);
				}
				else if (linie.substr(0, 2) == "PS")
				{
					linie = linie.erase(0, 3);

					int pos = linie.find(delim);
					string nume = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					double pret = stod(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					int cantitate = stoi(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					double cantitateSare = stod(linie.substr(0, pos));

					ProdusSarat* ps = new ProdusSarat(nume, pret, cantitate, cantitateSare);
					this->validatorPS.validate(ps);
					this->produse.push_back(ps);
				}
			}
		}
		catch (...) {
			throw ReadFromFileException("formatul datelor din fisier este invalid!");
		}
		f.close();
	}
	else {
		throw ReadFromFileException("fisierul nu exista!");
	}
}

void RepoFileCSV::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Produs* elem : this->produse)
		{
			f << elem->toString(",") << endl;
		}
	}
}
