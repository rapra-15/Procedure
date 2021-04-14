#include "Amount_Animal.h"
#include "Amount.h"

int Amount_Animal(Animal* An) {
    if (An->K == FISH || An->K == BIRD || An->K == BEAST)
    {
        return Amount(An);
    }
    else
    {
        return -1;
    }
}
