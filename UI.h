#pragma once
#include "Service.h"

class UI {
private:
	Service serv;
	void displayMenu();
	void chooseFileType();
	void UILoadFromFile();
	void UIAddProdusDulce();
	void UIAddProdusSarat();
	void UIModifyProdus();
	void UIDeleteProdus();
	void UIShowAll();
	void printProduse(vector<Produs*> produse);

	void UIFilterByPrice();
	void UISortByQuantity();
	void UICumpara();
	void UIReturneaza();
public:
	UI();
	~UI();
	void runUI();
};