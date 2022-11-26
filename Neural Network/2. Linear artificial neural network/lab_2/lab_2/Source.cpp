#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

int main()
{
	clock_t start = clock();
	int n_in = 5, // количество входов
		n_ob = 30, // размер выборки для обучения
		n_pr = 15, // размер прогнозируемой выборки
		it = 0; // счетчик итераций
	float w[5], // весовые коэффициенты
		T, // пороговое значение
		E, E_min, // ошибка обучения и мин.ошибка
		t[60], // массив эталонных значений
		y[60], // массив выходных значений сети
		a, Y; // скорость обучения

	for (int i = 0; i < n_in; i++)
		w[i] = (1 + rand() % 9) / (float)10; // инициализация весовых коэффициентов
	T = (1 + rand() % 9) / (float)10; // инициализация порогового значения
	float tmp = 0.0;

	for (int j = 0; j < 60; j++) // заполнение массива выборки, на которой проходит обучение, т.е. эталонными значениями
		t[j] = 3 * sin(7 * (j + 1)) + 0.3;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter Emin: ";
	cin >> E_min;
	cout << "--------------------------------------" << endl;
	cout.width(11); cout << "t   |";
	cout.width(11); cout << "Y   |";
	cout.width(16); cout << "E   |" << endl;
	//обучение
	do
	{
		E = 0;
		cout << "--------------------------------------" << endl;
		it++;
		cout << "it = " << it << endl;
		for (int i = 0; i < (n_ob - n_in); i++)
		{
			Y = 0;
			for (int j = 0; j < n_in; j++)
				Y += w[j] * t[i + j];
			Y -= T; // рассчитываем выходную активность

			for (int j = 0; j < n_in; j++)
				w[j] -= a * (Y - t[i + n_in]) * t[i + j]; // изменяем весовые коэффициенты
			T += a * (Y - t[i + n_in]); // меняем пороговое значение
		}

		for (int i = 0; i < (n_ob - n_in); i++)
		{
			Y = 0;
			for (int j = 0; j < n_in; j++)
				Y += w[j] * t[i + j];
			Y -= T; // расчитываем выходную активность
			E += 0.5 * pow((Y - t[i + n_in]), 2); // находим суммарную среднеквадратичную ошибку
			cout.width(10); cout << t[i + n_in] << "|";
			cout.width(10); cout << Y << "|";
			cout.width(15); cout << E << "|" << endl;
		}

	} while (E >= E_min);

	// прогнозирование
	cout << "=====================================" << endl;
	cout << "		Prediction		" << endl;
	cout.width(16); cout << "t   |";
	cout.width(16); cout << "Y   |";
	cout.width(19); cout << "E   |" << endl;

	for (int i = (n_ob - n_in); i < (n_ob + n_pr); i++)
	{
		Y = 0;
		for (int j = 0; j < n_in; j++)
			Y += w[j] * t[i + j];
		Y -= T;
		E = 0.5 * pow((Y - t[i + n_in]), 2);
		cout.width(15); cout << t[i + n_in] << "|";
		cout.width(15); cout << Y << "|";
		cout.width(18); cout << E << "|" << endl;
		t[i + n_in] = Y;
	}
	clock_t finish = clock();
	cout << "Time: " << (finish - start) << " ms\n";
	system("pause");
	return 0;
}
