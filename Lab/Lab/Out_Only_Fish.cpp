#include "Out_Only_Fish.h"
#include "Out_Animal.h"

void Out_Only_Fish(Container* Head, ofstream& ofst) {
    ofst << endl << "Only Fishes." << endl;

    for (int i = 0; i < Head->Len; i++)
    {
        if (Head->Cont->K == FISH)
        {
            ofst << i << ": ";
            Out_Animal(Head->Cont, ofst);
            Head = Head->Next;
        }
        else
        {
            Head = Head->Next;
        }
    }
}