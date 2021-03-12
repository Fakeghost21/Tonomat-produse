#include "TestService.h"
#include <assert.h>
#include "Service.h"
#include "RepoFileTXT.h"
#include "ProdusDulce.h"
#include "ProdusSarat.h"
#include "RepoException.h"
#include <vector>

void TestService::testGetAll()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ProdusDulce* p1 = new ProdusDulce("banane", 3, 5, "fara");
	ProdusSarat* p2 = new ProdusSarat("chipsuri", 5, 20, 10);
	serv.addProdusDulce(p1->getNume(), p1->getPret(), p1->getCantitate(), p1->getGlazura());
	serv.addProdusSarat(p2->getNume(), p2->getPret(), p2->getCantitate(), p2->getCantitateSare());
	vector<Produs*> produse = serv.getAll();
	assert(*produse[0] == *p1);
	assert(*produse[1] == *p2);
}

void TestService::testGetProdusAtPosition()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ProdusDulce* p = new ProdusDulce("banane", 3, 5, "fara");
	serv.addProdusDulce(p->getNume(), p->getPret(), p->getCantitate(), p->getGlazura());
	try {
		assert(*serv.getProdusAtPosition(0) == *p);
	}
	catch (...) {
		assert(false);
	}
	try {
		*serv.getProdusAtPosition(-1);
	}
	catch (RepoException& e) {
	}
	catch (...) {
		assert(false);
	}
	try {
		*serv.getProdusAtPosition(1);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
}

void TestService::testAddProdusDulce()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ProdusDulce* pd1 = new ProdusDulce("banane", 3, 5, "fara");
	try {
		serv.addProdusDulce(pd1->getNume(), pd1->getPret(), pd1->getCantitate(), pd1->getGlazura());
	}
	catch (...) {
		assert(false);
	}
	assert(*serv.getProdusAtPosition(0) == *pd1);
	ProdusDulce* pd2 = new ProdusDulce("banane", 1, 10, "galbena");
	try {
		serv.addProdusDulce(pd2->getNume(), pd2->getPret(), pd2->getCantitate(), pd2->getGlazura());
		assert(false);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
	assert(*serv.getProdusAtPosition(0) == *pd1);
}

void TestService::testAddProdusSarat()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ProdusSarat* ps1 = new ProdusSarat("chipsuri", 3, 5, 20);
	try {
		serv.addProdusSarat(ps1->getNume(), ps1->getPret(), ps1->getCantitate(), ps1->getCantitateSare());
	}
	catch (...) {
		assert(false);
	}
	assert(*serv.getProdusAtPosition(0) == *ps1);
	ProdusSarat* ps2 = new ProdusSarat("chipsuri", 8, 10, 25);
	try {
		serv.addProdusSarat(ps2->getNume(), ps2->getPret(), ps2->getCantitate(), ps2->getCantitateSare());
		assert(false);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
	assert(*serv.getProdusAtPosition(0) == *ps1);
}

void TestService::testUpdateProdusDulce()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ProdusDulce* p1 = new ProdusDulce("banane", 3, 5, "fara");
	serv.addProdusDulce(p1->getNume(), p1->getPret(), p1->getCantitate(), p1->getGlazura());
	ProdusDulce* p2 = new ProdusDulce("briosa", 5, 10, "capsuni");
	ProdusDulce* p3 = new ProdusDulce("napolitane", 5, 12, "vanilie");
	try {
		serv.updateProdusDulce(p3->getNume(), p2->getNume(), p2->getPret(), p2->getCantitate(), p2->getGlazura());
		assert(false);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
	assert(*serv.getProdusAtPosition(0) == *p1);
	try {
		serv.updateProdusDulce(p1->getNume(), p2->getNume(), p2->getPret(), p2->getCantitate(), p2->getGlazura());
	}
	catch (...) {
		assert(false);
	}
	assert(*serv.getProdusAtPosition(0) == *p2);
}

void TestService::testUpdateProdusSarat()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ProdusSarat* p1 = new ProdusSarat("chipsuri", 3, 10, 12);
	serv.addProdusSarat(p1->getNume(), p1->getPret(), p1->getCantitate(), p1->getCantitateSare());
	ProdusSarat* p2 = new ProdusSarat("covrigi", 2, 20, 8);
	ProdusSarat* p3 = new ProdusSarat("saratele", 5, 30, 20);
	try {
		serv.updateProdusSarat(p3->getNume(), p2->getNume(), p2->getPret(), p2->getCantitate(), p2->getCantitateSare());
		assert(false);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
	assert(*serv.getProdusAtPosition(0) == *p1);
	try {
		serv.updateProdusSarat(p1->getNume(), p2->getNume(), p2->getPret(), p2->getCantitate(), p2->getCantitateSare());
	}
	catch (...) {
		assert(false);
	}
	assert(*serv.getProdusAtPosition(0) == *p2);
}

void TestService::testDeleteProdus()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ProdusDulce* p1 = new ProdusDulce("banane", 3, 5, "fara");
	serv.addProdusDulce(p1->getNume(), p1->getPret(), p1->getCantitate(), p1->getGlazura());
	try {
		serv.deleteProdus("briosa");
		assert(false);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
	assert(*serv.getProdusAtPosition(0) == *p1);
	try {
		serv.deleteProdus(p1->getNume());
	}
	catch (...) {
		assert(false);
	}
}

void TestService::testFilterByPrice()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ProdusDulce* p1 = new ProdusDulce("banane", 5, 50, "fara");
	ProdusSarat* p2 = new ProdusSarat("covrigi", 20, 200, 8);
	serv.addProdusDulce(p1->getNume(), p1->getPret(), p1->getCantitate(), p1->getGlazura());
	serv.addProdusSarat(p2->getNume(), p2->getPret(), p2->getCantitate(), p2->getCantitateSare());
	
	vector<Produs*> filterResult = serv.filterByPrice(0, 4);
	assert(filterResult.size() == 0);
	filterResult = serv.filterByPrice(30, 40);
	assert(filterResult.size() == 0);
	filterResult = serv.filterByPrice(4, 7);
	assert(filterResult.size() == 1);
	assert(*filterResult[0] == *p1);
	filterResult = serv.filterByPrice(10, 28);
	assert(filterResult.size() == 1);
	assert(*filterResult[0] == *p2);
	filterResult = serv.filterByPrice(2, 44);
	assert(filterResult.size() == 2);
	assert(*filterResult[0] == *p1);
	assert(*filterResult[1] == *p2);
}

void TestService::testSortByQuantity()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ProdusDulce* p1 = new ProdusDulce("banane", 5, 500, "fara");
	ProdusSarat* p2 = new ProdusSarat("covrigi", 20, 20, 8);
	ProdusDulce* p3 = new ProdusDulce("ciocolata", 5, 30, "fara");
	serv.addProdusDulce(p1->getNume(), p1->getPret(), p1->getCantitate(), p1->getGlazura());
	serv.addProdusSarat(p2->getNume(), p2->getPret(), p2->getCantitate(), p2->getCantitateSare());
	serv.addProdusDulce(p3->getNume(), p3->getPret(), p3->getCantitate(), p3->getGlazura());
	
	vector<Produs*> filterResult = serv.sortByQuantity();
	assert(filterResult.size() == 3);
	assert(*filterResult[0] == *p2);
	assert(*filterResult[1] == *p3);
	assert(*filterResult[2] == *p1);
}

void TestService::testCumpara()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	double pretTotal;
	ProdusDulce* p1 = new ProdusDulce("banane", 5, 500, "fara");
	serv.addProdusDulce(p1->getNume(), p1->getPret(), p1->getCantitate(), p1->getGlazura());

	assert(serv.cumpara("ciocolata", 1, pretTotal) == -2);
	assert(serv.cumpara(p1->getNume(), 600, pretTotal) == -1);
	assert(serv.cumpara(p1->getNume(), 50, pretTotal) == 0);
	assert(pretTotal == 250);
	assert(serv.getProdusAtPosition(0)->getCantitate() == 450);
}

void TestService::testReturneaza()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	double pretTotal;
	ProdusDulce* p1 = new ProdusDulce("banane", 5, 500, "fara");
	serv.addProdusDulce(p1->getNume(), p1->getPret(), p1->getCantitate(), p1->getGlazura());

	assert(serv.returneaza("ciocolata", 2) == -1);
	assert(serv.returneaza(p1->getNume(), 50) == 0);
	assert(serv.getProdusAtPosition(0)->getCantitate() == 550);
}

TestService::TestService()
{
}

TestService::~TestService()
{
}

void TestService::testAll()
{
	this->testGetAll();
	this->testGetProdusAtPosition();
	this->testAddProdusDulce();
	this->testAddProdusSarat();
	this->testUpdateProdusDulce();
	this->testUpdateProdusSarat();
	this->testDeleteProdus();

	this->testFilterByPrice();
	this->testSortByQuantity();
	this->testCumpara();
	this->testReturneaza();
}
