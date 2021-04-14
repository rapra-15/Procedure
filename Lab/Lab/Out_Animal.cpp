#include "Out_Animal.h"
#include "Out_Fish.h"
#include "Out_Bird.h"
#include "Out_Beast.h"
#include "Fish.h"
#include "Bird.h"
#include "Beast.h"

void Out_Animal(Animal* An, ofstream& ofst) {
    if (An->K == FISH)
    {
        Out_Fish((Fish*)An->Obj, ofst); //Выводим информацию о рыбке
    }
    else if (An->K == BIRD)
    {
        Out_Bird((Bird*)An->Obj, ofst); //Выводим информацию о птичке
    }
    else if (An->K == BEAST)
    {
        Out_Beast((Beast*)An->Obj, ofst);
    }
    else
    {
        ofst << "Incorrect element!" << endl;
    }
}
