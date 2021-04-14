#include "Out_Bird.h"
#include "Bird.h"

void Out_Bird(Bird* B, ofstream& ofst) {
    ofst << "It's a Bird: " << B->Name << endl;
    ofst << "Is it a migration bird: "; //Выводим название птицы
    
    //Выводим информацию о том, мигрирует ли птица
    if (B->Migration)
    {
        ofst << "Yes" << endl;
    }
    else
    {
        ofst << "No" << endl;
    }

    ofst << "Bird's age is " << B->Age << endl;
}