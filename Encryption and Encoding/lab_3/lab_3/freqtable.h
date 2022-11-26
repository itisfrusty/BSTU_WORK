#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef _FREQTABLE_H_

#define _FREQTABLE_H_

#include <iostream>

#include <fstream>

#include <math.h>

#include <string>

#include <sstream>

#include <algorithm>

#include <queue>

#include <vector>

// Таблица частот

class freqtable

{

protected:

	std::string fileName = ""; // Имя файла

	int fileSize(); // Размер файла

	double entropy(); // Энтропия

	void allRepeats(); // Все повторения

public:

	freqtable() { }

	freqtable(std::string _fileName) : fileName(_fileName) { }

	struct ByteRepeats; // Байт и его повторения

	struct ByteRepeatsCompare; // Компаматор

	std::vector<ByteRepeats> repeatsTable; // Сама таблица частот

	void update(std::string _fileName); // Смена рабочего файла

	void calculate(); // Подсчет

	void write(); // Запись в файл

	void read(); // Считываение с файла

	double Entropy;

	int AllRepeats;

	int FileSize;

	~freqtable() { }

};

struct freqtable::ByteRepeats

{

	int byte; // Байт

	int repeats; // Повторения

	ByteRepeats* left, * right;

	ByteRepeats() : byte(0), repeats(0), left(nullptr), right(nullptr) { }

	ByteRepeats(int _b, int _r) : byte(_b), repeats(_r), left(nullptr), right(nullptr) { }

};

// Компаматор

struct freqtable::ByteRepeatsCompare

{

	bool operator()(ByteRepeats l, ByteRepeats r)

	{

		return (l.repeats > r.repeats);

	}

	bool operator()(ByteRepeats* l, ByteRepeats* r)

	{

		return (l->repeats > r->repeats);

	}

};

void freqtable::update(std::string _fileName)

{

	fileName = _fileName;

}

int freqtable::fileSize()

{

	int size = 0;

	std::ifstream file(fileName, std::ifstream::binary); // Открываем файл в бинарном режиме

	file.seekg(0, file.end);

	size = file.tellg(); // Считаем количество символов в файле

	file.seekg(0, file.beg);

	file.close();

	FileSize = size;

	return size;

}

void freqtable::calculate()

{

	if (fileName == "")

	{

		return;

	}

	repeatsTable.erase(repeatsTable.begin(), repeatsTable.end()); // Очищаем, если ранее использовалась

	std::ifstream file(fileName, std::ifstream::binary); // Открываем файл в бинарном режиме

	int symbolCount = fileSize(); // Количество символов

	unsigned char* data; // Содержимое файла

	data = new unsigned char[symbolCount]; // Аллоцируем память

	file.read((char*)data, symbolCount); // Заполняем массив

	file.close();

	for (int i = 0; i < 256; i++)

	{

		repeatsTable.push_back(ByteRepeats(i, 0)); // Даем значения байтам

	}

	for (int i = 0; i < symbolCount; ++i)

	{

		++repeatsTable[data[i]].repeats; // Считаем повторения байтов

	}

	std::sort(repeatsTable.begin(), repeatsTable.end(), ByteRepeatsCompare()); // Сортируем

	// Удаляем байты с нулевыми повторениями

	for (std::vector<ByteRepeats>::iterator i = repeatsTable.begin(); i != repeatsTable.end();)

	{

		if (i->repeats == 0)

		{

			i = repeatsTable.erase(i);

		}

		else

		{

			i++;

		}

	}

	entropy(); // Считаем энтропию

	allRepeats();

	delete[] data; // Освобождаем память

}

// Все повторения

void freqtable::allRepeats()

{

	int allRep = 0;

	for (int i = 0; i < repeatsTable.size(); i++)

	{

		allRep += repeatsTable[i].repeats;

	}

	AllRepeats = allRep;

}

// Энтропия

double freqtable::entropy()

{

	double freq[256], entropy = 0;

	std::fill(freq, freq + 256, 0);

	for (int i = 0; i < repeatsTable.size(); ++i)

	{

		if (repeatsTable[i].repeats == 0)

		{

			continue;

		}

		freq[i] = (double)repeatsTable[i].repeats / fileSize(); // Считаем частоту

		entropy += (log10(1.0 / freq[i]) / log10(2.0)) * freq[i]; // Считаем энтропию по формуле Шеннона

	}

	Entropy = entropy;

	return entropy;

}

// Запись в файл

void freqtable::write()

{

	std::cout << "Try to calculate FreqTable of " + fileName << std::endl;

	calculate();

	std::ofstream outputFile(fileName + ".tab"); // Создаем выходной файл

	outputFile << Entropy << std::endl;

	for (int i = 0; i < repeatsTable.size(); i++)

	{

		outputFile << "\n" << repeatsTable[i].byte << "\t\t" << repeatsTable[i].repeats; // Выводим частотную таблица

	}

	outputFile << std::endl;

	outputFile.close(); // Закрываем файл

}

// Считываение с файла

void freqtable::read()

{

	std::string line;

	repeatsTable.erase(repeatsTable.begin(), repeatsTable.end()); // Очищаем

	std::ifstream file(fileName + ".tab"); // Открываем файл в бинарном режиме

	if (file.is_open())

	{

		int lineCount = 0;

		while (getline(file, line))

		{

			if (lineCount == 0)

			{

				std::stringstream ss(line);

				ss >> Entropy;

				lineCount++;

			}

			int found = line.find('\t'); // Ищем табуляцию

			if (found != -1)

			{

				std::string _byte, _repeats;

				_byte = line.substr(0, found); // Байт

				_repeats = line.substr(found + 1, line.length() - 1); // Повторения

				repeatsTable.push_back(ByteRepeats(std::stoi(_byte), std::stoi(_repeats)));

			}

		}

	}

	allRepeats();

	file.close();

}

#endif
