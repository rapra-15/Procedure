#ifndef CONTAINER_H
#define CONTAINER_H

#include "Animal.h"

//Контейнер
struct Container {
    Container* Next; //Указатель на след. элемент контейнера
    Animal* Cont; //Указатель на структуру, содержащую информацию о животном
    int Len = 0; //Разменость контейнера
};

#endif // CONTAINER_H