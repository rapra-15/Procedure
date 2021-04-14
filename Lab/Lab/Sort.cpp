#include "Sort.h"
#include "Compare.h"
#include <iostream>

void Sort(Container* Head) {
	if (Head->Len > 1)
	{
		Container* First = Head;
		Container* Second = Head->Next;

		Container* Temp = new Container;

		for (int i = 0; i < Head->Len - 1; i++)
		{
			for (int j = 0; j < Head->Len - i - 1; j++)
			{
				if (Compare(First, Second))
				{
					Temp->Cont = First->Cont;
					First->Cont = Second->Cont;
					Second->Cont = Temp->Cont;
				}

				Second = Second->Next;
			}

			First = First->Next;
			Second = First->Next;
		}
	}
}