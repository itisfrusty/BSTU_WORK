#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;
const int ALP = 33;//кол-во букв в алфавите
unsigned char TABLE[ALP + ALP] = { 0 }; //массив для алфавитов

void suport()//функция заполнения массива алфовитов

{

	int p = 0;//для учёта букв ё и Ё в таблице ASCII
	for (int i = 0; i < ALP + ALP; i++)//цикл по проходу всего массива

	{

		if (i == 6) //если 6 позиция в массиве алфавита

		{

			TABLE[i] = 'Ё';//запись в алф. быквы Ё
			p++;
			continue;//переход к след. итерации
		}

		if (i == 6 + ALP)//если 6 позиция в массиве алфавита

		{

			TABLE[i] = 'ё';//запись в алф. быквы ё
			p++;
			continue;//переход к след. итерации

		}
		TABLE[i] = unsigned char(192 + i - p); //запись в массив буквы по таблице
	}
}

int position(unsigned char ch)//возвращает номер буквы в алфавите

{
	for (int i = 0; i < ALP + ALP; i++)
		if (TABLE[i] == ch) return i + 1;
	return 0;

}

unsigned char decod(int a, int b)//находит разность номеров двух букв

{

	int ind = 0;
	if (a > b) ind = a - b; //если не требуется переход в конец алфавита
	else ind = ALP + ALP - (b - a); //если требуется переход в конец алфавита
	return TABLE[ind - 1]; //возвращает декодированную букву по инд из алфавита
}

void read(string file, string key)//основная функция

{
	ifstream fin(file); //открывает файл
	if (!fin.is_open()) //проверка открытия

	{
		cout << file << " - error_open" << endl; //вывод, если не открыт
	}

	else

	{

		suport(); //ф. заполнения массива алфавита
		string buf; //строка, в которую считываем из файла
		int p = 0; //номер буквы в массиве ключа
		ofstream fout(file + ".dec"); //создаём расшифрованный файл
		while (getline(fin, buf)) //цикл считывания построчно

		{
			if (buf.empty()) //если строка пустая, то
				fout << endl;//сразу выводим пустую строку в результирующий файл

			else
			{
				for (int i = 0; buf[i] != '\0'; i++)//цикл на работу с каждым символом в строке
				{
					if (int a = position(buf[i])) //присваиваем номер буквы строки в алфавите

					{

						int b = position(key[p]);//присваиваем номер буквы ключа в алфавите
						buf[i] = decod(a, b);//ф. нахождения разности и возвр. буквы

					}
					p++; //переход к следующей букве ключа
					if (p == key.length()) p = 0;//если дошли до границы ключа, то возврат к первой букве

				}
				fout << buf << endl;//вывод изменённой строки в результирующий файл
			}
		}
		fout.close();//закрытие результирующего файла
		cout << endl << "Mission complete!" << endl;//вывод сообщения в консоль
	}
	fin.close();//закрытие исходного файла
}

int main()

{
	SetConsoleCP(1251);//для русской кодировки вводимого ключа
	string key, file; //строки для ключа и названия исходного файла
	cout << "Enter the key:" << endl; //вывод сообщения на консоль
	cin >> key; //ввод ключа
	cout << endl << "Enter file name:" << endl;//вывод сообщения на консоль
	cin >> file; //ввод имени исходного файла
	read(file, key); //основная функция
	return 0;
}