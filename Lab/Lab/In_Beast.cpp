#include "In_Beast.h"
#include "Beast.h"

void* In_Beast(ifstream& ifst) {
    Beast* B = new Beast; //�������� ������ ��� �����

    ifst >> B->Name; //��������� �������� �����

    string Temp_K = ""; //������, �������� ���������� � ���� �����

    ifst >> Temp_K; //��������� ���������� � ���� �����

    //���������� ��� �����
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