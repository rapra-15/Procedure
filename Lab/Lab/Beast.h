#ifndef BEAST_H
#define BEAST_H

#include <iostream>
#include <string>

using namespace std;

//���������, ���������� ���������� � ������
struct Beast {
    string Name; //�������� �����
    
    //��� �����
    enum Beast_Type {
        PREDATOR,
        HERBIVORE,
        INSECTIVOROUS
    };

    Beast_Type B_T;
};

#endif // BEAST_H