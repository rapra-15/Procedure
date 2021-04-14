#include "In_Bird.h"
#include "Bird.h"

void* In_Bird(ifstream& ifst) {
    Bird* B = new Bird; //Выделяем память для птицы

    ifst >> B->Name; //Считывает название птицы
    ifst >> B->Migration; //Считываем информацию о том, мигрирует ли она

    return B;
}