#include "Out_Beast.h"
#include "Beast.h"

void Out_Beast(Beast* B, ofstream& ofst) {
    ofst << "It's a Beast: " << B->Name << endl;
    ofst << "Beast's type is ";

    if (B->B_T == Beast::PREDATOR)
    {
        ofst << "Predator" << endl;
    }
    else if (B->B_T == Beast::HERBIVORE)
    {
        ofst << "Herbivore" << endl;
    }
    else if (B->B_T == Beast::INSECTIVOROUS)
    {
        ofst << "Insectivorous" << endl;
    }
}