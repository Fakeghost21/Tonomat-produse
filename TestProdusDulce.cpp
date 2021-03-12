#include "TestProdusDulce.h"
#include <assert.h>
#include "ProdusDulce.h"
#include "Util.h"

void TestProdusDulce::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetGlazura();
	this->testSetGlazura();;
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToString();
}

void TestProdusDulce::testImplicitConstructor()
{
	ProdusDulce p;
	assert(p.getNume().empty());
	assert(p.getPret() == 0);
}

void TestProdusDulce::testConstructorWithParameters()
{
	ProdusDulce p("banane", 3, 5, "fara");
	assert(p.getNume() == "banane");
	assert(p.getPret() == 3);
}

void TestProdusDulce::testCopyConstructor()
{
	ProdusDulce p1("banane", 3, 5, "fara");
	ProdusDulce p2(p1);
	assert(p2.getNume() == p1.getNume());
	assert(p2.getPret() == p1.getPret());
}

void TestProdusDulce::testClone()
{
	ProdusDulce p("banane", 3, 5, "fara");
	ProdusDulce* pClone = (ProdusDulce*)p.clone();
	assert(p == *pClone);
	assert(&p != pClone);
}

void TestProdusDulce::testGetGlazura()
{
	ProdusDulce p("banane", 3, 5, "fara");
	assert(p.getNume() == "banane");
}

void TestProdusDulce::testSetGlazura()
{
	ProdusDulce p;
	p.setNume("banane");
	assert(p.getNume() == "banane");
}

void TestProdusDulce::testAssignmentOperator()
{
	ProdusDulce p1("banane", 3, 5, "fara");
	ProdusDulce p2;
	p2 = p1;
	assert(p2.getNume() == p1.getNume());
	assert(p2.getPret() == p1.getPret());
}

void TestProdusDulce::testEqualityOperator()
{
	ProdusDulce p1("banane", 3, 5, "fara");
	ProdusDulce p2 = p1;
	assert(p1 == p2);
	p2.setNume("briosa");
	assert(!(p1 == p2));
	p2.setNume(p1.getNume());
	assert(p1 == p2);
	p2.setPret(10);
	assert(!(p1 == p2));
	p2.setPret(p1.getPret());
	assert(p1 == p2);
}

void TestProdusDulce::testToString()
{
	ProdusDulce p("banane", 3, 5, "fara");
	assert(p.toString(" ") == "PD banane 3 5 fara");
	assert(p.toString(",") == "PD,banane,3,5,fara");
}
