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
		
		TEST_METHOD(In_Fish_Test) //Тест проверки ввода информации о рыбе
		{
			Fish* F_exp = new Fish; //Выделяем память для рыбы,
									//exp означает, что такую информацию
									//мы предполагаем увидеть после считывания

			//Заполняем предполагаемые данные
			F_exp->Name = "Fish1";
			F_exp->H = Fish::OCEAN;
			F_exp->Age = 13;

			ifstream ifst("../Lab/in_fish.txt");

			Fish* F_act = (Fish*)In_Fish(ifst);

			//Сравниваем считанную (фактическую) и предполагаемой (описанной ранее) информацией о рыбе
			Assert::AreEqual(F_exp->Name, F_act->Name);
			Assert::AreEqual((int)F_exp->H, (int)F_act->H);
			Assert::AreEqual((int)F_exp->Age, (int)F_act->Age);
		}
		TEST_METHOD(In_Bird_Test) //Тест проверки ввода информации о птице
		{
			Bird* B_exp = new Bird; //Выделяем память для птицы,
									//exp означает, что такую информацию
									//мы предполагаем увидеть после считывания

			//Заполняем предполагаемые данные
			B_exp->Name = "Bird13";
			B_exp->Migration  = true;
			B_exp->Age = 4;

			ifstream ifst("../Lab/in_bird.txt");

			Bird* B_act = (Bird*)In_Bird(ifst);

			//Сравниваем считанную (фактическую) и предполагаемой (описанной ранее) информацией о птице
			Assert::AreEqual(B_exp->Name, B_act->Name);
			Assert::AreEqual(B_exp->Migration, B_act->Migration);
			Assert::AreEqual(B_exp->Age, B_act->Age);
		}
		TEST_METHOD(In_Beast_Test) //Тест проверки ввода информации о звере
		{
			Beast* B_exp = new Beast; //Выделяем память для зверя,
									//exp означает, что такую информацию
									//мы предполагаем увидеть после считывания

			//Заполняем предполагаемые данные
			B_exp->Name = "Beast1";
			B_exp->B_T = B_exp->INSECTIVOROUS;
			B_exp->Age = 18;

			ifstream ifst("../Lab/in_beast.txt");

			Beast* B_act = (Beast*)In_Beast(ifst);

			//Сравниваем считанную (фактическую) и предполагаемой (описанной ранее) информацией о рыбе
			Assert::AreEqual(B_exp->Name, B_act->Name);
			Assert::AreEqual((int)B_exp->B_T, (int)B_act->B_T);
			Assert::AreEqual(B_exp->Age, B_act->Age);
		}
		TEST_METHOD(Out_Fish_Test)
		{
			//Описываем фактическую информацию о птице
			Fish* F_act = new Fish;

			F_act->Name = "Fish7";
			F_act->H = F_act->RIVER;
			F_act->Age = 11;

			ofstream ofst("../Lab/out_fish_act.txt");

			//Выводим указанную ранее информацию о рыбе
			Out_Fish(F_act, ofst);

			ifstream ifst_exp("../Lab/out_fish_exp.txt");
			ifstream ifst_act("../Lab/out_fish_act.txt");

			//Считываем то, что вывели, а также то, что предполагали увидеть при выводе
			string Expected;
			getline(ifst_exp, Expected, '\0');
			string Actual;
			getline(ifst_act, Actual, '\0');

			//Сравниваем
			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(Out_Bird_Test)
		{
			//Описываем фактическую информацию о птице
			Bird* B_act = new Bird;

			B_act->Name = "Bird1";
			B_act->Migration = true;
			B_act->Age = 7;

			ofstream ofst("../Lab/out_bird_act.txt");

			//Выводим указанную ранее информацию о птице
			Out_Bird(B_act, ofst);

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
		TEST_METHOD(Out_Beast_Test)
		{
			//Описываем фактическую информацию о птице
			Beast* B_act = new Beast;

			B_act->Name = "Beast89";
			B_act->B_T = B_act->PREDATOR;
			B_act->Age = 23;

			ofstream ofst("../Lab/out_beast_act.txt");

			//Выводим указанную ранее информацию о звере
			Out_Beast(B_act, ofst);

			ifstream ifst_exp("../Lab/out_beast_exp.txt");
			ifstream ifst_act("../Lab/out_beast_act.txt");

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
			Animal* An = new Animal;
			
			An->Name = "Beast12";
			An->K = BEAST;

			int Sum_exp = 7;
			int Sum_act = Amount_Animal(An);

			Assert::AreEqual(Sum_exp, Sum_act);
		}
		TEST_METHOD(Compare_Test)
		{
			Container* Head_First = new Container();
			Animal* An_First = new Animal;

			An_First->Name = "Beast1";
			An_First->K = BEAST;
			Head_First->Cont = An_First;

			Container* Head_Second = new Container();
			Animal* An_Second = new Animal;

			An_Second->Name = "Fish1";
			An_Second->K = FISH;
			Head_Second->Cont = An_Second;

			bool Act = Compare(Head_First, Head_Second);
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
