#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<math.h>
#include<time.h>

using namespace std;
																		
bool IsLeapYear(int *Year);																									   	
int MonthDays(int *Month, int *Year);																							
void PrevDate(int *Day, int *Month, int *Year);																					
void NextDate(int *Day, int *Month, int *Year);																					

void main()
{
	setlocale(LC_ALL, "Rus");
	int n=1;
		cout << "Лабораторная работа." << endl;
		cout << endl;

		/*	1.	Дата некоторого дня характеризуется тремя натуральными числами: 
			g (год), m (порядковый номер месяца) и n (число).
			По заданным g, n и m определить (Определить функцию, подсчитывающую количество дней 
			в том или ином месяце):
				a.	дату предыдущего дня;
				b.	дату следующего дня
			2.	В обеих задачах рассмотреть два случая:
				a.	заданный год не является високосным; 
				b.	заданный год может быть високосным    */
		do
		{ 
			
			int Y, M, D;

				while (1)
				{
					cout << "Введите год (Y): ";
					cin >> Y;

					cout << "Введите месяц (M): ";
					cin >> M;

					cout << "Введите день (D): ";
					cin >> D;

					if (((D >= 1) && (D <= 31)) && ((M >= 1) && (M <= 12)) && (Y > 0))
						break;
					cout << "Должно выполнятся условие: 1 <= D <= 31, 1 <= M <= 12, Y > 0 " << endl;
					cout << "Введите данные еще раз." << endl;
				}
				cout << endl;

				cout << "Текущая дата: ";
				cout << D << "." << M << "." << Y << endl;

					int D1 = D;
					int M1 = M;
					int Y1 = Y;

			PrevDate(&D, &M, &Y);

				cout << "Предыдущая дата: ";
				cout << D << "." << M << "." << Y << endl;

			NextDate(&D1, &M1, &Y1);

				cout << "Следующая дата: ";
				cout << D1 << "." << M1 << "." << Y1 << endl;

		cout << endl;

		system("pause");
		cout << endl;
		cout << "Для повторения наберите любую цифру." << endl;
		cout << "Для выхода нажмите 0." << endl;
		cin >> n;
		system("cls");

		} while (n != 0);
}

/*Функция определения високосных лет */

bool IsLeapYear(int *Year)
{
	if ((*Year % 4 == 0) && (*Year % 100 != 0) || (*Year % 400 == 0))
		return true;
	else
		return false;
}

/*Функция определения количества дней в месяце*/

int MonthDays(int *Month, int *Year)
{
	int Y = *Year;
		switch (*Month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				return 31;
				break;

			case 4:
			case 6:
			case 9:
			case 11:
				return 30;
				break;

			case 2:
				if (IsLeapYear(&Y))
					return 29;
				else
					return 28;
				break;

			default:
				return 0;
		}
}

/*Функция определения предыдущей даты*/

void PrevDate(int *Day, int *Month, int *Year)
{
	int M = *Month;
	int Y = *Year;

		if ((*Day == 1) && (*Month == 1))
		{
			*Year = *Year - 1;
		}

			if (*Day == 1)
			{
				switch (*Month)
				{
					case 3:
						M--;
						*Day = MonthDays(&M, &Y);
						break;

					case 5:
					case 7:
					case 10:
					case 12:
						*Day = 30;
						break;

					case 1:
					case 2:
					case 4:
					case 6:
					case 8:
					case 9:
					case 11:
						*Day = 31;
						break;
				}

				*Month = (*Month + 10) % 12 + 1;
			}
			else
				*Day = *Day - 1;

}

/*Функция определения следующей даты*/

void NextDate(int *Day, int *Month, int *Year)
{
	int M = *Month;
	int Y = *Year;
	int LastDay;

		if ((*Day == 31) && (*Month == 12))
		{
			*Year = *Year + 1;
		}

		switch (*Month)
		{
			case 2:
				LastDay = MonthDays(&M, &Y);
				break;

			case 4:
			case 6:
			case 9:
			case 11:
				LastDay = 30;
				break;

			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				LastDay = 31;
				break;
		}

			if (LastDay > *Day)
				*Day = *Day + 1;
			else if (LastDay == *Day)
			{
				*Day = 1;
				*Month = *Month % 12 + 1;
			}

}









