#include "Amount.h"

int Amount(Animal* An) {
	int Sum = 0;

	if (An->K == FISH || An->K == BIRD || An->K == BEAST)
	{
		return An->Name.size();
	}
	else
	{
		return -1;
	}
}
