#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

// Таблица частот
class ftable
{
protected:
    std::string fileName; // Имя файла
    double entropy(); // Энтропия(функция получения)
    void length(); // Все повторения (функция подсчета)
    void sortAndDeleteZeros(); // Сортировка
public:
    ftable() : fileName("") { }
    ftable(std::string _fileName) : fileName(_fileName) { }
    void newFile(std::string _fileName); // Загрузка нового файла
    struct ByteStruct; // Байты и их повторения
    struct ByteCompare; // Сравнение
    std::vector<ByteStruct> table; // Таблица повторений
    void buildTable(); // Подсчет
    void writeToFile(std::string FileName); // Запись в файл
    double Entropy = 0.0; // Энтропия
    int Repeats = 0; // Повторения
    int Symbols = 0; // Символов в файле

    ~ftable() { }
};

struct ftable::ByteStruct
{
    int byte; // Байт
    int repeats; // Повторения
    ByteStruct* lNode, * rNode; // Левый и правый лист
    ByteStruct() : byte(0), repeats(0), lNode(nullptr), rNode(nullptr) { } // Конструктор
    ByteStruct(int Byte, int Repeats) : byte(Byte), repeats(Repeats), lNode(nullptr), rNode(nullptr) { }
};

struct ftable::ByteCompare {
    bool operator()(ByteStruct l, ByteStruct r) {
        return (l.repeats > r.repeats); // Сравение
    }
    bool operator()(ByteStruct* l, ByteStruct* r) {
        return (l->repeats > r->repeats);
    }
};

void ftable::newFile(std::string _fileName) {
    fileName = _fileName;
}

// Подсчет таблицы частот
void ftable::buildTable()
{
    int symbolCount = 0;

    if (fileName == "") {
        return;
    }
    table.erase(table.begin(), table.end()); // Очищаем таблицу
    std::ifstream file; // Открываем файл в бинарном режиме
    file.open(fileName, std::ifstream::binary);
    if (file.is_open())
    {
        file.seekg(0, file.end);
        symbolCount = file.tellg(); // Считаем количество символов в файле
        Symbols = symbolCount;
        file.seekg(0, file.beg);
    }
    unsigned char* data; // Содержимое файла
    data = new unsigned char[symbolCount]; // Выделяем память
    file.read((char*)data, symbolCount); // Заполняем массив
    file.close();
    for (int i = 0; i < 256; i++) {
        table.push_back(ByteStruct(i, 0)); // Даем значения байтам
    }
    for (int i = 0; i < symbolCount; ++i) {
        table[data[i]].repeats += 1; // Считаем повторения байтов, номер байта сразу является индеком массива
    }
    sortAndDeleteZeros();
    entropy();
    length();
    delete[] data; // Освобождаем память
}

// Запись в файл
void ftable::writeToFile(std::string FileName)
{
    std::cout << "Write Table of Freqs of " + fileName << std::endl;
    newFile(FileName);
    buildTable();
    std::ofstream outputFile("Algoritm/Tables/" + fileName + ".tab"); // Создаем выходной файл
    outputFile << Entropy << std::endl;
    for (int i = 0; i < table.size(); i++) {
        outputFile << "\n" << table[i].byte << "\t" << table[i].repeats;	// Выводим таблицу частот
    }
    outputFile.close(); // Закрываем файл
}

void ftable::sortAndDeleteZeros() {
    std::sort(table.begin(), table.end(), ByteCompare()); // Сортируем
    // Удаляем нулевые повторения
    for (std::vector<ByteStruct>::const_iterator byteIterator = table.begin(); byteIterator != table.end(); ) {
        if ((*byteIterator).repeats == 0) {
            byteIterator = table.erase(byteIterator);
        }
        else {
            ++byteIterator;
        }
    }
}

void ftable::length() {
    int repeats = 0;
    for (std::vector<ByteStruct>::const_iterator byteIterator = table.begin(); byteIterator != table.end(); byteIterator++)
    {
        repeats += byteIterator->repeats; // Все повторения
    }
    Repeats = repeats;
}

double ftable::entropy()
{
    double freqOfByte[256], entropy = 0;
    std::fill(freqOfByte, freqOfByte + 256, 0);
    for (int i = 0; i < table.size(); ++i) {
        freqOfByte[i] = (double)table[i].repeats / Symbols; // Считаем частоту
        entropy += (log10(1.0 / freqOfByte[i]) / log10(2.0)) * freqOfByte[i]; // Считаем энтропию по формуле Шеннона
    }
    Entropy = entropy;
    return entropy;
}
