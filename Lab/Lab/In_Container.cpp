#include "In_Container.h"
#include "In_Animal.h"

void In(Container* Head, ifstream& ifst) {
    Container* Temp, *P; //Временные узлы, в которых будем фиксировать промежуточную информацию
    int Len = 0; //Сюда будем писать количество узлов
    while (!ifst.eof())
    {
        Temp = new Container();
        
        //Заполняем первый узел
        if (Len == 0)
        {
            if ((Head->Cont = In_Animal(ifst)) != 0) //Считываем информацию о животном
            {
                Len++;
            }
        }
        else //Заполняем все остальные узлы
        {
            if ((Temp->Cont = In_Animal(ifst)) != 0)
            {
                P = Head->Next; //Фиксируем указатель на след. элемент (начало списка)
                Head->Next = Temp; //Текущий узел теперь указывает на новый
                Temp->Next = P; //Новый узел теперь указывает на начало списка
                Head = Temp; //Записываем новое начало списка
                Len++;
            }
        }
    }

    //Записываем размерность контейнера в каждом узле
    for (int i = 0; i < Len; i++)
    {
        Head->Len = Len;
        Head = Head->Next;
    }
}
