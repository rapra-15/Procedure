#include "Fish.h"
#include "Bird.h"
#include "Beast.h"
#include "In_Animal.h"
#include "In_Fish.h"
#include "In_Bird.h"
#include "In_Beast.h"

Animal* In_Animal(ifstream& ifst) {
    Animal *An = new Animal; //�������� ������ ��� ����� ��������
    int K; //������������� ���������
    ifst >> K; //��������� �� ����� ������������� ���������
    if (K == 1) //���� K == 1, �� ��� ����
    {
        An->K = FISH; //���������� ��, ��� ��� ����
        An->Obj = In_Fish(ifst); //��������� ���������� � ����
        Fish* Temp_F = (Fish*)An->Obj; //�������� ������ � ����
        An->Name = Temp_F->Name; //���������� � ����� �������� ��������
        An->Age = Temp_F->Age;
        return An;
    }
    else if (K == 2) //���� K == 2, �� ��� �����
    {
        An->K = BIRD; //���������� ��, ��� ��� �����
        An->Obj = In_Bird(ifst); //��������� ���������� � �����
        Bird* Temb_B = (Bird*)An->Obj; //�������� ���������� � �����
        An->Name = Temb_B->Name; //���������� � ����� �������� ��������
        An->Age = Temb_B->Age;
        return An;
    }
    else if (K == 3)
    {
        An->K = BEAST;
        An->Obj = In_Beast(ifst);
        Beast* Temp_B = (Beast*)An->Obj;
        An->Name = Temp_B->Name;
        An->Age = Temp_B->Age;
        return An;
    }
    else
    {
        return 0;
    }
}
