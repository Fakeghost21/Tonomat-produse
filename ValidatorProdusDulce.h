#pragma once
#include "ValidatorProdus.h"

class ValidatorProdusDulce : public ValidatorProdus {
public:
	ValidatorProdusDulce();
	~ValidatorProdusDulce();
	void validate(Produs* p);
};