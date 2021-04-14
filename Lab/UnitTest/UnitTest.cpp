#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab/Init_Container.h"
#include "../Lab/Init_Container.cpp"
#include "../Lab/In_Container.h"
#include "../Lab/In_Container.cpp"
#include "../Lab/In_Animal.h"
#include "../Lab/In_Animal.cpp"
#include "../Lab/Out_Container.h"
#include "../Lab/Out_Container.cpp"
#include "../Lab/Out_Animal.h"
#include "../Lab/Out_Animal.cpp"
#include "../Lab/Fish.h"
#include "../Lab/Bird.h"
#include "../Lab/Beast.h"
#include "../Lab/Animal.h"
#include "../Lab/Amount_Animal.h"
#include "../Lab/Amount_Animal.cpp"
#include "../Lab/Compare.h"
#include "../Lab/Compare.cpp"
#include "../Lab/Sort.h"
#include "../Lab/Sort.cpp"
#include "../Lab/In_Fish.h"
#include "../Lab/In_Fish.cpp"
#include "../Lab/In_Bird.h"
#include "../Lab/In_Bird.cpp"
#include "../Lab/In_Beast.h"
#include "../Lab/In_Beast.cpp"
#include "../Lab/Out_Fish.h"
#include "../Lab/Out_Fish.cpp"
#include "../Lab/Out_Bird.h"
#include "../Lab/Out_Bird.cpp"
#include "../Lab/Out_Beast.h"
#include "../Lab/Out_Beast.cpp"
#include "../Lab/Amount.h"
#include "../Lab/Amount.cpp"
#include "../Lab/Key.h"

#include <fstream>
#include <string>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(In_Fish_Test) //Тест проверки ввода информации (к примеру, о рыбах)
		{
			Fish* F_exp = new Fish; //Выделяем память для рыбы,
									//exp означает, что такую информацию
									//мы предполагаем увидеть после считывания

			//Заполняем предполагаемые данные
			F_exp->Name = "Fish1";
			F_exp->H = Fish::OCEAN;
			F_exp->Age = 13;

			//Выделяем память в контейнере
			Container* Head_Exp = new Container();

			//Заполняем все поля, которые будем сравнивать с тем, что находится в файле
			Head_Exp->Cont = new Animal;
			Head_Exp->Cont->Name = "Fish1";
			Head_Exp->Cont->K = FISH;
			Head_Exp->Cont->Obj = F_exp;
			Head_Exp->Cont->Age = 13;
			Head_Exp->Len = 1;
			Head_Exp->Next = Head_Exp;

			ifstream ifst("../Lab/in_fish.txt");

			Container* Head_Act = new Container();

			Head_Act = Init(Head_Act);

			//Считываем то, что в файле
			In(Head_Act, ifst);

			//Записываем фактическую информацию, с ней будем сравнивать предполагаемую
			Fish* F_act = (Fish*)Head_Act->Cont->Obj;

			//Сравниваем считанную (фактическую) и предполагаемой (описанной ранее) информацией о рыбе
			Assert::AreEqual(Head_Exp->Len, Head_Act->Len);
			Assert::AreEqual((int)Head_Exp->Cont->K, (int)Head_Act->Cont->K);
			Assert::AreEqual((int)Head_Exp->Cont->Age, (int)Head_Act->Cont->Age);

			Assert::AreEqual(F_exp->Name, F_act->Name);
			Assert::AreEqual((int)F_exp->H, (int)F_act->H);
			Assert::AreEqual((int)F_exp->Age, (int)F_act->Age);
		}
		TEST_METHOD(Out_Bird_Test)
		{
			//Описываем фактическую информацию о птице
			Bird* B_act = new Bird;

			B_act->Name = "Bird1";
			B_act->Migration = true;
			B_act->Age = 7;

			Container* Head_Act = new Container();

			Head_Act->Cont = new Animal;
			Head_Act->Cont->Name = "Bird1";
			Head_Act->Cont->K = BIRD;
			Head_Act->Cont->Obj = B_act;
			Head_Act->Len = 1;
			Head_Act->Next = Head_Act;

			ofstream ofst("../Lab/out_bird_act.txt");

			//Выводим указанную ранее информацию о птице
			Out(Head_Act, ofst);

			ifstream ifst_exp("../Lab/out_bird_exp.txt");
			ifstream ifst_act("../Lab/out_bird_act.txt");

			//Считываем то, что вывели, а также то, что предполагали увидеть при выводе
			string Expected;
			getline(ifst_exp, Expected, '\0');
			string Actual;
			getline(ifst_act, Actual, '\0');

			//Сравниваем
			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(Amount_Test)
		{
			Container* Head_Act = new Container();

			//Для теста функции подсчет достаточно указать имя животного
			//и класс
			Head_Act->Cont = new Animal;
			Head_Act->Cont->Name = "Beast1";
			Head_Act->Cont->K = BEAST;

			int Sum_exp = 6;
			int Sum_act = Amount_Animal(Head_Act->Cont);

			Assert::AreEqual(Sum_exp, Sum_act);
		}
		TEST_METHOD(Compare_Test)
		{
			//Для функции сравнения описываем два класса животных
			//и также указываем только имя и класс,
			//больше информации нам не понадобится
			Container* Head_B = new Container();

			Head_B->Cont = new Animal;
			Head_B->Cont->Name = "Beast1";
			Head_B->Cont->K = BEAST;

			Container* Head_F = new Container();

			Head_F->Cont = new Animal;
			Head_F->Cont->Name = "Fish1";
			Head_F->Cont->K = FISH;

			bool Act = Compare(Head_B, Head_F);
			bool Exp = true;

			Assert::AreEqual(Exp, Act);
		}
		TEST_METHOD(Sort_Test)
		{
			//В этом тесте считываем данные, которые хранятся изначально в файле
			//затем сортируем их и выводим.
			//Далее считываем то, что вывели и то, что
			//предполагали увидеть после сортировки.
			//И наконец сравниваем
			ifstream ifst("../Lab/input.txt");
			Container* Head = new Container();

			Head = Init(Head);

			In(Head, ifst);

			ofstream ofst("../Lab/sort_act.txt");

			Sort(Head);

			Out(Head, ofst);

			ifstream ifst_exp("../Lab/sort_exp.txt");
			ifstream ifst_act("../Lab/sort_act.txt");

			string Exp;
			getline(ifst_exp, Exp, '\0');
			string Act;
			getline(ifst_act, Act, '\0');

			Assert::AreEqual(Exp, Act);
		}
	};
}
