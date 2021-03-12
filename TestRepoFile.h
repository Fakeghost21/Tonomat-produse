#pragma once
#include "RepoFile.h"

class TestRepoFile {
private:
    const string fileNameInTXT = "TestProduseIn.txt";
    const string fileNameInInvalidTXT = "TestProduseInInvalid.txt";
    const string fileNameOutTXT = "TestProduseOut.txt";
    const string fileNameInCSV = "TestProduseIn.csv";
    const string fileNameInInvalidCSV = "TestProduseInInvalid.csv";
    const string fileNameOutCSV = "TestProduseOut.csv";

    //folosit pt. a testa lucrul cu fisiere
    vector<Produs*> produseIn;

    void testGetSize();
    void testGetAll();
    void testGetProdus();
    void testAddProdus();
    void testUpdateProdus();
    void testDeleteProdus();

    void testLoadFromFileTXT();
    void testLoadFromFileCSV();
    void testSavetoFileTXT();
    void testSaveToFileCSV();
public:
    TestRepoFile();
	~TestRepoFile();
	void testAll();
};