#include "Out_Animal.h"
#include "Out_Fish.h"
#include "Out_Bird.h"
#include "Fish.h"
#include "Bird.h"

void Out_Animal(Animal* An, ofstream& ofst) {
    if (An->K == FISH)
    {
        Out_Fish((Fish*)An->Obj, ofst); //Выводим информацию о рыбке
    }
    else if (An->K == BIRD)
    {
        Out_Bird((Bird*)An->Obj, ofst); //Выводим информацию о птичке
    }
    else
    {
        ofst << "Incorrect element!" << endl;
    }
}
