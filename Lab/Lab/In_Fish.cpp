#include "In_Fish.h"
#include "Fish.h"

void* In_Fish(ifstream& ifst) {
    Fish* F = new Fish; //Выделяем память пол рыбу
    
    ifst >> F->Name; //Считываем название рыбы
    
    string Temp_K = ""; //Строка, хранящая информацию о среде обитания рыбы

    ifst >> Temp_K; //Считывает информацию о среде обитания
    
    //Записываем, где обитает рыбка
    if (Temp_K == "River")
    {
        F->H = Fish::RIVER;
    }
    else if (Temp_K == "Sea")
    {
        F->H = Fish::SEA;
    }
    else if (Temp_K == "Ocean")
    {
        F->H = Fish::OCEAN;
    }

    return F;
}