#include "ValidatorProdus.h"
#include "ValidationException.h"

ValidatorProdus::ValidatorProdus()
{
}

ValidatorProdus::~ValidatorProdus()
{
}

void ValidatorProdus::validate(Produs* p)
{
	if (p->getNume().empty())
	{
		throw ValidationException("Numele produsului nu poate fi gol!");
	}
	for (char c : p->getNume())
	{
		if (!isalpha(c))
		{
			throw ValidationException("Numele produsului poate sa contina doar litere!");
		}
	}
	if (p->getPret() <= 0)
	{
		throw ValidationException("Pretul produsului treuie sa fie strict pozitiv!");
	}
	if (p->getCantitate() < 0)
	{
		throw ValidationException("Cantitatea produsului treuie sa fie pozitiva!");
	}
}

