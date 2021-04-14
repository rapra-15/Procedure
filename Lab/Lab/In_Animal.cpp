#include "Fish.h"
#include "Bird.h"
#include "In_Animal.h"
#include "In_Fish.h"
#include "In_Bird.h"

Animal* In_Animal(ifstream& ifst) {
    Animal *An = new Animal; //Выделяем память под новое животное
    int K; //Идентификатор животного
    ifst >> K; //Считываем из файла идентификатор животного
    if (K == 1) //Если K == 1, то это рыба
    {
        An->K = FISH; //Записывает то, что это рыба
        An->Obj = In_Fish(ifst); //Считываем информацию о рыбе
        Fish* Temp_F = (Fish*)An->Obj; //Получаем данные о рыбе
        An->Name = Temp_F->Name; //Записываем в общий параметр название
        return An;
    }
    else if (K == 2) //Если K == 2, то это птица
    {
        An->K = BIRD; //Записываем то, что это птица
        An->Obj = In_Bird(ifst); //Считываем информацию о птице
        Bird* Temb_B = (Bird*)An->Obj; //Получаем информацию о птице
        An->Name = Temb_B->Name; //Записываем в общий параметр название
        return An;
    }
    else
    {
        return 0;
    }
}
