#include "In_Beast.h"
#include "Beast.h"

void* In_Beast(ifstream& ifst) {
    Beast* B = new Beast; //Выделяем память под зверя

    ifst >> B->Name; //Считываем название зверя

    string Temp_K = ""; //Строка, хранящая информацию о типе зверя

    ifst >> Temp_K; //Считывает информацию о типе зверя

    //Записываем тип зверя
    if (Temp_K == "Predator")
    {
        B->B_T = Beast::PREDATOR;
    }
    else if (Temp_K == "Herbivore")
    {
        B->B_T = Beast::HERBIVORE;
    }
    else if (Temp_K == "Insectivorous")
    {
        B->B_T = Beast::INSECTIVOROUS;
    }

    return B;
}