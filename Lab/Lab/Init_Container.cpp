#include "Init_Container.h"
#include <cstdlib>

Container* Init(Container* Head) {
    Head = new Container(); //Выделяем память под новый узел 
    Head->Cont = NULL; //Пока животных нет 
    Head->Len = 0; //Контейнер пустой
    Head->Next = Head; //Указатель на след. элемент указывает на самый первый узел,
                        //т.к. это кольцевой список
    
    return Head;
}