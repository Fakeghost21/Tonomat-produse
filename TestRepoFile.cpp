#include <assert.h>
#include "TestRepoFile.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "ProdusDulce.h"
#include "ProdusSarat.h"
#include "RepoException.h"
#include "ReadFromFileException.h"

void TestRepoFile::testGetSize()
{
	RepoFile* repoFile = new RepoFileTXT();
	assert(repoFile->getSize() == 0);
	repoFile->addProdus(new ProdusDulce("banane",3,5, "galbena"));
	assert(repoFile->getSize() == 1);
}

void TestRepoFile::testGetAll()
{
	RepoFile* repoFile = new RepoFileTXT();
	ProdusDulce* p1 = new ProdusDulce("banane", 3, 5, "fara");
	ProdusSarat* p2 = new ProdusSarat("chipsuri", 5, 20, 10);
	repoFile->addProdus(p1);
	repoFile->addProdus(p2);
	vector<Produs*> produse = repoFile->getAll();
	assert(*produse[0] == *p1);
    assert(*produse[1] == *p2);
}

void TestRepoFile::testGetProdus()
{
	RepoFile* repoFile = new RepoFileTXT();
	ProdusDulce* p = new ProdusDulce("banane", 3, 5, "fara");
	repoFile->addProdus(p);
	try {
		assert(*repoFile->getProdus(0) == *p);
	}
	catch (...) {
		assert(false);
	}
	try {
		*(repoFile)->getProdus(-1);
	}
	catch (RepoException& e) {
	}
	catch (...) {
		assert(false);
	}
	try {
		*(repoFile)->getProdus(1);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
}

void TestRepoFile::testAddProdus()
{
	RepoFile* repoFile = new RepoFileTXT();
	ProdusDulce* pd = new ProdusDulce("banane", 3, 5, "fara");
	try {
		repoFile->addProdus(pd);
	}
	catch (...) {
		assert(false);
	}
	assert(repoFile->getSize() == 1);
	assert(*repoFile->getProdus(0) == *pd);
	ProdusSarat* ps = new ProdusSarat("banane", 1, 10, 1);
	try {
		repoFile->addProdus(ps);
		assert(false);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
	assert(repoFile->getSize() == 1);
	assert(*repoFile->getProdus(0) == *pd);
}

void TestRepoFile::testUpdateProdus()
{
	RepoFile* repoFile = new RepoFileTXT();
	ProdusDulce* p1 = new ProdusDulce("banane", 3, 5, "fara");
	repoFile->addProdus(p1);
	ProdusDulce* p2 = new ProdusDulce("briosa", 5, 10, "capsuni");
	ProdusDulce* p3 = new ProdusDulce("napolitane", 5, 12, "vanilie");
	try {
		repoFile->updateProdus(p3, p2);
		assert(false);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
	assert(*repoFile->getProdus(0) == *p1);
	try {
		repoFile->updateProdus(p1, p2);
	}
	catch (...) {
		assert(false);
	}
	assert(*repoFile->getProdus(0) == *p2);
}

void TestRepoFile::testDeleteProdus()
{
	RepoFile* repoFile = new RepoFileTXT();
	ProdusDulce* p1 = new ProdusDulce("banane", 3, 5, "fara");
	repoFile->addProdus(p1);
	ProdusDulce* p2 = new ProdusDulce("briosa", 5, 10, "capsuni");
	try {
		repoFile->deleteProdus(p2);
		assert(false);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
	assert(repoFile->getSize() == 1);
	assert(*repoFile->getProdus(0) == *p1);
	try {
		repoFile->deleteProdus(p1);
	}
	catch (...) {
		assert(false);
	}
	assert(repoFile->getSize() == 0);
}

void TestRepoFile::testLoadFromFileTXT()
{
	RepoFile* repoFile = new RepoFileTXT(this->fileNameInTXT);
	try {
		repoFile->loadFromFile();
	}
	catch (...) {
		assert(false);
	}
	assert(repoFile->getSize() == this->produseIn.size());
	assert(*repoFile->getProdus(0) == (*this->produseIn[0]));
	assert(*repoFile->getProdus(1) == (*this->produseIn[1]));

	repoFile->setFileName("fdsvgdbgfbfgbbgf.txt");
	try {
		repoFile->loadFromFile();
		assert(false);
	}
	catch (ReadFromFileException & e) {

	}
	catch (...) {
		assert(false);
	}

	repoFile->setFileName(this->fileNameInInvalidTXT);
	try {
		repoFile->loadFromFile();
		assert(false);
	}
	catch (ReadFromFileException & e) {

	}
	catch (...) {
		assert(false);
	}
}

void TestRepoFile::testLoadFromFileCSV()
{
	RepoFile* repoFile = new RepoFileCSV(this->fileNameInCSV);
	try {
		repoFile->loadFromFile();
	}
	catch (...) {
		assert(false);
	}
	assert(repoFile->getSize() == this->produseIn.size());
	assert(*repoFile->getProdus(0) == (*this->produseIn[0]));
	assert(*repoFile->getProdus(1) == (*this->produseIn[1]));

	repoFile->setFileName("fdsvgdbgfbfgbbgf.csv");
	try {
		repoFile->loadFromFile();
		assert(false);
	}
	catch (ReadFromFileException & e) {

	}
	catch (...) {
		assert(false);
	}

	repoFile->setFileName(this->fileNameInInvalidCSV);
	try {
		repoFile->loadFromFile();
		assert(false);
	}
	catch (ReadFromFileException & e) {

	}
	catch (...) {
		assert(false);
	}
}

void TestRepoFile::testSavetoFileTXT()
{
	RepoFile* repoFile = new RepoFileTXT(this->fileNameInTXT);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameOutTXT);
	ProdusDulce* newProdus = new ProdusDulce("napolitane", 5, 10, "vanilie");
	repoFile->addProdus(newProdus);
	repoFile->saveToFile();
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->produseIn.size() + 1);
	vector<Produs*> produse = repoFile->getAll();
	for (int i = 0; i < repoFile->getSize() - 1; i++)
	{
		assert(*produse[i] == *this->produseIn[i]);
	}
	assert(*produse[produse.size() - 1] == *newProdus);
}

void TestRepoFile::testSaveToFileCSV()
{
	RepoFile* repoFile = new RepoFileCSV(this->fileNameInCSV);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameOutCSV);
	ProdusDulce* newProdus = new ProdusDulce("napolitane", 5, 10, "vanilie");
	repoFile->addProdus(newProdus);
	repoFile->saveToFile();
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->produseIn.size() + 1);
	vector<Produs*> produse = repoFile->getAll();
	for (int i = 0; i < repoFile->getSize() - 1; i++)
	{
		assert(*produse[i] == *this->produseIn[i]);
	}
	assert(*produse[produse.size() - 1] == *newProdus);
}

TestRepoFile::TestRepoFile()
{
	ProdusDulce* p1 = new ProdusDulce("banane", 3, 5, "fara");
	ProdusSarat* p2 = new ProdusSarat("chipsuri", 5, 20, 10);
	this->produseIn.push_back(p1);
	this->produseIn.push_back(p2);
}

TestRepoFile::~TestRepoFile()
{
}

void TestRepoFile::testAll()
{
	this->testGetSize();
	this->testGetAll();
	this->testGetProdus();
	this->testAddProdus();
	this->testUpdateProdus();
	this->testDeleteProdus();
	this->testLoadFromFileTXT();
	this->testLoadFromFileCSV();
	this->testSavetoFileTXT();
	this->testSaveToFileCSV();
}
