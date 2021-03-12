#include "TestProdus.h"
#include <assert.h>
#include "Produs.h"
#include "Util.h"

void TestProdus::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetNume();
	this->testSetNume();
	this->testGetPret();
	this->testSetPret();
	this->testGetCantitate();
	this->testSetCantitate();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToString();
}

void TestProdus::testImplicitConstructor()
{
	Produs p;
	assert(p.getNume().empty());
	assert(p.getPret() == 0);
}

void TestProdus::testConstructorWithParameters()
{
	Produs p("banane", 3, 5);
	assert(p.getNume() == "banane");
	assert(p.getPret() == 3);
	assert(p.getCantitate() == 5);
}

void TestProdus::testCopyConstructor()
{
	Produs p1("banane", 3, 5);
	Produs p2(p1);
	assert(p2.getNume() == p1.getNume());
	assert(p2.getPret() == p1.getPret());
	assert(p2.getCantitate() == p1.getCantitate());
}

void TestProdus::testClone()
{
	Produs p("banane", 3, 5);
	Produs* pClone = p.clone();
	assert(p == *pClone);
	assert(&p != pClone);
}

void TestProdus::testGetNume()
{
	Produs p("banane", 3, 5);
	assert(p.getNume() == "banane");
}

void TestProdus::testSetNume()
{
	Produs p;
	p.setNume("banane");
	assert(p.getNume() == "banane");
}

void TestProdus::testGetPret()
{
	Produs p("banane", 3, 5);
	assert(p.getPret() == 3);
}

void TestProdus::testSetPret()
{
	Produs p;
	p.setPret(3);
	assert(p.getPret() == 3);
}

void TestProdus::testGetCantitate()
{
	Produs p("banane", 3, 5);
	assert(p.getCantitate() == 5);
}

void TestProdus::testSetCantitate()
{
	Produs p;
	p.setCantitate(5);
	assert(p.getCantitate() == 5);
}

void TestProdus::testAssignmentOperator()
{
	Produs p1("banane", 3, 5);
	Produs p2;
	p2 = p1;
	assert(p2.getNume() == p1.getNume());
	assert(p2.getPret() == p1.getPret());
	assert(p2.getCantitate() == p1.getCantitate());
}

void TestProdus::testEqualityOperator()
{
	Produs p1("banane", 3, 5);
	Produs p2 = p1;
	assert(p1 == p2);
	p2.setNume("briosa");
	assert(!(p1 == p2));
	p2.setNume(p1.getNume());
	assert(p1 == p2);
	p2.setPret(10);
	assert(!(p1 == p2));
	p2.setPret(p1.getPret());
	assert(p1 == p2);
	p2.setCantitate(10);
	assert(!(p1 == p2));
	p2.setCantitate(p1.getCantitate());
	assert(p1 == p2);
}

void TestProdus::testToString()
{
	Produs p("banane", 3, 5);
	assert(p.toString(" ") == "banane 3 5");
	assert(p.toString(",") == "banane,3,5");
}
