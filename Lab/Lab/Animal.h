#ifndef ANIMAL_H
#define ANIMAL_H

#include "Key.h"

#include <iostream>
#include <string>

using namespace std;

//Структура, содержащая информацию обо всех животных
struct Animal {
    Key K;
    string Name; //Общий параметр - название животного
    void* Obj;
    int Age; //Возраст животного
};

#endif // ANIMAL_H