#include "Out_Container.h"
#include "Out_Animal.h"
#include "Amount_Animal.h"

void Out(Container* Head, ofstream& ofst) {
    ofst << "Container contains " << Head->Len
        << " elements." << endl; //������� ���������� � ����������� ����������

    for (int i = 0; i < Head->Len; i++)
    {
        ofst << i << ": "; //������� ����� ����
        Out_Animal(Head->Cont, ofst); //������� ���������� � ��������
        ofst << "Amount of symbols in the name of animal = " << Amount_Animal(Head->Cont) << endl;
        Head = Head->Next; //��������� � ����. ����
    }
}