#include "Out_Container.h"
#include "Out_Animal.h"
#include "Amount_Animal.h"

void Out(Container* Head, ofstream& ofst) {
    ofst << "Container contains " << Head->Len
        << " elements." << endl; //Выводим информацию о размерности контейнера

    for (int i = 0; i < Head->Len; i++)
    {
        ofst << i << ": "; //Выводим номер узла
        Out_Animal(Head->Cont, ofst); //Выводим информацию о животном
        ofst << "Amount of symbols in the name of animal = " << Amount_Animal(Head->Cont) << endl;
        Head = Head->Next; //Переходим к след. узлу
    }
}