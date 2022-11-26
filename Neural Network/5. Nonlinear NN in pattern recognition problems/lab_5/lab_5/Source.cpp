#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <cstdio>

#define INPUT 	30
#define HIDE		8
#define OUTPUT	10	
#define alpha 	0.1
#define E		0.4

using namespace std;
double	w_layer2[INPUT][HIDE],		//Весовые коэффициенты между входным и скрытым слоем
T_layer2[HIDE],		//Пороговые значения НЭ скрытого слоя
w_layer3[HIDE][OUTPUT],	//Весовые коэффициенты связей между скрытым и выходным слоем
T_layer3[OUTPUT],		//Пороговые значения НЭ выходного слоя
y_layer2[HIDE],		//Выходные значения НЭ скрытого
y_layer3[OUTPUT];		//Выходные значения НЭ выходного

char input_buffer[INPUT + 1];		//Образ, введенный с клавиатуры
double g_layer2[HIDE];		//Ошибки нейронов скрытого
double g_layer3[OUTPUT];		//Ошибки нейронов выходного

bool input_sample[OUTPUT][INPUT] = {

{
0,1,1,1,0,
1,0,0,0,1,
1,0,0,0,1,
1,0,0,0,1,
1,0,0,0,1,
0,1,1,1,0
},
{
0,0,1,0,0,
0,1,1,0,0,
1,0,1,0,0,
0,0,1,0,0,
0,0,1,0,0,
1,1,1,1,1
},
{
0,1,1,1,0,
1,0,0,0,1,
0,0,0,1,0,
0,0,1,0,0,
0,1,0,0,0,
1,1,1,1,1
},
{
0,1,1,1,0,
1,0,0,0,1,
0,0,1,1,0,
0,0,1,1,0,
1,0,0,0,1,
0,1,1,1,0
},
{
0,0,0,1,0,
0,0,1,1,0,
0,1,0,1,0,
1,1,1,1,1,
0,0,0,1,0,
0,0,0,1,0
},
{
1,1,1,1,1,
1,0,0,0,0,
1,1,1,1,0,
0,0,0,0,1,
0,0,0,0,1,
1,1,1,1,0
},
{
0,1,1,1,0,
1,0,0,0,0,
1,1,1,1,0,
1,0,0,0,1,
1,0,0,0,1,
0,1,1,1,0
},
{
0,1,1,1,1,
0,0,0,0,1,
0,0,0,1,0,
0,0,1,0,0,
0,0,1,0,0,
0,0,1,0,0
},
{
0,1,1,1,0,
1,0,0,0,1,
0,1,1,1,0,
1,0,0,0,1,
1,0,0,0,1,
0,1,1,1,0
},
{
0,1,1,1,0,
1,0,0,0,1,
1,0,0,0,1,
0,1,1,1,0,
0,0,0,0,1,
0,1,1,1,0
} };

FILE* fo;

//Возвращает определённый класс образа
int out_network(char temp[]) {
	//Считаем выходные значения скрытого слоя
	for (int i = 0; i < HIDE; i++) {
		y_layer2[i] = 0;
		for (int j = 0; j < INPUT; j++)
			if (temp[j])
				y_layer2[i] += w_layer2[j][i];
		y_layer2[i] -= T_layer2[i];
		y_layer2[i] = 1 / (1 + exp(-y_layer2[i]));
	}
	//Считаем выходные значения выходного слоя
	for (int i = 0; i < OUTPUT; i++) {
		y_layer3[i] = 0;
		for (int j = 0; j < HIDE; j++)
			y_layer3[i] += y_layer2[j] * w_layer3[j][i];
		y_layer3[i] -= T_layer3[i];
	}
	//Определяем класс входного образа
	double max_val = y_layer3[0];
	int result = 0;
	for (int i = 1; i < OUTPUT; i++)
		if (y_layer3[i] > max_val) {
			max_val = y_layer3[i];
			result = i;
		}
	return result;
}
//Распознавание строки
int recognition(char temp[]) {
	for (int i = 0; i < INPUT; i++) {
		if (temp[i] == '0')
			input_buffer[i] = 0;
		else
			input_buffer[i] = 1;
	}
	return out_network(input_buffer);
}

int main() {
	fo = fopen("error.txt", "wt");
	setlocale(0, "");
	srand(time(NULL));
	/// Случайно задаем веса и пороги
	for (int i = 0; i < HIDE; i++) {
		for (int j = 0; j < INPUT; j++)
			w_layer2[j][i] = double(rand() - 16384) / 16384;
		for (int j = 0; j < OUTPUT; j++)
			w_layer3[i][j] = double(rand() - 16384) / 16384;
		T_layer2[i] = double(rand() - 16384) / 16384;
	}
	for (int i = 0; i < OUTPUT; i++)
		T_layer3[i] = double(rand() - 16384) / 16384;

	/// Вывод входных значений
	for (int k = 0; k < 6; k++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 5; j++) {
				if (input_sample[i][j + k * 5] == 0)
					printf(" ");
				else
					printf("%d", input_sample[i][j + k * 5]);
			}
			printf("  ");
		}
		printf("\n");
	}

	/// Обучение
	int counter = 0;
	bool flag = 1;	//Признак окончания обучения
	while (flag) {
		flag = 0;
		//Для каждой обучающей выборки:
		for (int k = 0; k < OUTPUT; k++) {
			//Формируем обучающую выборку
			for (int i = 0; i < INPUT; i++)
				input_buffer[i] = input_sample[k][i];
			//Получаем выходные значения нейронов
			out_network(input_buffer);
			//Считаем ошибки нейронов выходного слоя
			double E_sqrt = 0;
			for (int i = 0; i < OUTPUT; i++) {
				if (i == k)
					g_layer3[i] = y_layer3[i] - 1;
				else
					g_layer3[i] = y_layer3[i];
				E_sqrt += pow(g_layer3[i], 2);
			}
			fprintf(fo, "%f\n", E_sqrt);
			//Если одна из них больше допустимой, переходим к следующей итерации обучения
			for (int i = 0; i < OUTPUT; i++)
				if (abs(g_layer3[i]) >= E)
					flag = 1;
			//Считаем ошибки нейронов скрытого
			for (int i = 0; i < HIDE; i++) {
				g_layer2[i] = 0;
				for (int j = 0; j < OUTPUT; j++) {
					g_layer2[i] += g_layer3[j] * y_layer3[j] * (1 - y_layer3[j]) * w_layer3[i][j];
				}
			}
			//Пересчитываем значения весовых коэффициентов и пороговых значений скрытого слоя
			for (int j = 0; j < HIDE; j++) {
				for (int i = 0; i < INPUT; i++)
					w_layer2[i][j] -= alpha * g_layer2[j] * y_layer2[j] * (1 - y_layer2[j]) * input_buffer[i];
				T_layer2[j] += alpha * g_layer2[j] * y_layer2[j] * (1 - y_layer2[j]);
			}
			//Пересчитываем значения весовых коэффициентов и пороговых значений выходного слоя
			for (int j = 0; j < OUTPUT; j++) {
				for (int i = 0; i < HIDE; i++)
					w_layer3[i][j] -= alpha * g_layer3[j] * y_layer2[i];
				T_layer3[j] += alpha * g_layer3[j];
			}
			counter++;
		}
	}
	printf("Обучено за %d итераций\n", counter);

	///Распознавание образов
	while (true) {
		printf("Введите образ для распознавания: ");
		gets_s(input_buffer);
		printf("Распознанный образ --> число %d\n", recognition(input_buffer));
	}
	fclose(fo);

	return 0;
}
