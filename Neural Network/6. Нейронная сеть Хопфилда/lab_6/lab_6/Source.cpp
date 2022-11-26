#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int line_column = 25, et = 3, inc = 0, n = 0;
int w[25][25], y[25], y_1[25];
int initials[3][25] = {
	{
	1,0,0,0,1,
	1,0,0,0,1,
	0,1,1,1,1, // ×
	0,0,0,0,1,
	0,0,0,0,1
	},
	{
	1,1,1,1,0,
	1,0,0,0,1,
	1,1,1,1,0, // Ð
	1,0,0,0,0,
	1,0,0,0,0
	},
	{
	1,0,0,1,1,
	1,0,1,0,0,
	1,1,0,0,0, //Ê
	1,0,1,0,0,
	1,0,0,1,1
	}

};
int pomexi[3][25] = {
	{
	1,0,1,0,1,
	1,0,0,0,1,
	0,1,0,1,1, // 7
	0,0,1,1,1,
	1,0,1,1,1
	},
	{
	1,1,0,1,0,
	0,0,0,0,1,
	1,1,0,1,0, // 6
	0,0,1,0,0,
	1,0,0,1,0
	},
	{
	1,1,0,1,1,
	0,0,1,0,1,
	1,1,0,1,0, //10
	0,0,1,0,1,
	0,1,0,1,1
	}
};



int main()
{
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < line_column; i++)
		for (int j = 0; j < line_column; j++) {
			w[i][j] = 0;
		}


	for (int i = 0; i < line_column; i++)
		y_1[i] = 0;

	for (int i = 0; i < line_column; i++) {
		for (int j = 0; j < line_column; j++)
			for (int k = 0; k < et; k++) {
				w[i][j] += (2 * initials[k][i] - 1) * (2 * initials[k][j] - 1);
			}
	}
	for (int i = 0; i < line_column; i++)
		w[i][i] = 0;

	while (n != 3) {

		for (int i = 0; i < line_column; i++)
			y_1[i] = pomexi[n][i];

		while (inc != 25) {
			inc = 0;
			for (int j = 0; j < 25; j++) {
				y[j] = y_1[j];
				y_1[j] = 0;
			}
			for (int i = 0; i < line_column; i++) {
				for (int j = 0; j < line_column; j++) {
					y_1[i] += y[j] * w[j][i];
				}
				if (y_1[i] > 0)
					y_1[i] = 1;
				else
					y_1[i] = 0;
			}
			for (int i = 0; i < line_column; i++) {
				if (y[i] == y_1[i])
					inc++;
			}
		}

		for (int i = 0; i < line_column; i++) {
			if (i % 5 == 0)
				cout << endl;
			cout << y_1[i];
		}
		n++;
		inc = 0;
		cout << endl;
	}
	system("pause");
	return 0;
}
