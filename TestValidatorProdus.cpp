#include "TestValidatorProdus.h"
#include "ValidatorProdus.h"
#include "ValidationException.h"
#include <cassert>
#include "ValidatorProdusDulce.h"
#include "ProdusDulce.h"
#include "ValidatorProdusSarat.h"
#include "ProdusSarat.h"

void TestValidatorProdus::testValidatorProdus()
{
	ValidatorProdus val;
	Produs* p1 = new Produs("ciocolata", 5, 20);
	try
	{
		val.validate(p1);
	}
	catch (...)
	{
		assert(false);
	}
	Produs* p2 = new Produs("", 5, 30);
	try
	{
		val.validate(p2);
		assert(false);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	Produs* p3 = new Produs("abc_", 5, 30);
	try
	{
		val.validate(p3);
		assert(false);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	Produs* p4 = new Produs("abc", -1, 30);
	try
	{
		val.validate(p4);
		assert(false);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	Produs* p5 = new Produs("abc", 0, 30);
	try
	{
		val.validate(p5);
		assert(false);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	Produs* p6 = new Produs("abc", 1, -1);
	try
	{
		val.validate(p6);
		assert(false);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	Produs* p7 = new Produs("abc", 1, 0);
	try
	{
		val.validate(p7);
	}
	catch (...) {
		assert(false);
	}
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
	delete p7;
}

void TestValidatorProdus::testValidatorProdusDulce()
{
	ValidatorProdusDulce val;
	ProdusDulce* p1 = new ProdusDulce("ciocolata", 5, 20, "neagra");
	try
	{
		val.validate(p1);
	}
	catch (...)
	{
		assert(false);
	}
	ProdusDulce* p2 = new ProdusDulce("ciocolata", 5, 20, "");
	try
	{
		val.validate(p2);
		assert(false);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	ProdusDulce* p3 = new ProdusDulce("ciocolata", 5, 20, "u8io");
	try
	{
		val.validate(p3);
		assert(false);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	delete p1;
	delete p2;
	delete p3;
}

void TestValidatorProdus::testValidatorProdusSarat()
{
	ValidatorProdusSarat val;
	ProdusSarat* p1 = new ProdusSarat("ciocolata", 5, 20, 30);
	try
	{
		val.validate(p1);
	}
	catch (...)
	{
		assert(false);
	}
	ProdusSarat* p2 = new ProdusSarat("ciocolata", 5, 20, 0);
	try
	{
		val.validate(p2);
		assert(false);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	ProdusSarat* p3 = new ProdusSarat("ciocolata", 5, 20, -1);
	try
	{
		val.validate(p3);
		assert(false);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	delete p1;
	delete p2;
	delete p3;
}

TestValidatorProdus::TestValidatorProdus()
{
}

TestValidatorProdus::~TestValidatorProdus()
{
}

void TestValidatorProdus::testAll()
{
	this->testValidatorProdus();
	this->testValidatorProdusDulce();
	this->testValidatorProdusSarat();
}
