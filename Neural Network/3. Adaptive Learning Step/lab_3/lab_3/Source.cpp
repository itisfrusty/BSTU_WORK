#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

int main()
{
	clock_t start = clock();
	int n_in = 3, // количество входов
		n_ob = 30, // размер выборки для обучения
		n_pr = 15, // размер прогнозируемой выборки
		it = 0; // счетчик итераций
	float w[5], // весовые коэффициенты
		T, // пороговое значение
		E = 0, sum = 0, E_min, // ошибка обучения и мин.ошибка
		t[60], // массив эталонных значений
		y[60], // массив выходных значений сети
		a, Y; // скорость обучения

	for (int i = 0; i < n_in; i++)
		w[i] = (1 + rand() % 9) / (float)10; // инициализация весовых коэффициентов
	T = (1 + rand() % 9) / (float)10; // инициализация порогового значения
	float tmp = 0.0;

	for (int j = 0; j < 60; j++) // заполнение массива выборки, на которой проходит обучение, т.е. эталонными значениями
		t[j] = 1 * sin(0.5 * (j + 1)) + 0.1;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter Emin: ";
	cin >> E_min;
	cout << "--------------------------------------" << endl;
	//обучение
	do
	{
		E = 0;
		sum = 0;
		//	cout << "--------------------------------------"<<endl;
		it++;
		//	cout << "it = " << it << endl;
		for (int i = 0; i < (n_ob - n_in); i++)
		{
			Y = 0;
			for (int j = 0; j < n_in; j++)
			{
				Y += w[j] * t[i + j];
				sum += pow(t[i + j], 2);
			}
			Y -= T; // рассчитываем выходную активность

			for (int j = 0; j < n_in; j++)
				w[j] -= a * (Y - t[i + n_in]) * t[i + j]; // изменяем весовые коэффициенты
			T += a * (Y - t[i + n_in]); // меняем пороговое значение
			a = (1 / (1 + sum));
		}

		for (int i = 0; i < (n_ob - n_in); i++)
		{
			Y = 0;
			for (int j = 0; j < n_in; j++)
				Y += w[j] * t[i + j];
			Y -= T; // расчитываем выходную активность
			E += 0.5 * pow((Y - t[i + n_in]), 2); // находим суммарную среднеквадратичную ошибку
		}

	} while (E >= E_min);

	cout << "it = " << it << endl;
	clock_t finish = clock();
	cout << "Time: " << (finish - start) << " ms\n";
	system("pause");
	return 0;
}
