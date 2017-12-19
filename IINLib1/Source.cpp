#include "IIN.h"
#include <stdexcept>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#include <conio.h> 

using namespace std;

namespace IIN
{
	void IINToData(char iin[13])
	{
		char den[3];
		char mes[3];
		char god[5];
		int kr;
		if (strlen(iin) == 12)
			kr = (1 * iin[0] + 2 * iin[1] + 3 * iin[2] + 4 * iin[3] + 5 * iin[4] + 6 * iin[5] + 7 * iin[6] + 8 * iin[7] + 9 * iin[8] + 10 * iin[9] + 11 * iin[10]) % 11;

		if (strlen(iin) != 12)
		{
			cout << "Вы ввели не правильно ИИН \n";
		}
		else
		{
			char ckr = iin[11];
			if (kr != atoi(&ckr))
			{
				cout << "Поздравляю у Вас не правильный ИИН" << endl;
			}
			else
				ckr = iin[6];
			if (atoi(&ckr) == 1 || atoi(&ckr) == 3 || atoi(&ckr) == 5)
				cout << "Ваш пол: мужчина \n";
			else
				cout << "Ваш пол: женщина \n";
			den[0] = iin[4];
			den[1] = iin[5];

			mes[0] = iin[2];
			mes[1] = iin[3];
			if (atoi(&ckr) == 1 || atoi(&ckr) == 2)
			{
				god[0] = '1';
				god[1] = '8';
				god[2] = iin[0];
				god[3] = iin[1];
			}
			else if (atoi(&ckr) == 3 || atoi(&ckr) == 4)
			{
				god[0] = '1';
				god[1] = '9';
				god[2] = iin[0];
				god[3] = iin[1];
			}
			else
			{
				god[0] = '2';
				god[1] = '0';
				god[2] = iin[0];
				god[3] = iin[1];
			}
			int igod, imes, iden;

			igod = atoi(god);
			imes = atoi(mes);
			iden = atoi(den);
			cout << "Вы родились: " << iden << "/" << imes << "/" << igod << endl;

			if ((iden >= 20 && imes == 3) || (iden <= 21 && imes == 4))
			{
				cout << "Вы Овен \n";
			}
			else if ((iden >= 20 && imes == 4) || (iden <= 21 && imes == 5))
			{
				cout << "Вы Телец \n";
			}
			else if ((iden >= 22 && imes == 5) || (iden <= 21 && imes == 6))
			{
				cout << "Вы Близнецы \n";
			}
			else if ((iden >= 22 && imes == 6) || (iden <= 23 && imes == 7))
			{
				cout << "Вы Рак \n";
			}
			else if ((iden >= 24 && imes == 7) || (iden <= 23 && imes == 8))
			{
				cout << "Вы Лев \n";
			}
			else if ((iden >= 24 && imes == 8) || (iden <= 23 && imes == 9))
			{
				cout << "Вы Дева \n";
			}
			else if ((iden >= 24 && imes == 9) || (iden <= 23 && imes == 10))
			{
				cout << "Вы Весы \n";
			}
			else if ((iden >= 24 && imes == 10) || (iden <= 21 && imes == 11))
			{
				cout << "Вы Скорпион \n";
			}
			else if ((iden >= 22 && imes == 12) || (iden <= 20 && imes == 1))
			{
				cout << "Вы Козерог \n";
			}
			else if ((iden >= 21 && imes == 1) || (iden <= 19 && imes == 2))
			{
				cout << "Вы Водолей \n";
			}
			else if ((iden >= 20 && imes == 2) || (iden <= 20 && imes == 3))
			{
				cout << "Вы Рыбы \n";
			}
		}
	}
	void DataToIIN(char den[3], char mes[3], char god[5], char pol[8])
	{
		char iin[13];
		int kr;
		iin[0] = god[2];
		iin[1] = god[3];
		iin[2] = mes[0];
		iin[3] = mes[1];
		iin[4] = den[0];
		iin[5] = den[1];
		if (pol[0] == 'м'&&god[0] == '1'&&god[1] == '8')
		{
			iin[6] = '1';
		}
		else if (pol[0] == 'ж'&&god[0] == '1'&&god[1] == '8')
		{
			iin[6] = '2';
		}
		else if (pol[0] == 'м'&&god[0] == '1'&&god[1] == '9')
		{
			iin[6] = '3';
		}
		else if (pol[0] == 'ж'&&god[0] == '1'&&god[1] == '9')
		{
			iin[6] = '4';
		}
		else if (pol[0] == 'м'&&god[0] == '2'&&god[1] == '0')
		{
			iin[6] = '5';
		}
		else if (pol[0] == 'ж'&&god[0] == '2'&&god[1] == '0')
		{
			iin[6] = '6';
		}
		srand(time(NULL));
		int a1 = rand() % 9, a2 = rand() % 9, a3 = rand() % 9, a4 = rand() % 9;
		char ca1[2], ca2[2], ca3[2], ca4[2], ckr[2];
		_itoa_s(a1, ca1, 10);
		_itoa_s(a2, ca2, 10);
		_itoa_s(a3, ca3, 10);
		_itoa_s(a4, ca4, 10);
		iin[7] = ca1[0];
		iin[8] = ca2[0];
		iin[9] = ca3[0];
		iin[10] = ca4[0];

		kr = (1 * iin[0] + 2 * iin[1] + 3 * iin[2] + 4 * iin[3] + 5 * iin[4] + 6 * iin[5] + 7 * iin[6] + 8 * iin[7] + 9 * iin[8] + 10 * iin[9] + 11 * iin[10]) % 11;
		_itoa_s(kr, ckr, 10);
		iin[11] = ckr[0];
		for (int i = 0; i <= 11; i++)
		{
			cout << iin[i];
		}
		cout << endl;
	}
}