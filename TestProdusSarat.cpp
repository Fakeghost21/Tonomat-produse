#include "TestProdusSarat.h"
#include <assert.h>
#include "ProdusSarat.h"
#include "Util.h"

void TestProdusSarat::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetCantitateSare();
	this->testSetCantitateSare();;
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToString();
}

void TestProdusSarat::testImplicitConstructor()
{
	ProdusSarat p;
	assert(p.getNume().empty());
	assert(p.getPret() == 0);
}

void TestProdusSarat::testConstructorWithParameters()
{
	ProdusSarat p("chipsuri", 5, 7, 10);
	assert(p.getNume() == "chipsuri");
	assert(p.getPret() == 5);
}

void TestProdusSarat::testCopyConstructor()
{
	ProdusSarat p1("chipsuri", 5, 7, 10);
	ProdusSarat p2(p1);
	assert(p2.getNume() == p1.getNume());
	assert(p2.getPret() == p1.getPret());
}

void TestProdusSarat::testClone()
{
	ProdusSarat p("chipsuri", 5, 7, 10);
	ProdusSarat* pClone = (ProdusSarat*)p.clone();
	assert(p == *pClone);
	assert(&p != pClone);
}

void TestProdusSarat::testGetCantitateSare()
{
	ProdusSarat p("chipsuri", 5, 7, 10);
	assert(p.getNume() == "chipsuri");
}

void TestProdusSarat::testSetCantitateSare()
{
	ProdusSarat p;
	p.setNume("chipsuri");
	assert(p.getNume() == "chipsuri");
}

void TestProdusSarat::testAssignmentOperator()
{
	ProdusSarat p1("chipsuri", 5, 7, 10);
	ProdusSarat p2;
	p2 = p1;
	assert(p2.getNume() == p1.getNume());
	assert(p2.getPret() == p1.getPret());
}

void TestProdusSarat::testEqualityOperator()
{
	ProdusSarat p1("chipsuri", 5, 7, 10);
	ProdusSarat p2 = p1;
	assert(p1 == p2);
	p2.setNume("saleuri");
	assert(!(p1 == p2));
	p2.setNume(p1.getNume());
	assert(p1 == p2);
	p2.setPret(10);
	assert(!(p1 == p2));
	p2.setPret(p1.getPret());
	assert(p1 == p2);
}

void TestProdusSarat::testToString()
{
	ProdusSarat p("chipsuri", 5, 7, 10);
	assert(p.toString(" ") == "PS chipsuri 5 7 10");
	assert(p.toString(",") == "PS,chipsuri,5,7,10");
}
