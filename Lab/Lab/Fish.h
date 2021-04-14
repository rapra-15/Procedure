#ifndef FISH_H
#define FISH_H

#include <iostream>
#include <string>

using namespace std;

//Структура, содержащая информацию о рыбах
struct Fish { 
    
    string Name; //Название рыбы

    //Среда обитания рыбы
    enum  Habitat {
        RIVER,
        SEA,
        OCEAN
    };

    Habitat H;
    int Age; //Возраст рыбы
};

#endif // FISH_H