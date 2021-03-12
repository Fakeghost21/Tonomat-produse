// Seminar5_sapt_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TestRepoFile.h"
#include <string>
#include "RepoFile.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "TestProdus.h"
#include "TestProdusDulce.h"
#include "TestProdusSarat.h"
#include "TestValidatorProdus.h"
#include "UI.h"
#include "TestService.h"

using namespace std; 

int main()
{
    TestProdus testProdus;
    testProdus.testAll();
    TestProdusDulce testProdusDulce;
    testProdusDulce.testAll();
    TestProdusSarat testProdusSarat;
    testProdusSarat.testAll();

    TestValidatorProdus tvp;
    tvp.testAll();

    TestRepoFile testRepoFile;
    testRepoFile.testAll();

    TestService testService;
    testService.testAll();

    UI ui;
    ui.runUI();

    cout << "Gata";




   /* RepoFile* repoFile;
    cout << "TXT sau CSV?";
    string opt;
    getline(cin, opt);
    if (opt == "txt")
    {
        repoFile = new RepoFileTXT("fisier.txt");
    }
    else
    {
        if (opt == "csv")
        {
            repoFile = new RepoFileCSV("fisier.csv");
        }
    }*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
