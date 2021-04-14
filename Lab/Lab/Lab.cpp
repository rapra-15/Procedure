#include <iostream>
#include <fstream>
#include "Container.h"
#include "Init_Container.h"
#include "In_Container.h"
#include "Out_Container.h"
#include "Clear_Container.h"
#include "Sort.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 3) {
        cout << "incorrect command line! "
            "Waited: command in_file out_file"
            << endl;
        exit(1);
    }
    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);
    cout << "Start" << endl;

    Container* Head = new Container(); //Создаем контейнер

    Head = Init(Head); //Инициализируем контейнер

    In(Head, ifst); //Записываем элементы контейнера из файла input.txt
    ofst << "Filled container. " << endl;

    Sort(Head);

    Out(Head, ofst); //Выводим элементы контейнера в файл output.txt

    Head = Clear(Head); //Очищаем контейнер
    ofst << "Empty container. " << endl;
    Out(Head, ofst); //Пробуем вывести в файл пустой контейнер

    cout << "Stop" << endl;
    system("pause");
    return 0;
}