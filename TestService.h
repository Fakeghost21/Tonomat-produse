#pragma once
class TestService {
private:
    void testGetAll();
    void testGetProdusAtPosition();
    void testAddProdusDulce();
    void testAddProdusSarat();
    void testUpdateProdusDulce();
    void testUpdateProdusSarat();
    void testDeleteProdus();

    void testFilterByPrice();
    void testSortByQuantity();
    void testCumpara();
    void testReturneaza();
public: 
	TestService();
	~TestService();
	void testAll();
};