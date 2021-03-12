#pragma once
#include <string>
#include "Produs.h"

using namespace std;

class ValidatorProdus {
public:
	ValidatorProdus();
	~ValidatorProdus();
	virtual void validate(Produs* p);
};