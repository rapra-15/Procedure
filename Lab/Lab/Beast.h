#ifndef BEAST_H
#define BEAST_H

#include <iostream>
#include <string>

using namespace std;

//Структура, содержащая информацию о зверях
struct Beast {
    string Name; //Название зверя
    
    //Тип зверя
    enum Beast_Type {
        PREDATOR,
        HERBIVORE,
        INSECTIVOROUS
    };

    Beast_Type B_T;
};

#endif // BEAST_H