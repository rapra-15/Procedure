#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include <string>

using namespace std;

//Структура, содержащая информацию о птицах
struct Bird {
    string Name; //Название птицы
    bool Migration; //Мигрирует ли она
    int Age; //Возраст птицы
};

#endif // BIRD_H