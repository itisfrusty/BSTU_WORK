#pragma once
#include "ftable.h"

// Алгоритм Шеннона-Фано
class sfano
{
protected:
    std::string fileName;
    ftable FTable;
    struct SfanoCode;
    void saveCode(std::vector<SfanoCode>& sfCodes, int left, int right);
    double length();
public:
    sfano() { }
    sfano(std::string FileName);
    std::vector<SfanoCode> sfCode;
    void buildSfanoTable();
    void newFile(std::string FileName);
    void writeToFile(std::string FileName);

    ~sfano() { }
};

sfano::sfano(std::string FileName) {
    fileName = FileName;
    FTable = ftable(fileName);
    FTable.buildTable();
}

struct sfano::SfanoCode
{
    ftable::ByteStruct byte; // Байт
    std::string code; // Код
    SfanoCode(ftable::ByteStruct Byte, std::string Code) : byte(Byte), code(Code) { }
    SfanoCode() : byte(ftable::ByteStruct(0, 0)), code("") { }
};

void sfano::newFile(std::string FileName)
{
    fileName = FileName;
    FTable = ftable(fileName);
    FTable.buildTable();
}

// Подсчёт кодов
void sfano::saveCode(std::vector<SfanoCode>& sfCodes, int left, int right)
{
    if (left == right)
        return;
    int leftPosition = left; // Начало списка
    int rightPosition = right; // Конец списка
    int leftSum = 0;
    int rightSum = 0;

    // Ищем середину
    while (leftPosition < rightPosition) {
        if (leftSum <= rightSum) {
            leftSum += sfCode[leftPosition].byte.repeats;
            leftPosition++;
        }
        else {
            rightSum += sfCode[rightPosition].byte.repeats;
            rightPosition--;
        }
    }

    // Подсчитываем коды
    for (int leftPointer = left; leftPointer < leftPosition; leftPointer++) {
        sfCode[leftPointer].code += "1";
    }
    for (int rightPointer = leftPosition; rightPointer <= right; rightPointer++) {
        sfCode[rightPointer].code += "0";
    }
    // Идем влево
    saveCode(sfCode, left, leftPosition - 1);
    // Идем вправо
    saveCode(sfCode, leftPosition, right);
}

// Средняя длина
double sfano::length()
{
    double length = 0;
    int allRepeats = FTable.Repeats;
    for (int i = 0; i < sfCode.size(); i++)
    {
        length += sfCode[i].byte.repeats * sfCode[i].code.length(); // Ищем общую длину
    }
    return length / allRepeats;
}

// Создание таблицы
void sfano::buildSfanoTable()
{
    sfCode.erase(sfCode.begin(), sfCode.end());
    for (int i = 0; i < FTable.table.size(); ++i)
    {
        sfCode.push_back(SfanoCode(ftable::ByteStruct(FTable.table[i].byte, FTable.table[i].repeats), "")); // Добавляем байты в таблицу
    }
    saveCode(sfCode, 0, FTable.table.size() - 1);
}

// Запись в файл
void sfano::writeToFile(std::string FileName)
{
    std::cout << "Write SF of " + fileName << std::endl;
    newFile(FileName);
    buildSfanoTable();
    std::ofstream outputFile("Algoritm/SF/" + fileName + ".s-f"); // Создаем выходной файл
    outputFile << FTable.Entropy << '\n' << length() << std::endl;
    for (int i = sfCode.size() - 1; i >= 0; i--)
    {
        outputFile << "\n" << sfCode[i].byte.byte << "\t" << sfCode[i].code;
    }
    outputFile.close(); // Закрываем файл
}
