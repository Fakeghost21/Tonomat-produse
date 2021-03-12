#pragma once
#include "ValidatorProdus.h"

class ValidatorProdusSarat : public ValidatorProdus {
public:
	ValidatorProdusSarat();
	~ValidatorProdusSarat();
	void validate(Produs* p);
};