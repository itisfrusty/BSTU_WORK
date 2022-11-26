#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef _HUFFMAN_H_

#define _HUFFMAN_H_

#include "calg.h"

// Класс для алгоритма хаффмана

class huffman : public calg

{

protected:

	void calculateCodes(freqtable::ByteRepeats* root, std::string codeline); // Рекурсивная функция создания кода Хаффмана

	double averageLength(); // Средняя длина

	std::priority_queue<freqtable::ByteRepeats*, std::vector<freqtable::ByteRepeats*>, freqtable::ByteRepeatsCompare> minByte; // Дерево

public:

	huffman() { }

	huffman(std::string _fileName) : calg(_fileName) { }

	void calculate(); // Создание дерева и подсчет кодов

	void write(); // Запись в файл

	void readFreqTable(); // Чтение готовой таблицы частот и подсчет кодов

	std::string decode(std::string codeline); // Декодирование

	int length(); // Длина обащего кода

	~huffman() { }

};

// Функция создания кодов

void huffman::calculateCodes(freqtable::ByteRepeats* root, std::string codeline)

{

	if (!root)

	{

		return;

	}

	if (root->byte != 256)

	{

		codes.push_back(ByteAndCode(*root, codeline)); // Если листок, то добавляем

	}

	calculateCodes(root->left, codeline + "0"); // Идем по левой ветви

	calculateCodes(root->right, codeline + "1"); // Идем по правой ветви

}

int huffman::length()

{

	int _length = 0;

	for (int i = 0; i < codes.size(); i++)

	{

		_length += codes[i].byte.repeats * codes[i].code.length(); // Вычисляем длину

	}

	return _length;

}

double huffman::averageLength()

{

	double _length = length();

	int allRepeats = ftable.AllRepeats;

	return _length / allRepeats; // Вычисляем среднюю длину

}

void huffman::calculate()

{

	freqtable::ByteRepeats* left, * right, * top;

	for (int i = 0; i < ftable.repeatsTable.size(); ++i)

		minByte.push(new freqtable::ByteRepeats(ftable.repeatsTable[i].byte, ftable.repeatsTable[i].repeats)); // Создание дерева

		// Iterate while size of heap doesn't become 1

	while (minByte.size() != 1)

	{

		left = minByte.top();

		minByte.pop(); // Убираем левый

		right = minByte.top();

		minByte.pop(); // Убираем правый

		top = new freqtable::ByteRepeats(256, left->repeats + right->repeats); // Создаем листок с общим весом

		top->left = left;

		top->right = right;

		minByte.push(top); // Добавляем листок

	}

	codes.erase(codes.begin(), codes.end()); // Очищаем, если использовался

	calculateCodes(minByte.top(), ""); // Вызываем функцию создания кодов

}

// Декодируем

std::string huffman::decode(std::string codeline)

{

	std::string ans = "";

	freqtable::ByteRepeats* curr = minByte.top(); // Сохраняем корень

	for (int i = 0; i < codeline.size(); i++)

	{

		if (codeline[i] == '0')

			curr = curr->left; // Идем по левой ветке

		else

			curr = curr->right; // Идем по правой ветке

			// reached leaf node

		if (curr->left == nullptr and curr->right == nullptr)

		{

			ans += (char)curr->byte;

			curr = minByte.top();

		}

	}

	return ans;

}

// Запись на диск

void huffman::write()

{

	std::cout << "\nTry to calculate Huffman of " + fileName << std::endl;

	ftable.write();

	FileSize = ftable.FileSize;

	calculate();

	std::ofstream outputFile(fileName + ".huf"); // Создаем выходной файл

	outputFile << ftable.Entropy << '\n' << averageLength() << std::endl;

	for (int i = 0; i < codes.size(); i++)

	{

		if (codes[i].byte.byte == 256)

			break;

		outputFile << "\n" << codes[i].byte.byte << "\t" << codes[i].code;

	}

	outputFile.close(); // Закрываем файл

}

// Считывание с файла

void huffman::readFreqTable()

{

	std::cout << "Try to read Huffman of " + fileName << std::endl;

	ftable.read();

	calculate();

	std::ofstream outputFile(fileName + ".huf"); // Создаем выходной файл

	outputFile << ftable.Entropy << '\n' << averageLength() << std::endl;

	for (int i = 0; i < codes.size(); i++)

	{

		if (codes[i].byte.byte == 256)

			break;

		outputFile << "\n" << codes[i].byte.byte << "\t" << codes[i].code;

	}

	outputFile.close(); // Закрываем файл

}

#endif
