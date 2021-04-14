#include "Clear_Container.h"
#include <cstdlib>

Container* Clear(Container* Head) {
    int Len = Head->Len; //Фиксируем размерность контейнера

    while (Len > 0) //Пока размерность контейнера не 0
    {
        free(Head->Cont); //Очищаем память, замнимаемую структурой информации о животном
        Head->Len = 0; //Указываем размерность контейнера для одного его узал 0
        Head = Head->Next; //Переходим к след. элементу контейнера
        Len--; //Уменьшаем зафиксированную длину
    }
    return Head;
}