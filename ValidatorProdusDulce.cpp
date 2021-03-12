#include "ValidatorProdusDulce.h"
#include "ProdusDulce.h"
#include "ValidationException.h"
//
ValidatorProdusDulce::ValidatorProdusDulce()
{
}

ValidatorProdusDulce::~ValidatorProdusDulce()
{
}

void ValidatorProdusDulce::validate(Produs* p)
{
	ValidatorProdus::validate(p);
	ProdusDulce* pd = (ProdusDulce*)p;
	if (pd->getGlazura().empty())
	{
		throw ValidationException("Glazura produsului nu poate fi goala!");
	}
	for (char c : pd->getGlazura())
	{
		if (!isalpha(c))
		{
			throw ValidationException("Glazura produsului poate sa contina doar litere!");
		}
	}
}
