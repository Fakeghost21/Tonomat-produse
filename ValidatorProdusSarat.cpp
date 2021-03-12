#include "ValidatorProdusSarat.h"
#include "ValidationException.h"
#include "ProdusSarat.h"

ValidatorProdusSarat::ValidatorProdusSarat()
{
}

ValidatorProdusSarat::~ValidatorProdusSarat()
{
}

void ValidatorProdusSarat::validate(Produs* p)
{
	ValidatorProdus::validate(p);
	ProdusSarat* ps = (ProdusSarat*)p;
	if (ps->getCantitateSare()<=0)
	{
		throw ValidationException("Canitatea de sare a produsului trebuie sa fie strict pozitiva!");
	}
}
